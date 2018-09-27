/****************************************************************************
 *  Copyright: National ICT Australia,  2007 - 2011                         *
 *  Developed at the ATP lab, Networked Systems research theme              *
 *  Author(s): Dimosthenis Pediaditakis, Yuriy Tselishchev                  *
 *  This file is distributed under the terms in the attached LICENSE file.  *
 *  If you do not find this file, copies can be found by writing to:        *
 *                                                                          *
 *      NICTA, Locked Bag 9013, Alexandria, NSW 1435, Australia             *
 *      Attention:  License Inquiry.                                        *
 *                                                                          *
 ****************************************************************************/

#include "CowReporting.h"

Define_Module(CowReporting);

void CowReporting::startup() {
    maxSampleInterval = ((double) par("maxSampleInterval")) / 1000.0;
    minSampleInterval = ((double) par("minSampleInterval")) / 1000.0;
    isSink = par("isSink");
    currSentSampleSN = 0;
    randomBackoffIntervalFraction = genk_dblrand(0);

    if(isSink){
        setTimer(SEND_NOTIFICATION, 1);
    }else{
        resetCurrentSample();
        setTimer(REQUEST_SAMPLE, maxSampleInterval * randomBackoffIntervalFraction);
    }

}

void CowReporting::timerFiredCallback(int index) {

    switch (index) {
        case REQUEST_SAMPLE: {
            requestSensorReading(0);
            requestSensorReading(1);
            requestSensorReading(2);
            requestSensorReading(3);
            requestSensorReading(4);

            setTimer(REQUEST_SAMPLE, maxSampleInterval);
            break;
        }case SEND_NOTIFICATION:{
            CowReportingDataPacket *packet2Net = new CowReportingDataPacket("Sink notification packet", APPLICATION_NOTIFICATION_PACKET);
            toNetworkLayer(packet2Net, BROADCAST_NETWORK_ADDRESS);
            setTimer(SEND_NOTIFICATION, 1);

            break;
        }
    }

}

void CowReporting::fromNetworkLayer(ApplicationPacket * genericPacket, const char *source, double rssi, double lqi) {
    CowReportingDataPacket *rcvPacket = check_and_cast<CowReportingDataPacket*>(genericPacket);
    int message_kind = rcvPacket->getKind();

    switch(message_kind){
        case APPLICATION_PACKET:{
            CowReportData theData = rcvPacket->getExtraData();
               if (isSink) {
                   trace() << "Sink received from: " << theData.nodeID <<" \t Time: " << theData.sim_time << " \t GPSX: "
                           << theData.gps_x << "\t GPSY: " << theData.gps_y << "\t AcelX: " << theData.acel_x << "\t AcelY: "
                           << theData.acel_y << "\t AcelZ: " << theData.acel_z;
               }
         break;
        }
        case APPLICATION_NOTIFICATION_PACKET:{
            trace() << "Sink notification packet received. Buffer size: " << samplesBuffer.size();

            int packetSent = 0;
            while(!samplesBuffer.empty() && packetSent < 32){
                CowReportingDataPacket *packet2Net = new CowReportingDataPacket("Data packet", APPLICATION_PACKET);
                packet2Net->setExtraData(samplesBuffer.back());
                packet2Net->setSequenceNumber(currSentSampleSN);

                toNetworkLayer(packet2Net, "0");
                samplesBuffer.pop_back();
                currSentSampleSN++;
                packetSent++;
            }
        break;
        }
    }
}

void CowReporting::handleSensorReading(SensorReadingMessage * rcvReading) {
    int sensIndex = rcvReading->getSensorIndex();
    string sensType(rcvReading->getSensorType());
    double sensValue = rcvReading->getSensedValue();

    trace() << "Index: " << sensIndex << "\t Type:" << sensType << "\t Sensed:" << sensValue;
    switch (sensIndex) {
        case 0: {
            currentSample.gps_x = sensValue;
            break;
        }
        case 1: {
            currentSample.gps_y = sensValue;
            break;
        }
        case 2: {
            currentSample.acel_x = sensValue;
            break;
        }
        case 3: {
            currentSample.acel_y = sensValue;
            break;
        }
        case 4: {
            currentSample.acel_z = sensValue;
            break;
        }
    }

    if(currentSampleIsComplete()){
        if(samplesBuffer.size() < 1000){

            currentSample.nodeID = SELF_NETWORK_ADDRESS;
            currentSample.sim_time = simTime().str().c_str();
            samplesBuffer.push_back(currentSample);

            resetCurrentSample();
            trace() << "Buffer size: " << samplesBuffer.size();
        }
    }

 }

bool CowReporting::currentSampleIsComplete(){
    if(currentSample.gps_x != -100 &&
      currentSample.gps_y != -100 &&
      currentSample.acel_x != -100 &&
      currentSample.acel_y != -100 &&
      currentSample.acel_z != -100)
      return true;

    return false;
}

void CowReporting::resetCurrentSample(){
    currentSample.gps_x = -100;
    currentSample.gps_y = -100;
    currentSample.acel_x = -100;
    currentSample.acel_y = -100;
    currentSample.acel_z = -100;
}
