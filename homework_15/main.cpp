#include <iostream>
#include <cmath>
#include "Sch.h"
#include <chrono>
#define N_total 1e+7
#define I1 1.56189                      //理论值
#define I2 1.68247
#define I3 1.94783
using namespace std::chrono;
typedef std::chrono::high_resolution_clock Clock;

//define Hamilton function
double Hamilton_F(double x,double y){
    return -2*(pow(x,2)+ pow(y,2))+0.5*(pow(x,4)+ pow(y,4))+0.5* pow((x-y),4);
}
//细致平衡条件
double function1(double x,double y, double xt, double yt, double beta)
{
    double dE= Hamilton_F(xt,yt)- Hamilton_F(x,y);      //ΔE
    return exp(-beta*(dE));
}
double Metropolis_Hasting_Sampling(double *x, double *y,double delta,double beta,int N,const char*p)
{
    FILE *fp= fopen(p,"w");
    int num=0;                  //用于计数抽样成功数值，得到抽样效率
    int z0=Sch::Seed();          //生成初始种子值
    double R0=1.0*z0/M;
    double R1;           //R1为[0, 1]随机数
    double x0=0,y0=0;                //初始值x0=1,y0=1
    double r=0;
    double xt,yt;
    for (int i = 0; i < N; ++i) {
        z0=Sch::Sch_16807(z0);
        R0=1.0*z0/M;             //R0为[0, 1]
        xt=(R0-0.5)*delta+x0;       //试探点横坐标

        z0=Sch::Sch_16807(z0);
        R0=1.0*z0/M;             //R0为[0, 1]
        yt=(R0-0.5)*delta+y0;       //试探点纵坐标

        r= function1(x0,y0,xt,yt,beta);      //计算P[j]/P[i]
        z0=Sch::Sch_16807(z0);
        R1=1.0*z0/M;                     //用于舍选的随机数
        if (R1 < min(1.0,r))            //抽样条件
        {
            x0=xt;                      //抽取该点
            y0=yt;
            *x=xt;                      //指针指向
            *y=yt;
            x++;                        //地址加加
            y++;
            if (i>=0.5*N_total)         //当开始的热化处理后再开始计数
                num++;
        }
        else
        {
            *x=x0;                      //指针指向
            *y=y0;
            x++;                        //地址移位
            y++;
        }
        if (i<5000)                     //只选取前面的马尔科夫链点作为画图点
            fprintf(fp,"%lf,%lf\n",x0,y0);
    }
    return 1.0*num/(0.5*N);             //效率
}
void Print_results(double beta,char*p){
//    FILE *fp= fopen(p,"w");
    double delta=0.5;                     //步长
    double eff;                         //效率
    double sum[3]= {0};             //求和量
    auto *x=(double *)malloc(sizeof(double )*N_total);          //动态数组指针
    auto *y=(double *)malloc(sizeof(double )*N_total);
    auto t1 = Clock::now();                     //计时开始
    eff=Metropolis_Hasting_Sampling(x,y,delta,beta,N_total,p);
    auto t2 = Clock::now();                     //计时结束
    for (int i = 0.5*N_total; i < N_total; ++i) {
        sum[0] += pow(x[i],2);
        sum[1] += pow(y[i],2);
        sum[2] += pow(x[i],2)+pow(y[i],2);
//        fprintf(fp,"%lf,%lf\n",x[i],y[i]);
    }
    /***记录不同β对应值和所用时间、效率***/
    cout <<"When β="<<beta<<", 用时: "<<chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count()/1e+9<<"s"<<", 效率: "<<eff<<endl;     //单位s
    cout<<"<x^2>:"<<sum[0]/(0.5*N_total)<<endl;
    cout<<"<y^2>:"<<sum[1]/(0.5*N_total)<<endl;
    cout<<"<x^2+y^2>:"<<sum[2]/(0.5*N_total)<<endl;
    free(x);
    free(y);                                        //释放内存
//    fclose(fp);
}
int main() {
    /******对不同β得到结果**********/
    Print_results(0.2,"beta=0.2_00.txt");
    Print_results(1.0,"beta=1.0_00.txt");
    Print_results(5.0,"beta=5.0_00.txt");
    return 0;
}
