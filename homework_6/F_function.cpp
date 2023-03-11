//
// Created by HUAWEI on 2022/10/8.
//

#include "F_function.h"
//利用二分法求解反函数值
double F_f(double y){
//    double x;
    double l=-1.0, r=1.0,m=0.0;

    while (std::abs(y-Lf(m))>accuracy){             //设定精度
        if(Lf(l)>Lf(r)){
            if(y>Lf(m))  r=m;
            else l=m;
        }
        else
        {
            if (y > Lf(m)) l = m;
            else r = m;
        }
        m = (l + r) / 2.0;                  //二分
    }
    return m;
}

//Lorenz函数
double Lf(double x){
    double fx,m= sqrt(2)*x;
    fx= 2*(atan(1+m)- atan(1-m))+ log(1+m+x*x)- log(1-m+x*x);
    fx= 1.25*fx/(4* sqrt(2));
    fx= fx/2.16743246835;                       //归一化处理
    fx= fx+0.5;
    return fx;
}

