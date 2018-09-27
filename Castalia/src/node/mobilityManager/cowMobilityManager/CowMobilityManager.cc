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

#include "CowMobilityManager.h"

Define_Module(CowMobilityManager);

void CowMobilityManager::initialize()
{
	VirtualMobilityManager::initialize();

	//Update interval: 1s
	updatePositionInterval = par("updatePositionInterval");
	updateTetaInterval = par("updateTetaInterval");

	loc1_x = nodeLocation.x;
	loc1_y = nodeLocation.y;
	loc1_z = nodeLocation.z;

	lim_x = par("xCoorLimit");
    lim_y = par("yCoorLimit");
    lim_z = par("zCoorLimit");

    lim_speed = par("limSpeed");

    teta = updateTeta();

	setLocation(loc1_x, loc1_y, loc1_z);
	scheduleAt(simTime() + updatePositionInterval,
			new MobilityManagerMessage("Periodic location update message", MOBILITY_PERIODIC));
	scheduleAt(simTime() + updateTetaInterval,
	            new MobilityManagerMessage("Periodic direction update message", UPDATE_DIRECTION));
}
double CowMobilityManager::updateSpeed(){
    //Speed between 0m/s - 1.5m/s
    return (rand() % lim_speed) / 100;
}

double CowMobilityManager::updateTeta(){
    //Angle between 0 - 360 degrees
    return rand() % 360;
}

void CowMobilityManager::handleMessage(cMessage * msg)
{
	int msgKind = msg->getKind();
	switch (msgKind) {

		case MOBILITY_PERIODIC:{
		    speed = updateSpeed();

			if (rand() % 1 == 0) {
				nodeLocation.x += updatePositionInterval * speed * cos(teta);
			} else {
				nodeLocation.x -= updatePositionInterval * speed * cos(teta);
			}

			if (rand() % 1 == 0) {
			    nodeLocation.y += updatePositionInterval * speed * sin(teta);
			} else {
			    nodeLocation.y -= updatePositionInterval * speed * sin(teta);
			}

			//Check for not allowed values
			nodeLocation.x = (nodeLocation.x < 0) ? 0 : nodeLocation.x;
			nodeLocation.x = (nodeLocation.x > lim_x) ? lim_x : nodeLocation.x;

			nodeLocation.y = (nodeLocation.y < 0) ? 0 : nodeLocation.y;
			nodeLocation.y = (nodeLocation.y > lim_y) ? lim_y : nodeLocation.y;

			notifyWirelessChannel();
			scheduleAt(simTime() + updatePositionInterval,
				new MobilityManagerMessage("Periodic location update message", MOBILITY_PERIODIC));

			trace() << "Changed cow location(x:y:z) to " << nodeLocation.x <<
					":" << nodeLocation.y << ":" << nodeLocation.z;
			break;
		} case UPDATE_DIRECTION:{
		    teta = updateTeta();
		    scheduleAt(simTime() + updateTetaInterval, new MobilityManagerMessage("Periodic direction update message", UPDATE_DIRECTION));
		    break;
		}

		default:{
			trace() << "WARNING: Unexpected message " << msgKind;
		}
	}

	delete msg;
	msg = NULL;
}

