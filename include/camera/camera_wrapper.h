//
// Created by sun on 19-4-1.
//

#ifndef AERIAL_CAMERA_WRAPPER_H
#define AERIAL_CAMERA_WRAPPER_H

#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>

#include "camera/wrapper_head.h"
#include "mynteye/api/api.h"

using namespace std;

class CameraWrapper: public WrapperHead {
private:
    shared_ptr<mynteye::API> api;
    int video_mode;

    bool readRaw(cv::Mat& src0, cv::Mat& src1);
    bool readRectified(cv::Mat& src0, cv::Mat& src1);
    bool readDisparity(cv::Mat &src0, cv::Mat &src1);
    bool readDepth(cv::Mat &src0, cv::Mat &src1);
    bool readPoints(cv::Mat &src0, cv::Mat &src1);
    bool readDisparityNorm(cv::Mat &src0, cv::Mat &src1);
    bool readDepthNorm(cv::Mat &src0, cv::Mat &src1);



public:
    CameraWrapper(int argc, char *argv[], int mode);
    ~CameraWrapper() final;

    bool init() final;
    bool read(cv::Mat& src0, cv::Mat& src1) final;

};

#endif //AERIAL_CAMERA_WRAPPER_H
