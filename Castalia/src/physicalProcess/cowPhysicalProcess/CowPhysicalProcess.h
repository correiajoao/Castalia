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

#ifndef _CARSPHYSICALPROCESS_H_
#define _CARSPHYSICALPROCESS_H_

#define SIMTIME_STEP 0.01

#include "CastaliaModule.h"
#include "PhysicalProcessMessage_m.h"

using namespace std;

typedef struct {
	simtime_t time;
	double x;
	double y;
} sourceSnapshot;

class CowPhysicalProcess: public CastaliaModule {
 private:
    double gps_x;
    double gps_y;

    double aceleration_x;
    double aceleration_y;
    double aceleration_z;

	bool printDebugInfo;
	const char *description;

 protected:
	virtual void handleMessage(cMessage * msg);

 public:
     double getAcelerationX() const;
     void setAcelerationX(double acelerationX);
     double getAcelerationY() const;
     void setAcelerationY(double acelerationY);
     double getAcelerationZ() const;
     void setAcelerationZ(double acelerationZ);
     const char* getDescription() const;
     void setDescription(const char* description);
     double getGpsX() const;
     void setGpsX(double gpsX);
     double getGpsY() const;
     void setGpsY(double gpsY);
     bool isPrintDebugInfo() const;
     void setPrintDebugInfo(bool printDebugInfo);
     double getRandomAceleration();

};

#endif
