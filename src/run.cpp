//
// Created by xixiliadorabarry on 19-3-8.
//

#include "aerial/aerial.h"
#include "pcl_tool/pcl_tool.h"

int Aerial::run(Mat &src0, Mat &src1){
    showVideo(src0,src1);
    showDistance(src0,src1);

    return 0;
}

int PCLTool::run(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud) {
    passThrough(cloud);
    voxelGridFilter(cloud);
    sorFilter(cloud);
//    clusterExtraction(cloud);
}