//
// Created by HUAWEI on 2022/10/15.
//

#include "Sample_solution.h"
void Direct_sample(int N, double P[], int a[]){                 //直接抽样法
    FILE *fp= fopen("direct_sample_100000.txt","w"); //抽取数据大小为100000的能量值
    Sch sch;                                                    //随机数生成器
    int z=sch.Seed();
    double x;
    for (int i = 0; i < N; ++i) {
        x=1.0*z/M;                                              //[0,1]随机数
        for (int j = 0; j < num-1; ++j) {                       //遍历概率累计函数P(n)，找到满足P(j-1)<x≤P(j)的值
            if (x>P[j]) continue;                               //继续循环
            else{
                fprintf(fp,"%d\n",a[j]);
                break;                                          //找到！退出循环
            }
        }
        z=sch.Sch_16807(z);                                     //更新随机数
    }
    fclose(fp);
}
void Acceptance_rejection_sample(int N, double P[], int a[]){           //舍选抽样
    FILE *fp= fopen("Acceptance_rejection_sample_100000.txt","w");  //打开指定文件存数据
    Sch sch;
    int z1=sch.Seed();                                  //生成第一组随机数
    Sleep(5000);                    //睡眠一会，避免两组随机数重复
    int z2=sch.Seed();                      //生成第二组随机数
    double x1,x2,y,p;
    int NUM=0,SUM=0;
    while (NUM<N){                      //抽选N个数据
        x1=1.0*z1/M;
        x2=1.0*z2/M;
        if (x1>0&&x1<=p1){              //第一段抽样函数
            y=168.93185*x1+2900;
            p=a1;
        }
        else if(x1>p1&&x1<=p2){         //第二段抽样函数
            y=25.431301*x1+2979.8723;
            p=a2;
        }
        else if(x1>p2&&x1<=1){          //第三段抽样函数
            y=731.9973*x1+2281.1021;
            p=a3;
        }
        int k=floor(y),l=ceil(y);               //Lagrange插值计算
        double Pro1=(P[k-2900]-P[k-2900-1]),Pro2=(P[l-2900]-P[l-2900-1]);   //计算概率
        double diff=Pro1*(y-l)/(k-l)+Pro2*(y-k)/(l-k);      //Lagrange插值
        if(x2*p<diff){                      //舍选过程
            fprintf(fp,"%lf\n",y);      //存数据
            NUM++;
        }
        SUM++;
        z1=sch.Sch_16807(z1);
        z2=sch.Sch_16807(z2);           //更新随机数
    }
    fclose(fp);
    std::cout<<1.0*NUM/SUM<<endl;           //打印舍选效率
}

