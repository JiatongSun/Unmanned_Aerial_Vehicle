//
// Created by xixiliadorabarry on 19-3-8.
//

#ifndef AERIAL_PC_VIEWER_H
#define AERIAL_PC_VIEWER_H

#include <memory>

#include <opencv2/core/core.hpp>

#include <pcl/visualization/pcl_visualizer.h>

#include "pcl_tool/pcl_tool.h"


class PCViewer {
public:
    PCViewer();
    ~PCViewer();

    void Update(const cv::Mat &xyz);

    void Update(pcl::PointCloud<pcl::PointXYZ>::ConstPtr pc);

    bool WasVisual() const;
    bool WasStopped() const;

    void ConvertMatToPointCloud(
            const cv::Mat &xyz, pcl::PointCloud<pcl::PointXYZ>::Ptr pc);

private:

    std::shared_ptr<pcl::visualization::PCLVisualizer> viewer_;
    PCLTool pcl_tool;
};

#endif //AERIAL_PC_VIEWER_H
