#include "Particle.h"
#include "DBM.h"
#include <chrono>
#include <iostream>
using namespace std;
using namespace chrono;
typedef std::chrono::high_resolution_clock Clock;
int main() {

/*********以下为DLA************/
    auto t1 = Clock::now();//计时开始
    Set_initial();                      //初始化
    Continuous_Walking();               //运行随机行走
    auto t2 = Clock::now();//计时结束
    std::cout <<"DLA"<<":"<<std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()/1e+9<<"s"<<  '\n';     //单位s
    Print_unfree_particle();            //打印到txt


/*********以下为DBM************/
    auto t3 = Clock::now();//计时开始
    ini_G();                            //初始化
    MC_Laplace();                       //DBM求解
    auto t4 = Clock::now();//计时结束
    std::cout <<"DBM"<<":"<<std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count()/1e+9<<"s"<<  '\n';     //单位s



    return 0;
}
