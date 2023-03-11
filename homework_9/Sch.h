//
// Created by HUAWEI on 2022/9/11.
//
#include <iostream>
#include "windows.h"
#include <fstream>
#include <string>

using namespace std;
#define A 16807
#define Q 127773
#define M 2147483647
#define O 4294967290
#define R 2836

#ifndef MAIN_CPP_SCH_H
#define MAIN_CPP_SCH_H


class Sch {
public:
    static int Seed();
    static int Sch_16807(int z);
    void Save_Random(int seed, int N, char const url[]);
    static void save_seed(int N);
//    double Sch_Test_weight(int N);
//    double fibonacci_dalayed(int N, int p, int q);

};


#endif //MAIN_CPP_SCH_H
