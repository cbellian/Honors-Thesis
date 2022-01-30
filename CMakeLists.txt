cmake_minimum_required(VERSION 3.10)

project(EnhancerID)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "/Users/cameronbellian/Desktop/CPP_Libs/Boost/boost_1_77_0")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "/Users/cameronbellian/Desktop/CPP_Libs/Boost/boost_1_77_0/stage/lib")

FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

add_executable(EnhancerID EnhancerID.cpp EnhancerIDDriver.cpp)