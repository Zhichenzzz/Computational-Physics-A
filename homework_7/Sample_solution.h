//
// Created by HUAWEI on 2022/10/15.
//
#include <iostream>
#include <cmath>
#include "Sch.h"
#ifndef HOMEWORK_7_SAMPLE_SOLUTION_H
#define HOMEWORK_7_SAMPLE_SOLUTION_H
#define num (3013-2900+1)
#define p1 0.55646587               //提前定义好两个分位数
#define p2 0.98880025
#define a1 0.01432316               //提前定义好F(x)在三段内的大小
#define a2 0.0950247726
#define a3 0.00327776

void Direct_sample(int N, double P[], int a[]);
void Acceptance_rejection_sample(int N, double P[], int a[]);

#endif //HOMEWORK_7_SAMPLE_SOLUTION_H
