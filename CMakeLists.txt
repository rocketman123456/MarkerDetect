cmake_minimum_required(VERSION 3.5)

SET(OpenCV_DIR "E:/vcpkg/installed/x64-windows/share/opencv")

project(MarkerDetect LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV CONFIG REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(MarkerDetect SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    DataPack.h
    camthread.cpp
    camthread.h
  )
else()
  add_executable(MarkerDetect
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    DataPack.h
    camthread.cpp
    camthread.h
  )
endif()

target_link_libraries(MarkerDetect PRIVATE
    Qt5::Widgets
    opencv_ml
    opencv_dnn
    opencv_dpm
    opencv_hdf
)
