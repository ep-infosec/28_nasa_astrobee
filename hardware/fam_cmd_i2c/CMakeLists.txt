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
project(fam_cmd_i2c)

## Compile as C++14, supported in ROS Kinetic and newer
add_compile_options(-std=c++14)

## Find catkin macros and libraries
find_package(catkin2 REQUIRED COMPONENTS
  roscpp
  rospy
  ff_msgs
  std_msgs
  i2c
)

catkin_package(
  CATKIN_DEPENDS roscpp rospy ff_msgs std_msgs i2c
)

###########
## Build ##
###########

# Specify additional locations of header files
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ executable: inspection_tool
add_executable(fam_cmd_gen tools/fam_cmd_gen.cc)
add_dependencies(fam_cmd_gen ${catkin_EXPORTED_TARGETS})
target_link_libraries(fam_cmd_gen
  ${catkin_LIBRARIES})

## Declare a C++ executable: inspection_tool
add_executable(fam_cmd_i2c_node tools/fam_cmd_i2c_node.cc)
add_dependencies(fam_cmd_i2c_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(fam_cmd_i2c_node
  ${catkin_LIBRARIES})

#############
## Install ##
#############

# Install C++ executables
install(TARGETS fam_cmd_gen DESTINATION bin)
install(TARGETS fam_cmd_i2c_node DESTINATION bin)
install(CODE "execute_process(
  COMMAND ln -s ../../bin/fam_cmd_gen share/${PROJECT_NAME}
  COMMAND ln -s ../../bin/fam_cmd_i2c_node share/${PROJECT_NAME}
  WORKING_DIRECTORY ${CMAKE_INSTALL_PREFIX}
  OUTPUT_QUIET
  ERROR_QUIET
  )")

# Mark launch files for installation
install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
  PATTERN ".svn" EXCLUDE)

