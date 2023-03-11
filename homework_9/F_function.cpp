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
//对作业4的函数抽样
void func_hw4(int N , const char *p) {      //传入N及文件名
    FILE *fp= fopen(p,"w");
    Sleep(5000);
    int z=Sch::Seed();
    double xi,x,sum=0.0;
    for (int i = 0; i < NUM; ++i) {
        sum=0.0;
        for (int j = 0; j < N; ++j) {
            z=Sch::Sch_16807(z);
            xi=1.0*z/M;
            if(xi<P){                            //若随机数小于F(0),则在第一段取值
                x= F_f(F1,xi);              //调用求反函数函数
            }
            else{                               //若随机数大于F(0),则在第二段取值
                x= F_f(F2,xi);              //调用求反函数函数
            }
            sum=sum+x;
        }
        fprintf(fp,"%lf\n",1.0*sum/N);          //<x>=(x_1+x_2+...)/N
    }

}