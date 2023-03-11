//
// Created by HUAWEI on 2022/10/8.
//
#include "cmath"
#ifndef HOMEWORK_6_F_FUNCTION_H
#define HOMEWORK_6_F_FUNCTION_H
#define accuracy 1e-6
#define P ((exp(1.0)-1.0)/(1+exp(1.0)-exp(-1.0)))
#define S (1+exp(1.0)-exp(-1.0))

double F_f(double(*f)(double x),double y);
double F1(double x);
double F2(double x);

#endif //HOMEWORK_6_F_FUNCTION_H
