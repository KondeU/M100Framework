/************************************************************

GNU GENERAL PUBLIC LICENSE, Version 3, 29 June 2007
Copyright (c) 2017, KondeU, All rights reserved.

Project:     M100Framework
File:        FlightIndoor.cpp
Description: Could only run on linux. Device is Manifold.
Date:        2017-06-30
Version:     2.1
Authors:     Deyou Kong <370242479@qq.com>
History:     01, 17-06-30, Deyou Kong, Create file and implement it.
             02, 17-09-07, Deyou Kong, Use CLogger to log info.
			 03, 17-10-15, Deyou Kong, Remove external CLogger class and implement it locally.

************************************************************/

#include "FlightIndoor.h"

void CFlightIndoor::IdrFlyHeight(float fHeight)
{
	FlightData fd;
	fd.flag = 0x5B; // 0x5BHEX = 01011011BIN
	fd.x = 0;
	fd.y = 0;
	fd.z = fHeight;
	fd.yaw = 0;

	pScript->getFlight()->setFlight(&fd);
}

void CFlightIndoor::IdrFlyUp(float fSpeed)
{
	// Default parameter:
	// fSpeed = 0.7

	FlightData fd;
	fd.flag = 0x4B; // 0x4BHEX = 01001011BIN
	fd.x = 0;
	fd.y = 0;
	fd.z = fSpeed;
	fd.yaw = 0;

	pScript->getFlight()->setFlight(&fd);
}

void CFlightIndoor::IdrFlyDn(float fSpeed)
{
	// Default parameter:
	// fSpeed = 0.7

	FlightData fd;
	fd.flag = 0x4B; // 0x4BHEX = 01001011BIN
	fd.x = 0;
	fd.y = 0;
	fd.z = -fSpeed;
	fd.yaw = 0;

	pScript->getFlight()->setFlight(&fd);
}

void CFlightIndoor::IdrFlying(float fSpeedX, float fSpeedY, float fHeight, float fYawRate)
{
	// Default parameter:
	// fYawRate = 0.0

	FlightData fd;
	fd.flag = 0x5B; // 0x5BHEX = 01011011BIN
	fd.x = fSpeedX;
	fd.y = fSpeedY;
	fd.z = fHeight;
	fd.yaw = fYawRate;

	pScript->getFlight()->setFlight(&fd);
}

