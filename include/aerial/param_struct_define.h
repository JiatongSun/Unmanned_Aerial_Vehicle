//
// Created by xixiliadorabarry on 2/26/19.
//

#ifndef AERIAL_PARAM_STRUCT_DEFINE_H
#define AERIAL_PARAM_STRUCT_DEFINE_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

using namespace std;

struct VideoMode {
    int VIDEO_FILES = 0;
    int RAW_MODE = 1;
    int RECTIFIED_MODE = 2;
    int DISPARITY_MODE = 3;
    int DEPTH_MODE = 4;
    int POINT_MODE = 5;
    int DISPARITY_NORM_MODE = 6;
    int DEPTH_NORM_MODE = 7;
};

#endif //AERIAL_PARAM_STRUCT_DEFINE_H
