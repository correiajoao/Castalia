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

#ifndef _COWREPORTING_H_
#define _COWREPORTING_H_

#include "vector"
#include "VirtualApplication.h"
#include "CowReportingPacket_m.h"

using namespace std;

enum CowReportingTimers {
	REQUEST_SAMPLE = 1,
	SEND_NOTIFICATION = 2
};

class CowReporting: public VirtualApplication {
 private:
    CowReportData currentSample;
    vector<CowReportData> samplesBuffer;

	double maxSampleInterval;
	double minSampleInterval;

	int currSentSampleSN;

	double randomBackoffIntervalFraction;
	bool isSink;

 protected:
	bool currentSampleIsComplete();
	void resetCurrentSample();

	void startup();
	void fromNetworkLayer(ApplicationPacket *, const char *, double, double);
	void handleSensorReading(SensorReadingMessage *);
	void timerFiredCallback(int);
};

#endif
