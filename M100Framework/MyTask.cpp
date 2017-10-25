/************************************************************

GNU GENERAL PUBLIC LICENSE, Version 3, 29 June 2007
Copyright (c) 2017, KondeU, All rights reserved.

Project:     M100Framework
File:        MyTask.cpp
Description: Could only run on linux. Device is Manifold.
Date:        2017-10-15
Version:     2.1
Authors:     Deyou Kong <370242479@qq.com>
History:     01, 17-10-15, Deyou Kong, Framework task demo.

************************************************************/

#include <unistd.h>

#include "Flight.h"
#include "FlightIndoor.h"

#include <iostream>
using namespace std;

int MyTask(ConboardSDKScript & sdkScript)
{
	CFlight cFlight;
	cFlight.CtrlObtain();
	cFlight.Takeoff();
	sleep(3);
	cFlight.Land();
	cFlight.CtrlRelease();

	return 0;
}
