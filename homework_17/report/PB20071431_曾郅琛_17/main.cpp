#include "Particle.h"
#include "Sandbox_boxcounting.h"
#include <chrono>
#include <iostream>
using namespace std;
using namespace chrono;
typedef std::chrono::high_resolution_clock Clock;
int main() {

/*********以下为DLA************/
//    auto t1 = Clock::now();//计时开始
//    Set_initial();                      //初始化
//    Continuous_Walking();               //运行随机行走
//    auto t2 = Clock::now();//计时结束
//    std::cout <<"DLA"<<":"<<std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()/1e+9<<"s"<<  '\n';     //单位s
//    Print_unfree_particle();            //打印到txt

/*********以下为DLA进行网格化************/
    int num[240][240]={0};
    //此为DLA文件
    FILE *fp= fopen("DLA_10000.txt","r");
    //网格化
    FILE *fp2= fopen("dot.txt","w");
    int temp1=0,temp2=0;
    while(!feof(fp)){
        fscanf(fp,"%d,%d\n",&temp1,&temp2);
        num[temp1+119][temp2+119]=1;                //将中心平移到119，119
    }
    fclose(fp);
    for (auto & i : num) {
        for (int j : i) {
            fprintf(fp2,"%d\t",j);          //打印到文件
        }
        fprintf(fp2,"\n");                          //换行
    }
    fclose(fp2);


/*********以下为Box Counting && Sandbox************/
    printf("Box Counting: \n");
    Box_counting(num);
    printf("Sandbox: \n");
    Sandbox(num);
    return 0;
}
