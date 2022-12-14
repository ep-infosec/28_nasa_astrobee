# Copyright (c) 2017, United States Government, as represented by the
# Administrator of the National Aeronautics and Space Administration.
# 
# All rights reserved.
# 
# The Astrobee platform is licensed under the Apache License, Version 2.0
# (the "License"); you may not use this file except in compliance with the
# License. You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations
# under the License.

cmake_minimum_required(VERSION 3.0)
project(flycapture)

## Compile as C++14, supported in ROS Kinetic and newer
add_compile_options(-std=c++14)

# Need to think of a better way to get flycapture
find_path(FLYCAPTURE_INCLUDE_DIR flycapture/FlyCapture2Defs.h
  HINTS ${FLYCAPTURE_ROOT_DIR}/include /usr)
find_library(FLYCAPTURE_LIBRARY NAMES flycapture libflycapture
  HINTS /usr/lib ${FLYCAPTURE_ROOT_DIR}/lib)
# find_package_handle_standard_args(FLYCAPTURE DEFAULT_MSG
#   FLYCAPTURE_INCLUDE_DIR FLYCAPTURE_LIBRARY)

find_package(catkin REQUIRED COMPONENTS
)

catkin_package(
  LIBRARIES flycapture
  CATKIN_DEPENDS roscpp cv_bridge image_transport
)


if (FLYCAPTURE_FOUND)
  ## Declare a C++ executable: fly_node
  add_executable(fly_node tools/fly_node.cc)
  add_dependencies(fly_node ${catkin_EXPORTED_TARGETS})
  target_link_libraries(fly_node
    gflags ${catkin_LIBRARIES})
else()
  message(STATUS "Not building fly_node")
endif()
