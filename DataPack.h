#ifndef DATAPACK_H
#define DATAPACK_H

#include <opencv2/opencv.hpp>
#include <vector>

// 与窗口通信
struct _FrameMsg
{
    int32_t id;
    cv::Mat *img;
} FrameMsg;

// 串口线程发送给摄像头线程
struct _SerialMsg
{
    uint8_t command = 0;
    int32_t id = -1;
    int32_t dic_id = 0;
    uint8_t label_id = 0;
    double labelsz = 0.0;
    // 标定用数据
    int32_t x = 0;
    int32_t y = 0;
    double sz_square = 0.0;
    double sz_marker = 0.0;
    int32_t frame_count = 0;
    int16_t label_type = 0;
} SerialMsg;

// 摄像头线程发送给串口线程
struct _CamMsg
{
    int32_t id = -1;
    uint8_t respond = 0;
    bool state = false;
    double result_time = 0.0;
    // 计算结果返回
    uint8_t label_id[2];
    float x[2],y[2],z[2];
    float q1[2],q2[2],q3[2],q4[2];
    uint32_t dt = 0;
} CamMsg;

// 存储自检信息等
struct _CamCheckInfo
{
    bool getRes[2] = { false, false };
    bool state[2] = { false, false };
    double dt[2] = { 0.0, 0.0 };
} CamCheckInfo;

#endif // DATAPACK_H
