//
// Created by xixiliadorabarry on 19-3-16.
//

#include <iostream>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>
#include "pcl_tool/pcl_tool.h"

void PCLTool::passThrough (pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud)
{
    std::cerr << "Cloud before filtering: " << cloud->points.size()<< std::endl;

    pcl::PassThrough<pcl::PointXYZ> pass;
    pass.setInputCloud (cloud);
    pass.setFilterFieldName ("z");
    pass.setFilterLimits (0, 750.0);
    //pass.setFilterLimitsNegative (true);
    pass.filter (*cloud);

    std::cerr << "Cloud after filtering: " << cloud->points.size()<< std::endl;
}