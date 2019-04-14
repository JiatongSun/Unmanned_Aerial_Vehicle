//
// Created by xixiliadorabarry on 19-3-25.
//

//该.cpp用于对点云进行体素过滤，即以单位立方网格为单位，降低点云数目，便于后期操作

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include "pcl_tool/pcl_tool.h"

void PCLTool::voxelGridFilter(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud){
    pcl::PCLPointCloud2::Ptr cloud_blob(new pcl::PCLPointCloud2),
            cloud_filtered_blob(new pcl::PCLPointCloud2);//申明滤波前后的点云
    pcl::toPCLPointCloud2(*cloud, *cloud_blob);
    std::cerr << "PointCloud before filtering: " << cloud_blob->width * cloud_blob->height
              << " data points (" << pcl::getFieldsList (*cloud_blob) << ").";
    cout<<endl;

    // Create the filtering object
    pcl::VoxelGrid<pcl::PCLPointCloud2> vg;
    vg.setInputCloud (cloud_blob);
    vg.setLeafSize (20, 20, 20);
    vg.filter (*cloud_filtered_blob);

    pcl::fromPCLPointCloud2(*cloud_filtered_blob, *cloud);
    std::cerr << "PointCloud after filtering: " << cloud_filtered_blob->width * cloud_filtered_blob->height
              << " data points (" << pcl::getFieldsList (*cloud_filtered_blob) << ").";
    cout<<endl;
}