cmake_minimum_required(VERSION 3.23)
project(homework_1_random_numbers)

set(CMAKE_CXX_STANDARD 14)

#include_directories(${PROJECT_SOURCE_DIR}/include)
# 指定头文件搜索路径
#link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(homework_1_random_numbers Random_num.cpp Sch.cpp Sch.h)

#target_link_libraries(${PROJECT_NAME} libCP_Library.a)
