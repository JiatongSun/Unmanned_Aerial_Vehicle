//
// Created by xixiliadorabarry on 2/26/19.
//

#ifndef AERIAL_AERIAL_H
#define AERIAL_AERIAL_H

#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>
#include "mynteye/api/api.h"
#include "util/pc_viewer.h"
#include "aerial/param_struct_define.h"

using namespace std;
using namespace mynteye;
using namespace cv;
using namespace pcl;

class Aerial {
public:
    Aerial();
    ~Aerial();
    int run(Mat &src0, Mat &src1);

    void setVideoMode(int mode);
    void setPcViewer(PCViewer pcviewer);

private:
    int video_mode;
    PCViewer pc;

    void initEnergyPartParam();

    void showVideo(Mat src0, Mat src1);
    void showDistance(Mat src0, Mat src1);

};

#endif //AERIAL_AERIAL_H
