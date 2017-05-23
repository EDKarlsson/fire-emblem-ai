cmake_minimum_required(VERSION 3.7)
project(fire_emblem_ai)

# Set Libs
set(CMAKE_CXX_STANDARD 11)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

# Find packages
find_package(OpenCV REQUIRED)
find_package(Boost 1.64.0 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(SOURCE_FILES main.cpp ImageProcessor.cpp ImageProcessor.h)
add_executable(fire_emblem_ai ${SOURCE_FILES})
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(fire_emblem_ai ${OpenCV_LIBS} ${Boost_LIBRARIES})
