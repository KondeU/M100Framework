/************************************************************

GNU GENERAL PUBLIC LICENSE, Version 3, 29 June 2007
Copyright (c) 2017, KondeU, All rights reserved.

Project:     M100Framework
File:        _Task.cpp
Description: Could only run on linux. Device is Manifold.
Date:        2017-06-30
Version:     2.1
Authors:     Deyou Kong <370242479@qq.com>
History:     01, 17-06-30, Deyou Kong, Create file and implement it.

************************************************************/

#include "conboardsdktask.h"

//#define MODE_DATATRANSPARENT // Communicate between Onboard and Remote, another define in _Main.cpp
#ifdef MODE_DATATRANSPARENT
// If use a structure, should use the "#pragma pack(1)"
void DataTransparent(DJI::onboardSDK::CoreAPI * api, Header * pHeader, void * pData)
{
	// Data start is "((char*)(pHeader))[14]"
	// TODO
	void MyDataTransparent(void * pData);
	MyDataTransparent(&(pHeader[14]));
	return;
}
#endif

bool Startup()
{
	// TODO
	return true;
}

bool Cleanup()
{
	// TODO
	return true;
}

int Flightask(ConboardSDKScript & sdkScript)
{
	// TODO
	int MyTask(ConboardSDKScript & sdkScript);
	MyTask(sdkScript);
	return 0;
}

