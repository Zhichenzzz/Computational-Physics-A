//
// Created by HUAWEI on 2022/10/16.
//

#include "exp_distribution.h"
//指数函数的抽样
void Exp(int N,const char *p){
    FILE *f1= fopen(p,"w");     //存文件
    Sleep(5000);            //休眠
    int z=Sch::Seed();
    double xi,x,sum=0.0;
    for (int i = 0; i < NUM; ++i) {         //每个独立同分布抽取点数
        sum=0.0;                            //初始化总和
        for (int j = 0; j < N; ++j) {       //对每个指数分布抽样
            z=Sch::Sch_16807(z);            //更新随机数
            xi=1.0*z/M;
            x=-2*log(xi);                   //直接抽样
            sum=sum+x;					//求出独立变量的总和x_1+x_2+...
        }
        fprintf(f1,"%lf\n",1.0*sum/N);          //<x>=(x_1+x_2+...)/N
    }
}