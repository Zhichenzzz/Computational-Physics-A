cmake_minimum_required(VERSION 3.23)
project(homework_17)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(homework_17
        main.cpp
        Particle.cpp
        Particle.h
        Sch.cpp
        Sch.h Sandbox_boxcounting.cpp Sandbox_boxcounting.h)
