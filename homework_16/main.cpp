#include <iostream>
#include <cmath>
#include "Sch.h"
#define PI 3.141592654      //pi
#define Total_num 2e+4      //总的迭代次数
#define begin_num 1000      //舍去的迭代
#define accuracy 10
double function(double lambda, double x){       //迭代函数
    return lambda * sin(PI*x);
}
int main() {
    double start=0.865, end=0.8655;             //lambda的取值范围
    double step=0.00001;                        //lambda的步长
    int z=Sch::Seed();
    double x0=1.0*z/M;
//    double x=x0;
    FILE *fp= fopen("results_try_0.865.txt","w");       //打开文件
    for (double lambda = end; lambda > start ; lambda-=step) {          //进行lambda的循环
        for (int j = 0; j < 5; ++j) {                           //此处为了解决初值敏感性的问题，进行多个随机数初值
            z=Sch::Sch_16807(z);
            double x=2.0*z/M-1;                                 //随机数
            for (int i=0; i<Total_num/5; i++)                   //总的迭代
            {
                x=function(lambda,x);               //迭代
                if (i>((Total_num-begin_num)/5-1))              //真正选用的迭代
                {
//                    if(i==((Total_num-begin_num)/5-1)) x0=x;
//                    if(abs(x0-x)<)
                    printf("%f,%f\n", lambda, x);       //打印
                    fprintf(fp,"%f,%f\n",lambda,x);         //写文件
                }
            }
        }

    }
    return 0;
}
