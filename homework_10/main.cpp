#include <iostream>
#include "RW.h"

int main() {
//    Sch::Save_Random(Sch::Seed(),100000,"random_num.txt");
    double w[2]={0.02,0.05},a[2]={0.25,0.5};    //初始频率与振幅
//    int N=50000,TIME=10000;                  //系综粒子数、时间
    int N,TIME;
    cout<<"Please input number of particles:";
    cin>>N;
    cout<<"Please input time:";
    cin>>TIME;
    C_v(N,TIME,w,a);                        //速度自相关函数
    write_RW_xy(TIME,w,a);                  //正弦电场随机行走

    return 0;
}
