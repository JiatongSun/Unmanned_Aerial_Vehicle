//
// Created by sun on 19-4-9.
//

#ifndef AERIAL_PCL_TOOL_H
#define AERIAL_PCL_TOOL_H

#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>
#include "mynteye/api/api.h"

using namespace std;
using namespace mynteye;
using namespace cv;
using namespace pcl;

class PCLTool {
public:
    PCLTool();
    ~PCLTool();

    int run(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud);

private:
    void sorFilter (pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud);
    void passThrough (pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud);
    void voxelGridFilter(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud);
    void clusterExtraction(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud);

};

#endif //AERIAL_PCL_TOOL_H
