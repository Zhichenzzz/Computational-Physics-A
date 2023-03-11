cmake_minimum_required(VERSION 3.23)
project(homework_9)

set(CMAKE_CXX_STANDARD 14)

add_executable(homework_9 main.cpp Sch.cpp Sch.h exp_distribution.cpp
        exp_distribution.h Poisson.cpp Poisson.h Lorentz.cpp Lorentz.h
        F_function.h F_function.cpp
        )
