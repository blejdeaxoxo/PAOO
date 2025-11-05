cmake_minimum_required(VERSION 3.16)

project(TaskManagerApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TaskManagerApp
    src/main.cpp
    src/Task.cpp
    src/TaskManager.cpp
)

target_include_directories(TaskManagerApp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
