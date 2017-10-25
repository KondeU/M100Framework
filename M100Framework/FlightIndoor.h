/************************************************************

GNU GENERAL PUBLIC LICENSE, Version 3, 29 June 2007
Copyright (c) 2017, KondeU, All rights reserved.

Project:     M100Framework
File:        FlightIndoor.h
Description: Could only run on linux. Device is Manifold.
Date:        2017-06-30
Version:     2.1
Authors:     Deyou Kong <370242479@qq.com>
History:     01, 17-06-30, Deyou Kong, Create file and implement it.
             02, 17-09-07, Deyou Kong, Use CLogger to log info.
			 03, 17-10-15, Deyou Kong, Remove external CLogger class and implement it locally.

************************************************************/

#pragma once

#include "Flight.h"

class CFlightIndoor : public CFlight
{
public:

	//CFlightIndoor(ConboardSDKScript * pst = nullptr) : CFlight(pst), cLog("FlightIndoor") {};
	CFlightIndoor(ConboardSDKScript * pst = nullptr) : CFlight(pst) {};

	void IdrFlyHeight(float fHeight);
	void IdrFlyUp(float fSpeed = 0.7);
	void IdrFlyDn(float fSpeed = 0.7);
	void IdrFlying(float fSpeedX, float fSpeedY, float fHeight, float fYawRate = 0.0);

private:

	//CLogger cLog;
};

