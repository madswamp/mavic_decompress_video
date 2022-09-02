cmake_minimum_required(VERSION 3.0.2)

set(PROJECT_NAME mavic_decompress_video)
project(${PROJECT_NAME})

add_definitions(-std=c++11)


set(MAVIC_RECEIVE_VIDEO_INCLUDE_DIR
        include/mavic_interface_ros/mavic_receive_video)


set(MAVIC_RECEIVE_VIDEO_LIB_FILES
        include/mavic_interface_ros/mavic_receive_video/mavic_receive_video.h
        src/mavic_receive_video/mavic_receive_video.cpp)


find_package(catkin REQUIRED COMPONENTS
        cv_bridge
        geometry_msgs
        roscpp
        rospy
        sensor_msgs
        std_msgs
        # aerostack_msgs
        tf
        camera_info_manager)


find_package(PkgConfig)
find_package( OpenCV REQUIRED )



catkin_package(
        CATKIN_DEPENDS geometry_msgs roscpp rospy sensor_msgs std_msgs
        cv_bridge camera_info_manager)


include_directories(
        ${catkin_INCLUDE_DIRS}
        ${MAVIC_RECEIVE_VIDEO_INCLUDE_DIR}
        ${OpenCV_INCLUDE_DIRS}


)


add_library(mavic_receive_video_includes ${MAVIC_RECEIVE_VIDEO_LIB_FILES})
add_dependencies(mavic_receive_video_includes ${catkin_EXPORTED_TARGETS})
target_link_libraries(mavic_receive_video_includes ${catkin_LIBRARIES} ${OpenCV_LIBS})


add_executable(mavic_decompress_video_node src/mavic_receive_video/mavic_receive_video_node.cpp)
add_dependencies(mavic_decompress_video_node  ${catkin_EXPORTED_TARGETS})
target_link_libraries(mavic_decompress_video_node  mavic_receive_video_includes)
target_link_libraries(mavic_decompress_video_node  ${catkin_LIBRARIES} ${OpenCV_LIBS})
