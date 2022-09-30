cmake_minimum_required(VERSION 3.23)
project(TopSystemsInterviewTestCase)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(TopSystemsInterviewTestCase src/main.cpp src/ui/mainwindow.h src/ui/mainwindow.cpp)
target_link_libraries(TopSystemsInterviewTestCase
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        )

