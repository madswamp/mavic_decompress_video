//
// Created by madswamp on 22/04/21.
//

#ifndef MAVIC_INTERFACE_MAVIC_RECEIVE_VIDEO_H
#define MAVIC_INTERFACE_MAVIC_RECEIVE_VIDEO_H

#include "ros/ros.h"
#include "sensor_msgs/CompressedImage.h"
#include "sensor_msgs/Image.h"
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <camera_info_manager/camera_info_manager.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>

const std::string calibration_file_path = "package://mavic_interface_ros/config/calibration_mavic_pro.yaml";
const std::string camera_name = "sensor_measurement/camera";

class mavic_receive_video
{
private:
    ros::NodeHandle nh;
    ros::Subscriber video_compressed_sub;


    void video_compressed_callback(const sensor_msgs::CompressedImageConstPtr& msg);


    sensor_msgs::CompressedImage image_compressed;



public:
    mavic_receive_video();
    ~mavic_receive_video();
    ros::Publisher  video_raw_pub,camera_info_pub;

    void uncompress_frame_and_pub();
    bool flag_new_frame=false;
};

#endif //MAVIC_INTERFACE_MAVIC_RECEIVE_VIDEO_H
