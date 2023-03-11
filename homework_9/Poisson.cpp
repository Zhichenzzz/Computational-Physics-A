//
// Created by HUAWEI on 2022/10/16.
//

#include "Poisson.h"
//阶乘函数
int fac(int k){
    if(k<0) return -1;
    if(k==0) return 1;
    int l = 1;
    for (int i = 1; i <= k; ++i) {
        l = l * i;
    }
    return l;
}
//泊松分布概率质量函数
double poisson_pf(int k){
    double el=exp(-2);
    return (pow(2,k)/fac(k)* el);
}
//泊松分布累积分布函数
double poisson_PF(int k){
    if(k<0) return 0;
    else{
        double l=0;
        for (int i = 0; i <= k; ++i) {
            l=l+ poisson_pf(i);
        }
        return l;
    }
}
//泊松函数抽样，传入N以及文件名
void poisson_distribution(int N,const char *p){
    FILE *f1= fopen(p,"w");
    int z=Sch::Seed(),x=0,temp,j;
    double xi;
    for (int i = 0; i < NUM; ++i) {             //每个独立分布的点数
        x=0;
        temp=0;
        for (int k = 0; k < N; ++k) {           //遍历每个独立分布
            xi=1.0*z/M;
            for (j = 0; j < 15; ++j) {                  //当j在15以外，可以认为取j=15
                if(xi> poisson_PF(j-1)&&xi<= poisson_PF(j)){     //判断j的范围
                    temp=j;                 //记录j，即为抽样点
                    break;                  //退出循环进入下一个独立分布
                }
            }
            if(j==15) temp=15;          //j≥15，均认为j=15
            x=x+temp;
            z=Sch::Sch_16807(z);        //更新随机数
        }
        fprintf(f1,"%lf\n",1.0*x/N);        //打印
    }
}