#include <iostream>
#include "Sch.h"
#include "F_function.h"
int main() {
    Sch s;
    int k;                              //输入数据规模
    cout<<"Please input the number：";
    cin>>k;
    FILE *fp= fopen("Gauss_dot_10000000.txt","w");      //此处需要与数据规模对照修改
    int num=0,sum=0;
    int z1=s.Sch_16807(s.Seed());               //生成种子用于抽样分布函数
    Sleep(5000);
    int z2=s.Sch_16807(s.Seed());               //生成种子用于对Gauss函数抽样
    double x1,x2,x,y;
    while (num<k) {
        x=F_f(1.0*z1/M);                        //二分法计算反函数，得到x值
        y=1.0*z2/M*1.25/(1+ pow(x,4));          //在y方向随机数，产生Lorentz函数的分布
        if(y<=std::exp(-0.5*x*x)){                  //若产生点在给定Gauss分布下，则选取
            num++;                                   //计数
            fprintf(fp,"%lf,%lf\n",x,y);            //打印在txt文件
        }
        sum++;                                  //用于计算效率
        z1=s.Sch_16807(z1);
        z2=s.Sch_16807(z2);
    }

    cout<<"Number="<<num<<",efficiency="<<double (1.0*num/sum)<<endl;

    return 0;
}
