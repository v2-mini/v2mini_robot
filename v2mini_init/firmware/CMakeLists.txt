cmake_minimum_required(VERSION 2.8.3)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x -fpermissive")

include_directories(${ROS_LIB_DIR})

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libraries)

generate_arduino_firmware(baseware
  SRCS baseware.cpp ${ROS_LIB_DIR}/time.cpp
  BOARD mega2560
  PORT /dev/arduino_mega_base
)

generate_arduino_firmware(torsoware
  SRCS torsoware.cpp ${ROS_LIB_DIR}/time.cpp
  BOARD mega
  PORT /dev/arduino_mega_head
)
