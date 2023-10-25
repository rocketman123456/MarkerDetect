#include "camthread.h"

CamThread::CamThread(int32_t w,int32_t h,int32_t id, QObject *parent)
    : QThread(parent), _width(w), _height(h), _cam_id(id)
{

}

CamThread::~CamThread()
{
    _cam.release();
}
