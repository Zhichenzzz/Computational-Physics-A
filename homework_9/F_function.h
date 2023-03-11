//
// Created by HUAWEI on 2022/10/8.
//
#include "cmath"
#include "Sch.h"
#ifndef HOMEWORK_6_F_FUNCTION_H
#define HOMEWORK_6_F_FUNCTION_H
#define accuracy 1e-10
#define P ((exp(1.0)-1.0)/(1+exp(1.0)-exp(-1.0)))
#define S (1+exp(1.0)-exp(-1.0))
#define NUM 10000

double F_f(double(*f)(double x),double y);
double F1(double x);
double F2(double x);
void func_hw4(int N , const char *p);

#endif //HOMEWORK_6_F_FUNCTION_H
