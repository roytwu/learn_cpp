#* Use OpenCV without Trunk 
#* History: 
#*   02/08/2019  initial version
#*   02/26/2019  adding Eigen library
#*   03/13/2020  adding Boost library
 
#* set minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5 FATAL_ERROR)

#* project name and language
PROJECT(_tdd LANGUAGES CXX)

FIND_PACKAGE(OpenCV REQUIRED)
FIND_PACKAGE(Boost COMPONENTS unit_test_framework REQUIRED) #* 03/13

#*Read environment variable to custom name
SET(OpenCV_DIR       $ENV{OpenCV_DIR})
SET(EIGEN            $ENV{EIGEN_DIR})
SET(BOOST_R          $ENV{BOOST_ROOT})
SET(BOOST            $ENV{BOOST_INCLUDEDIR})

INCLUDE_DIRECTORIES(
  ${OpenCV_INCLUDE_DIRS} #* defined by OpenCV in OpenCVConfig.cmake 
  ${EIGEN}/include/eigen3/
  ${BOOST}
  #${BOOST}/lib/
  #${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}  #* 03/13
  ../      #* adding directory for the testing target, 05/05/2020
)

#* set source files
SET(SOURCE_FILES 
  main.cpp
)

SET(CMAKE_CXX_STANDARD 14)  #equivalent to adding a flag such as -std=gnu++14
SET(USE_LIBRARY       ON)
SET(BUILD_SHARED_LIBS OFF)

#ADD_LIBRARY(message
# STATIC #option: STATIC or SHARED
#  message.hpp
#  message.cpp
#)


#* add an executable to the project using the specified source files.
ADD_EXECUTABLE(exeTDD 
  ${SOURCE_FILES}
)

#* tell CMake that the library target has to be linked into the executable target
TARGET_LINK_LIBRARIES(exeTDD
  ${OpenCV_LIBS}
)
