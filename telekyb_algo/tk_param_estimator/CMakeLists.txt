# Catkin User Guide: http://www.ros.org/doc/groovy/api/catkin/html/user_guide/user_guide.html
# Catkin CMake Standard: http://www.ros.org/doc/g:qroovy/api/catkin/html/user_guide/standards.html
cmake_minimum_required(VERSION 2.8.3)
project(tk_param_estimator)

list(APPEND CMAKE_MODULE_PATH $ENV{TELEKYB_CMAKE_SCRIPTS_DIR})
if (DEFINED $ENV{BOOST_ROOT})
        set(BOOST_ROOT $ENV{BOOST_ROOT})
endif()
if (DEFINED $ENV{YAMLCPP_ROOT})
        set(YAMLCPP_ROOT $ENV{YAMLCPP_ROOT})
endif()

find_package(catkin REQUIRED COMPONENTS roscpp telekyb_defines telekyb_base tk_draft_msgs pluginlib cmake_modules)
find_package(Boost QUIET REQUIRED COMPONENTS system thread)
find_package(YamlCpp REQUIRED)
find_package(Eigen REQUIRED)

#MESSAGE(FATAL_ERROR ${PROJECT_SOURCE_DIR}/include/telekyb_base/Options/)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}
	${EIGEN_INCLUDE_DIRS}
	${catkin_INCLUDE_DIRS}
)


add_library(${PROJECT_NAME}
	src/MassEstimator.cpp
	src/InertiaMatrixEstimator.cpp
)

add_dependencies(${PROJECT_NAME}
        telekyb_msgs_generate_messages_cpp
        telekyb_srvs_generate_messages_cpp
        tk_draft_msgs_generate_messages_cpp
)


#target_link_libraries(${PROJECT_NAME}
#        ${Boost_LIBRARIES}
#        ${YAMLCPP_LIBRARY}
#        ${catkin_LIBRARIES}
#	${PROJECT_NAME}
#)

catkin_package(
    DEPENDS roscpp Boost
    CATKIN_DEPENDS telekyb_defines telekyb_base
    INCLUDE_DIRS include
    LIBRARIES ${PROJECT_NAME}
)

