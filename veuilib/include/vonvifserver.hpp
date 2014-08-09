#ifndef __V_ONVIF_SERVER_HPP__
#define __V_ONVIF_SERVER_HPP__
#include "utility.hpp"
#include "debug.hpp"
#include "videotype.hpp"
#include <QWidget>
#include "factory.hpp"
#include <QThread>

using namespace UtilityLib;

class VE_LIBRARY_API VONVIFServer
{
public:
	VONVIFServer();
	~VONVIFServer();
public:
	InitRTSPServer();
	InitProfileSSim();
private:

};


#endif /* VONVIFServer */
