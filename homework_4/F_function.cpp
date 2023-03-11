//
// Created by HUAWEI on 2022/10/8.
//

#include "F_function.h"


//利用二分法求解反函数值
double F_f(double(*f)(double x),double y){
//    double x;
    double l=-1.0, r=1.0,m=0.0;
//  判断循环是否可以停止
    while (std::abs(y-f(m))>accuracy){
        if(f(l)>f(r)){
            if(y>f(m))  r=m;
            else l=m;
        }
        else
        {
            if (y > f(m)) l = m;
            else r = m;
        }
        m = (l + r) / 2.0;
    }
    return m;
}

//当x<0时，取的F1函数
double F1(double x){
    double fx;
    fx= exp(1.0)- exp(-x);
    fx= fx/S;
    return fx;
}
//当x大于0时，取的F2函数
double F2(double x){
    double fx;
    fx= x+exp(1.0)- exp(-x);
    fx= fx/S;
    return fx;
}

