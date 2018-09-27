/****************************************************************************
 *  Copyright: National ICT Australia,  2007 - 2010                         *
 *  Developed at the ATP lab, Networked Systems research theme              *
 *  Author(s): Yuri Tselishchev                                             *
 *  This file is distributed under the terms in the attached LICENSE file.  *
 *  If you do not find this file, copies can be found by writing to:        *
 *                                                                          *
 *      NICTA, Locked Bag 9013, Alexandria, NSW 1435, Australia             *
 *      Attention:  License Inquiry.                                        *
 *                                                                          *  
 ****************************************************************************/

#include "CowPhysicalProcess.h"

Define_Module(CowPhysicalProcess);

double CowPhysicalProcess::getAcelerationX() const {
    return aceleration_x;
}

void CowPhysicalProcess::setAcelerationX(double acelerationX) {
    aceleration_x = acelerationX;
}

double CowPhysicalProcess::getAcelerationY() const {
    return aceleration_y;
}

void CowPhysicalProcess::setAcelerationY(double acelerationY) {
    aceleration_y = acelerationY;
}

double CowPhysicalProcess::getAcelerationZ() const {
    return aceleration_z;
}

void CowPhysicalProcess::setAcelerationZ(double acelerationZ) {
    aceleration_z = acelerationZ;
}

const char* CowPhysicalProcess::getDescription() const {
    return description;
}

void CowPhysicalProcess::setDescription(const char* description) {
    this->description = description;
}

double CowPhysicalProcess::getGpsX() const {
    return gps_x;
}

void CowPhysicalProcess::setGpsX(double gpsX) {
    gps_x = gpsX;
}

double CowPhysicalProcess::getGpsY() const {
    return gps_y;
}

void CowPhysicalProcess::setGpsY(double gpsY) {
    gps_y = gpsY;
}

bool CowPhysicalProcess::isPrintDebugInfo() const {
    return printDebugInfo;
}

void CowPhysicalProcess::setPrintDebugInfo(bool printDebugInfo) {
    this->printDebugInfo = printDebugInfo;
}

double CowPhysicalProcess::getRandomAceleration() {
    return ((double(rand()) / double(RAND_MAX)) * (9.8 + 9.8)) - 9.8;
}

void CowPhysicalProcess::handleMessage(cMessage * msg)
{
	switch (msg->getKind()) {
		case PHYSICAL_PROCESS_SAMPLING: {
			PhysicalProcessMessage *phyMsg = check_and_cast < PhysicalProcessMessage * >(msg);
			int sensorIndex = phyMsg->getSensorIndex();

			//Identifies the sensor kind by your ID
			switch (sensorIndex){
			    case 0:{
			        setGpsX(phyMsg->getXCoor());
			        phyMsg->setValue(getGpsX());
			        break;
			    }case 1:{
			        setGpsY(phyMsg->getYCoor());
                    phyMsg->setValue(getGpsY());
			        break;
			    }case 2:{
                    setAcelerationX(getRandomAceleration());
                    phyMsg->setValue(getAcelerationX());
                    break;
                }case 3:{
                    setAcelerationY(getRandomAceleration());
                    phyMsg->setValue(getAcelerationY());
                    break;
                }case 4:{
                    setAcelerationZ(getRandomAceleration());
                    phyMsg->setValue(getAcelerationZ());
                    break;
                }
			}
			// Send reply back to the node who made the request
			send(phyMsg, "toNode", phyMsg->getSrcID());
			return;
		}

		default: {
			opp_error(":\n Physical Process received message other than PHYSICAL_PROCESS_SAMPLING");
		}
	}
}

