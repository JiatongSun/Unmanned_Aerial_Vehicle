//
// Created by sun on 19-4-8.
//

#include "aerial/aerial.h"

using namespace std;
using namespace cv;
using namespace pcl;

void Aerial::showVideo(Mat src0, Mat src1){
    switch (video_mode){

        case 0: case 1:
        {
            cv::Mat img;
            cv::hconcat(src0, src1, img);
            cv::imshow("frame", img);
            break;
        }

        case 2:
        {
            cv::Mat img_rectified;
            cv::hconcat(src0, src1, img_rectified);
            cv::imshow("frame_rectified", img_rectified);
            break;
        }

        case 3:
        {
            cv::imshow("disparity", src0);
            break;
        }

        case 4:
        {
            cv::imshow("depth", src0);
            break;
        }

        case 5:
        {
            pc.Update(src0);
            break;
        }

        case 6:
        {
            cv::imshow("disparity_norm", src0);
            break;
        }

        case 7:
        {
            cv::imshow("depth_norm", src0);
            break;
        }

        default:
        {
            cout<<"Mode Error!"<<endl;
        }

    }


}

void Aerial::showDistance(Mat src0, Mat src1){
    if(video_mode!=7)return;
    ushort distance = src0.at<ushort>(376,240);//图像中心的深度，图像总大小为752×480，可以选取别的点读深度
    if(distance >= 10000)return;
    cout<<"distance: "<<distance<<endl;
}