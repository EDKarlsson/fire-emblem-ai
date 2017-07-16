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
find_package(Tesseract 3.05.0 REQUIRED)
find_package(Leptonica 1.74.2 REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

if(Tesseract_FOUND)
    include_directories(${Tesseract_INCLUDE_DIRS})
endif()

if(OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
endif()

if(Leptonica_FOUND)
    include_directories(${Leptonica_INCLUDE_DIRS})
endif()

set(SOURCE_FILES src/main.cpp src/ImageProcessing/ImageProcessor.cpp src/ImageProcessing/ImageProcessor.h src/Core/Character.cpp src/Core/Character.h src/Core/Game.cpp src/Core/Game.h src/Core/GameBoard.cpp src/Core/GameBoard.h test/combat.cpp test/combat.h)
add_executable(fire_emblem_ai ${SOURCE_FILES})
target_link_libraries(fire_emblem_ai ${OpenCV_LIBS} ${Boost_LIBRARIES} ${Tesseract_LIBRARIES} ${Leptonica_LIBRARIES})
