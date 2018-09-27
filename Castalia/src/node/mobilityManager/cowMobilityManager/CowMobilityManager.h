/****************************************************************************
 *  Copyright: National ICT Australia,  2007 - 2010                         *
 *  Developed at the ATP lab, Networked Systems research theme              *
 *  Author(s): Yuriy Tselishchev                                            *
 *  This file is distributed under the terms in the attached LICENSE file.  *
 *  If you do not find this file, copies can be found by writing to:        *
 *                                                                          *
 *      NICTA, Locked Bag 9013, Alexandria, NSW 1435, Australia             *
 *      Attention:  License Inquiry.                                        *
 *                                                                          *  
 ****************************************************************************/

#ifndef _MOBILITYMODULE_H_
#define _MOBILITYMODULE_H_

#include "MobilityManagerMessage_m.h"
#include "VirtualMobilityManager.h"

using namespace std;

class CowMobilityManager: public VirtualMobilityManager {
 private:
	/*--- The .ned file's parameters ---*/
	double updatePositionInterval;
	double updateTetaInterval;
	double loc1_x;
	double loc1_y;
	double loc1_z;
	double lim_x;
	double lim_y;
	double lim_z;
	int lim_speed;

    double speed;
    double teta;
 protected:
	void initialize();
	void handleMessage(cMessage * msg);
	double updateSpeed();
	double updateTeta();
};

#endif
