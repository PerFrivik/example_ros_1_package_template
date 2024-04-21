cmake_minimum_required(VERSION 3.0.2)
project(my_package)

# Set C++11 as the standard for the C++ compiler
add_compile_options(-std=c++11)

# Find necessary catkin packages for building this package
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

# Define what other packages will need to use this package
catkin_package(
  CATKIN_DEPENDS roscpp std_msgs
)

# Include directories for header files
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# Declare a C++ executable with the name <package_name>_node from the specified source files
add_executable(${PROJECT_NAME}_node src/Node.cpp)

# Link the executable to the necessary ROS libraries
target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)

# Mark the executable for installation, and specify the destination for installed executables
install(TARGETS ${PROJECT_NAME}_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
