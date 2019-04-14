//
// Created by sun on 19-4-10.
//

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include "util/pc_viewer.h"
#include "pcl_tool/pcl_tool.h"

using namespace cv;

void PCLTool::sorFilter (pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud)
{
    // Create the filtering object
    pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
    sor.setInputCloud (cloud);
    sor.setMeanK (50);
    sor.setStddevMulThresh (1.0);
    sor.filter (*cloud);

//    sor.setNegative (true);
//    sor.filter (*cloud);
}