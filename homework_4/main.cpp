#include <iostream>
#include "Sch.h"
#include "F_function.h"
#include <cmath>

int main() {
    Sch s;

    int N;
    std::cout<<"Please input N:";
    cin>>N;
    FILE *fp= fopen("px_dot_5000.txt","w");     // 每次需要修改保存文件名
    int z1=s.Sch_16807(s.Seed());

    double x,q,y;
    for (int i = 0; i < N; ++i) {
        q=1.0*z1/M;                         //生成[0,1]随机数
        if(q<P){                            //若随机数小于F(0),则在第一段取值
            x= F_f(F1,q);              //调用求反函数函数
            y=exp(-x);                      //求解p(x)
        }
        else{                               //若随机数大于F(0),则在第一段取值
            x= F_f(F2,q);              //调用求反函数函数
            y=exp(-x)+1;                    //求解p(x)
        }
        fprintf(fp,"%lf,%lf\n",x,y);
        z1=s.Sch_16807(z1);              //生成随机数
    }
//    cout<<double (1.0*num/sum)<<endl;
    return 0;
}
//-1.08372
//2.16743