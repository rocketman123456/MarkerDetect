#ifndef CAMTHREAD_H
#define CAMTHREAD_H

#include <QThread>
#include <QMutex>
#include <QDebug>
#include <QTime>

#include <opencv2/opencv.hpp>
#include <vector>

#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

class CamThread : public QThread
{
    Q_OBJECT
public:
    explicit CamThread(int32_t w,int32_t h,int32_t id, QObject *parent);
    ~CamThread();

protected:
    QMutex _lock; // thread lock
    QTime  _timer;

    int32_t _width = 0;
    int32_t _height = 0;
    int32_t _cam_id = -1;
    int64_t _count = 0;

    // camera variable
    cv::VideoCapture _cam;
    cv::Mat _img;
    cv::Mat _camMatrix;
    cv::Mat _distCoeffs;

    // calibration
    std::string _pathCamParam;
    //aruco::CameraParameters _camParam;
};

#endif // CAMTHREAD_H
