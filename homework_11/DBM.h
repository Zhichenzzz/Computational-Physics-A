//
// Created by HUAWEI on 2022/11/5.
//

#ifndef MAIN_CPP_DBM_H
#define MAIN_CPP_DBM_H
#include "Particle.h"
#include <iostream>

extern void ini_G();
extern float phi_calculate(int i, int j);
extern void growth_rate(int i, int j);
extern void MC_Laplace();

extern void single_broken(int i, int j);
extern void Laplace_equations(float* G, int length);
extern void print();
#endif //MAIN_CPP_DBM_H
