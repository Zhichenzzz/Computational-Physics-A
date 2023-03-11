#include <iostream>
#include <cmath>
#include "Integration.h"
//定义的单变量函数
double f_single(double x){
    return sqrt(x*x+ 2*sqrt(x));
}
//定义的多变量函数
double f_mutiple(double x,double y,double z,double u,double v){
    return (5 + x*x - y*y + 3*x*y - z*z + u*u*u - v*v*v);
}
int main() {
    //计算不同大小数据量的结果
    for (int i = 2; i < 9; ++i) {
        int N=pow(10,i);
        single_integration(N,f_single,0,5);
        multiple_integration(N,f_mutiple,0,7/10.0,0,4.0/7,0,9.0/10,0,2,0,13.0/11);

    }
    return 0;
}
