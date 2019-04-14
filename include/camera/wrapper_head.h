//
// Created by sun on 19-4-1.
//

#ifndef AERIAL_WRAPPER_HEAD_H
#define AERIAL_WRAPPER_HEAD_H

#include "aerial/aerial.h"
#include <opencv2/core/core.hpp>

/**
 * @brief A virtual class for wrapper of camera and video files
 */
class WrapperHead {

public:
    virtual ~WrapperHead() = default;;
    virtual bool init() = 0;
    virtual bool read(cv::Mat &src_left, cv::Mat &src_right) = 0;

};

#endif //AERIAL_WRAPPER_HEAD_H
