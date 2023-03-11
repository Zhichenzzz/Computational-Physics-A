//
// Created by HUAWEI on 2022/9/11.
//

#include "windows.h"

#include <string>

#include <fstream>
#include <sstream> //字符串转换

#include <iostream>
#include <cmath>
using namespace std;
#define A 16807
#define Q 127773
#define M 2147483647
#define R 2836
#define PI 3.141592653589793
#ifndef MAIN_CPP_SCH_H
#define MAIN_CPP_SCH_H


class Sch {
public:
    int Seed();
    int Sch_16807(int z);
    void Save_Random(int seed, int N, char const url[]);
    void Cos(int N, char const* url);
    void Phi(int N, const char *url);

};


#endif //MAIN_CPP_SCH_H
