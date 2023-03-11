//
// Created by HUAWEI on 2022/9/11.
//
#include <iostream>
#include "windows.h"
#include <fstream>
#include <string>

using namespace std;
//一些数据的定义
#define A 16807
#define Q 127773
#define M 2147483647
#define R 2836

#ifndef MAIN_CPP_SCH_H
#define MAIN_CPP_SCH_H


class Sch {                 //类封装
public:
    int Seed();
    int Sch_16807(int z);
    void Save_Random(int seed, int N, char const url[]);
};


#endif //MAIN_CPP_SCH_H
