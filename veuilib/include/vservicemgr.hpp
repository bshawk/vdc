//------------------------------------------------------------------------------
// File: vservicemgr.hpp
//
// Desc: service manager - Manage ONVIF Service.
//
// Copyright (c) 2014-2018 vdceye. All rights reserved.
//------------------------------------------------------------------------------

#ifndef __V_SERVICE_MGR_HPP__
#define __V_SERVICE_MGR_HPP__
#include "utility.hpp"
#include "debug.hpp"
#include "videotype.hpp"
#include <QWidget>
#include "factory.hpp"
#include <QThread>
#include "vonvifdismgr.hpp"
#include "vvipcmgr.hpp"
#include "vonvifpgmgr.hpp"
#include "vrtspserver.hpp"

using namespace UtilityLib;

class VE_LIBRARY_API VServiceMgr
{
public:
	VServiceMgr();
	~VServiceMgr();

public:
	static VServiceMgr * CreateObject(Factory & pFactory);
public:
	/* ONVIF server */
	VOnvifDisMgr * m_pOnvifDisMgr;
	VVIPCMgr * m_pVVIPCMgr;
	VONVIFPGMgr * m_pVONVIFPGMgr;
	
	/* RTSP Server */
	VRTSPServer *m_pVRTSPServer;

};

#endif /* __V_SERVICE_MGR_HPP__ */
