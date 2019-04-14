//
// Created by xixiliadorabarry on 2/26/19.
//
//
// Created by xixiliadorabarry on 2/25/19.
//
#include <fstream>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <time.h>
#include <jmorecfg.h>

#include "aerial/aerial.h"
#include "camera/camera_wrapper.h"
#include "camera/video_wrapper.h"
#include "camera/wrapper_head.h"
#include "util/pc_viewer.h"

using namespace cv;
using namespace std;


int main(int argc, char *argv[])
{
    bool flag = true;
    while (flag)
    {
        int from_camera = 1;
        cout<<"Input 1 for camera, 0 for video files"<<endl;
        cin>>from_camera;

        WrapperHead *video;
        VideoMode video_mode;
        Aerial aerial;

        int mode;

        if(from_camera)
        {
            mode = video_mode.RECTIFIED_MODE;
            video = new CameraWrapper(argc,argv,mode);

        }
        else

        {
            mode = video_mode.VIDEO_FILES;
            video = new VideoWrapper("video_1.avi", "video_2.avi");
        }

        if (video->init()) {
            cout << "Video source initialization successfully." << endl;
        }



        Mat src0, src1;
        PCViewer pc_viewer;

        aerial.setPcViewer(pc_viewer);
        aerial.setVideoMode(mode);


//----------------------Write a video-----------------------
        VideoWriter video_writer_1, video_writer_2;
        string file_name_1 = "/home/sun/视频/video_1.avi";
        video_writer_1.open(file_name_1,
                          CV_FOURCC('M','P','E','G'),
                        //CV_FOURCC('D','I','V','X'),
                        //CV_FOURCC('P','I','M','1'),
                          30,
                          cv::Size(752, 480), FALSE);

        if(!video_writer_1.isOpened())
        {
            cout<<"open writer 1 failed, check the video path."<<endl;
        }

        string file_name_2 = "/home/sun/视频/video_2.avi";
        video_writer_2.open(file_name_2,
//                            CV_FOURCC('M','P','E','G'),
//                            CV_FOURCC('D','I','V','X'),
                            CV_FOURCC('P','I','M','1'),
                            30,
                            cv::Size(752, 480),FALSE);

        if(!video_writer_2.isOpened())
        {
            cout<<"open writer 2 failed, check the video path."<<endl;
        }


//----------------------------------------------------------


        while (video->read(src0, src1))
        {

            if(!src0.empty() && !src1.empty()){
                aerial.run(src0,src1);


//----------------------Write a video-----------------------
                video_writer_1.write(src0);
                video_writer_2.write(src1);
//----------------------------------------------------------


            }

            if (waitKey(10) == 'q') {
                flag = false;
                break;
            }
        }
        delete video;
//----------------------Write a video-----------------------
        video_writer_1.release();
        video_writer_2.release();
//----------------------------------------------------------

        cout << "Program fails. Restarting" << endl;
    }

    return 0;
}
