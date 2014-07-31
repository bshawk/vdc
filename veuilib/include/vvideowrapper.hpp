#ifndef __V_VIDEO_WRAPPER_HPP__
#define __V_VIDEO_WRAPPER_HPP__
#include "utility.hpp"
#include "debug.hpp"
#include "videotype.hpp"
#include <QWidget>
#include "factory.hpp"
#include <QThread>

using namespace UtilityLib;

class VE_LIBRARY_API VVideoWrapper : public QWidget
{
	Q_OBJECT
public:
	VVideoWrapper(QWidget *parent = 0);
	~VVideoWrapper();
public:
	virtual BOOL Play(astring strUrl, int startTime, int endTime);
public:
	static VVideoWrapper * CreateObject(QWidget *parent);
private:
	
};


#endif /* __V_VIDEO_WRAPPER_HPP__ */
