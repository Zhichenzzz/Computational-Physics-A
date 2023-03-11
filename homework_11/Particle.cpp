//
// Created by HUAWEI on 2022/11/2.
//

#include "Particle.h"
#define PI 3.14159265359                    //PI
#define NUM_PARTICLE 2000                   //总共生成的点数
#define NUM_WALKING 500                     //每次行走的粒子数

//定义全局变量，unfree_Particle为最终黏在一起的粒子，free_Particle为正在运动的粒子
Particle unfree_particle[NUM_PARTICLE];
Particle free_particle[NUM_WALKING];

int now_unfree=1;           //当前时刻黏在一起的粒子数
int now_free=0;             //当前时刻自由粒子数
int circle=40;              //设定一个可以变化大小的圆半径
int z=Sch::Seed();          //随机数初始值作为随机行走步长

//随机行走
void Rdm_walk(Particle *part)
{
    z=Sch::Sch_16807(z);
    double k=1.0*z/M;
    if (k>=0&k<0.25)       {part->x++;}         //上下左右运动，概率相同，每次方向由生成随机数确定
    else if(k>=0.25&&k<0.5)   {part->x--;}
    else if(k>=0.5&&k<0.75)   {part->y++;}
    else if(k>=0.75&&k<=1)   {part->y--;}

}
//判断能否相碰，若两个粒子距离在1以内就可以碰在一起了
bool if_collision(Particle P1, Particle P2) {
    float a=(P1-P2).length();
    if (a<=1) return TRUE;
    else return FALSE;
}
//从圆边界生成均匀随机数点，向四周出发
void Circle_particle(Particle *P)
{
    z=Sch::Sch_16807(z);
    float ran=1.*z/M;
    P->x=circle* cos(2*PI*ran);         //格点直接舍入float为int存入x,y坐标
    P->y=circle* sin(2*PI*ran);
}
//正方边界
void Square_particle(Particle *P)
{
    z=Sch::Sch_16807(z);
    float ran=1.*z/M;
    P->x=2*circle*(2*ran-1);
    z=Sch::Sch_16807(z);
    ran=1.*z/M;
    P->y=2*circle*(2*ran-1);
}
//开始设置的kernel，后来发现似乎没有必要了
void Set_kernal()
{
    unfree_particle[0].x=0,unfree_particle[0].y=0;
    unfree_particle[1].x=1,unfree_particle[1].y=0;
    unfree_particle[2].x=0,unfree_particle[2].y=1;
    unfree_particle[3].x=-1,unfree_particle[3].y=0;
    unfree_particle[4].x=0,unfree_particle[4].y=-1;
    now_unfree=5;
}
//对开始的粒子初始化，从r=20位置出发
void Set_initial()
{

    for (int i = 0; i < NUM_WALKING; ++i) {
        Circle_particle(&(free_particle[i]));       //对第i个粒子在边界圆上设置初值
        now_free++;
    }
}
// out of border then set in border
void Border(Particle *P)
{
    if (P->length()>3./2*circle)                //如果粒子运动到1.5r以外，则重新从边界出发设置
        Circle_particle(P);
}
//聚集模型
void if_Diffusion()
{
    if (now_unfree<NUM_PARTICLE)                //当前粒子数小于需要总粒子数，循环继续
    {
        //free particle
        for (int i = 0; i < NUM_WALKING; ++i) {             //遍历每个正在运动粒子
            for (int j = now_unfree-1; j >= 0; --j) {       //准备存储粒子到聚集粒子类数组中
/***************注意到此处是倒序遍历，因为后黏上的粒子放在下标更大的位置，节省时间开销**************/
                if (if_collision(free_particle[i],unfree_particle[j]))      //两者距离
                {
                    unfree_particle[now_unfree]=free_particle[i];       //调用=重载函数，把free粒子信息拷贝到unfree中
                    cout<<unfree_particle[now_unfree].x<<","<<unfree_particle[now_unfree].y<<endl;//打印每次聚集的粒子
                    now_unfree++;                                       //当前聚集粒子++
                    Circle_particle(&(free_particle[i]));              //free的位置在圆边界重新生成一个粒子
//                    Square_particle(&(free_particle[i]));                //正方边界重新生成一个粒子
                    Change_Circle();                                      //进入改变圆半径的函数，判断是否需要改变半径
                    break;
                }
            }
        }
    }
}
//自由粒子的单步随机行走
void free_part_Walking()
{
    for (int i = 0; i < NUM_WALKING; ++i) {
        Rdm_walk(&free_particle[i]);        //随机行走
        Border(&free_particle[i]);              //判断是否到假定边界
    }
}
//持续行走，直到最终总粒子数达到要求
void Continuous_Walking()
{
    while (now_unfree<NUM_PARTICLE) {
        if_Diffusion();                     //判断是否黏在一起
        free_part_Walking();                //随机行走
    }
}
//打印在txt文件中
void Print_unfree_particle()
{
    FILE *fp= fopen("DLA_test.txt","w");
    for (int i = 0; i < now_unfree; ++i) {
        fprintf(fp,"%d,%d\n",unfree_particle[i].x,unfree_particle[i].y);
    }
}

//改变边界范围,加快聚集速度
void Change_Circle()
{
    if (now_unfree%500==0&&now_unfree<1000&&now_unfree>0)      //聚集粒子数为500,1000时更新半径
    {
        circle=circle+10;
        Set_initial();
    }
    if (now_unfree%1000==0&&now_unfree<10000&&now_unfree>=1000)      //每变成1000的倍数更新圆半径
    {
        circle=circle+15;
        Set_initial();
    }
}