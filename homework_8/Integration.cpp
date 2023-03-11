//
// Created by HUAWEI on 2022/10/16.
//

#include "Integration.h"
#include "Sch.h"
//单变量积分,函数指针作为参数
double single_integration(int N, double (*func)(double x),double a,double b){
    int z=Sch::Seed();
    double x = 0;
    double y,s=0.0;
    for (int i = 0; i < N; ++i) {
        x=a+1.0*(b-a)*z/M;              //抽样
        y=func(x);                  //算y
        s+=y;                       //累和
        z=Sch::Sch_16807(z);        //更新随机数
    }
    double r=(b-a)*s/N;             //返回实验结果值
    std::cout<<"When N="<<N<<",The result of single integration is "<<r<<",the error is "<<abs(r-result1)<<endl;    //打印结果
    return r;
}
//多变量积分,函数指针作为参数
double multiple_integration(int N, double (*func)(double x,double y,double z,double u,double v),\
                            double x1,double x2,double y1,double y2,double z1,double z2,\
                            double u1,double u2,double v1,double v2){
        int q[5];
        for (int i = 0; i < 5; ++i) {
            q[i]=Sch::Seed();
            Sleep(1000);            //休眠，避免随机数重复
        }
        double x,y,z,u,v,I;
        double s=0.0;
        for (int i = 0; i < N; ++i) {
            x=x1+1.0*(x2-x1)*q[0]/M;            //对x,y,z,u,v分别抽样随机数
            y=y1+1.0*(y2-y1)*q[1]/M;
            z=z1+1.0*(z2-z1)*q[2]/M;
            u=u1+1.0*(u2-u1)*q[3]/M;
            v=v1+1.0*(v2-v1)*q[4]/M;
            I=func(x,y,z,u,v);
            s+= I;                              //累和
            for (int j = 0; j < 5; ++j) {
                q[j]=Sch::Sch_16807(q[j]);
            }

        }
        double r=(x2-x1)*(y2-y1)*(z2-z1)*(u2-u1)*(v2-v1)*s/N;           //求解积分实验值
        std::cout<<"When N="<<N<<",The result of multiple integration is "<<r<<",the error is "<<abs(r-result2)<<endl;  //打印结果
        return r;
}