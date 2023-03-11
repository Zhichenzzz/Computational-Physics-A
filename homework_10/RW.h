//
// Created by HUAWEI on 2022/10/23.
//

#ifndef HOMEWORK_10_RW_H
#define HOMEWORK_10_RW_H
#include <iostream>
#include <cmath>
#include "Sch.h"
//向右运动的概率公式
double probability(double w, double a, double t){
    return (0.5+0.5*a*sin(w*t));
}
//通过与生成的随机数比较，确定每一步粒子向什么方向运动
double step_RW(double p, double m){
    if (m>=p&&m<=1) return -0.5;        //if m>=p&&m<=1 返回步长-0.5
    else if(m>=0&&m<p) return 0.5;      //if m>=p&&m<=1 返回步长0.5
    else return 0;
}

//记录单个粒子的运动
void write_RW_xy(int TIME, double w[], double a[]){
    FILE *fp= fopen("RW_xy_try.txt","w");
    int z1=Sch::Seed();
    double x=0,y=0;
    Sleep(5000);
    int z2=Sch::Seed();
//    double m1=0.0,m2=0.0;
    for (int i = 0; i < TIME; ++i) {
        x+= step_RW(probability(w[0],a[0],i),1.0*z1/M);     //随机力步长加上正弦力、粘滞力
        y+= step_RW(probability(w[1],a[1],i),1.0*z2/M);     //随机力步长加上正弦力、粘滞力
        fprintf(fp,"%lf,%lf,%d\n",x,y,i);
        z1=Sch::Sch_16807(z1);
        z2=Sch::Sch_16807(z2);
    }

}
//计算速度的自相关系数，N为系综粒子数，TIME为运动的时间
void C_v(int N, int TIME, double w[], double a[])
{

    int z1=Sch::Seed(),x=0;
    Sleep(5000);
    int z2=Sch::Seed(),y=0;
    FILE *fp= fopen("RW_Cv_try.txt","w");
    FILE *fp1= fopen("random_num.txt","r");
    double *v0,*u0,*C,*v,*u;
    double sum=0;
    v0=(double*)malloc(sizeof(double) * N);         //v0，u0为粒子x，y方向初速度；v，u为粒子之后时刻的两个方向速度
    u0=(double*)malloc(sizeof(double) * N);
    v=(double*)malloc(sizeof(double) * N);
    u=(double*)malloc(sizeof(double) * N);
    C=(double*)malloc(sizeof(double) * TIME);
    for (int i = 0; i < N; ++i)
    {
        fscanf(fp1,"%lf",&v0[i]);       //从生成的随机数txt文件中读取，作为初始速度值
        fscanf(fp1,"%lf",&u0[i]);
        v[i]=v0[i];
        u[i]=u0[i];
    }
    for (int t = 0; t < TIME; ++t)      //每个时刻的运动
    {
        sum=0.0;                        //置零处理
        for (int i = 0; i < N; ++i)
        {
            if(t==0)
            {
                sum+=v[i]*v0[i]+u[i]*u0[i];     //v(0)v(0)+u(0)u(0)
                continue;
            } else
            {

                v[i]=v[i]+ step_RW(0.5,1.0*z1/M)+a[0]*sin(w[0]*t)-0.25*v[i]; //v(0)v(t)
                u[i]=u[i]+ step_RW(0.5,1.0*z2/M)+a[1]*sin(w[1]*t)-0.25*u[i]; //u(0)u(t)
                sum+=v[i]*v0[i]+u[i]*u0[i];
                z1=Sch::Sch_16807(z1);
                z2=Sch::Sch_16807(z2);
            }
        }
        C[t]=sum/N;                     //  <v(0)v(t)+u(0)u(t)>
        fprintf(fp,"%d,%lf\n",t,C[t]);
    }
    free(v0);           //释放内存空间
    free(u0);
    free(v);
    free(u);
    free(C);
}
#endif //HOMEWORK_10_RW_H
