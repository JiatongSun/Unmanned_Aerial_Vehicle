#include <camera/camera_wrapper.h>
#include "mynteye/api/api.h"
#include "util/pc_viewer.h"

using std::cout;
using std::endl;
using namespace cv;
using namespace mynteye;

CameraWrapper::CameraWrapper(int argc, char *argv[], int mode)
{
    api = mynteye::API::Create(argc,argv);
    video_mode = mode;
}


bool CameraWrapper::init() {
    bool ok;
    auto &&request = api->SelectStreamRequest(&ok);
    if (!ok)return false;
    api->ConfigStreamRequest(request);
    api->Start(mynteye::Source::VIDEO_STREAMING);
    return true;
}

CameraWrapper::~CameraWrapper()
{
    api->Stop(Source::VIDEO_STREAMING);
}


bool CameraWrapper::read(cv::Mat& src0, cv::Mat& src1) {
    api->WaitForStreams();
    switch (video_mode){
        case 1:
        {
            return readRaw(src0, src1);
        }

        case 2:
        {
            return readRectified(src0, src1);
        }

        case 3:
        {
            return readDisparity(src0,src1);
        }

        case 4:
        {
            return readDepth(src0,src1);
        }

        case 5:
        {
            return readPoints(src0,src1);
        }

        case 6:
        {
            return readDisparityNorm(src0,src1);
        }

        case 7:
        {
            return readDepthNorm(src0,src1);
        }
    }

}

bool CameraWrapper::readRaw(cv::Mat &src0, cv::Mat &src1) {


    auto &&left_data = api->GetStreamData(Stream::LEFT);
    auto &&right_data = api->GetStreamData(Stream::RIGHT);

    src0 = left_data.frame;
    src1 = right_data.frame;

    return true;
}

bool CameraWrapper::readRectified(cv::Mat &src0, cv::Mat &src1) {
    api->EnableStreamData(Stream::LEFT_RECTIFIED);
    api->EnableStreamData(Stream::RIGHT_RECTIFIED);

    api->SetDisparityComputingMethodType(DisparityComputingMethod::BM);

    auto &&left_data = api->GetStreamData(Stream::RIGHT_RECTIFIED);
    auto &&right_data = api->GetStreamData(Stream::LEFT_RECTIFIED);

    src0 = left_data.frame;
    src1 = right_data.frame;

    return true;
}

bool CameraWrapper::readDisparity(cv::Mat &src0, cv::Mat &src1){
    api->EnableStreamData(Stream::DISPARITY);

    auto &&disp = api->GetStreamData(Stream::DISPARITY);

    src0 = disp.frame;
    src1 = disp.frame;

    return true;
}

bool CameraWrapper::readDepth(cv::Mat &src0, cv::Mat &src1) {
    api->EnableStreamData(Stream::DEPTH);

    auto &&depth_data = api->GetStreamData(Stream::DEPTH);

    src0 = depth_data.frame;
    src1 = depth_data.frame;

    return true;
}

bool CameraWrapper::readPoints(cv::Mat &src0, cv::Mat &src1) {
    api->EnableStreamData(Stream::POINTS);

    auto &&points_data = api->GetStreamData(Stream::POINTS);

    src0 = points_data.frame;
    src1 = points_data.frame;

    return true;
}

bool CameraWrapper::readDisparityNorm(cv::Mat &src0, cv::Mat &src1){
    api->EnableStreamData(Stream::DISPARITY_NORMALIZED);

    api->SetDisparityComputingMethodType(DisparityComputingMethod::BM);
    auto &&disp_norm_data = api->GetStreamData(Stream::DISPARITY_NORMALIZED);

    src0 = disp_norm_data.frame;
    src1 = disp_norm_data.frame;

    return true;
}

bool CameraWrapper::readDepthNorm(cv::Mat &src0, cv::Mat &src1) {
    api->EnableStreamData(Stream::DEPTH);

    api->SetDisparityComputingMethodType(DisparityComputingMethod::BM);
    auto &&depth_data = api->GetStreamData(Stream::DEPTH);

    src0 = depth_data.frame;
    src1 = depth_data.frame;

    return true;
}



