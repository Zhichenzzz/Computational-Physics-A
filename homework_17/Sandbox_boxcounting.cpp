//
// Created by HUAWEI on 2022/12/18.
//
#include "Sandbox_boxcounting.h"
#include <iostream>
#include <cmath>

using namespace std;

void Box_counting(const int p[][240])  //box_counting
{
    FILE *fp= fopen("Boxcounting.txt","w");
    int e[]={3,4,5,6,8,10,12,15,16,
             20,24,30,40,48,60,80,120,240};     //对240*240的像素点进行分box，其约数作为分割
    
    for (int i : e)                 //对每个e[i]元素进行计算
    {
        int N = 240/i;
        int number = 0;
        for ( int j = 0; j < i; j++){	//对行遍历
            for (int k = 0; k < i; k++){ //对列遍历
                int sum = 0;                    //每次计算前置零
                for (int m = 0; m <= N; m++){
                    for (int n = 0; n <= N; n++){       //对每个box计算有无点
                        sum+=p[j*N+m][k*N+n];
                    }
                }
                if (sum>0){             //有！
                    number++;
                }
            }
        }
        double D=log(number)/log(i);             //分形维数
        cout<<i<<","<<number<<","<<D<<endl;      //打印
        fprintf(fp,"%d,%d\n",i,number);
    }

}


void Sandbox(const int p[][240])  //Sandbox
{
    FILE *fp= fopen("Sandbox.txt","w");
    for (int i = 1; i <= 10; i++)       //边长10,20,30,40,50,60,70,80,90,100正方形内的点数
    {
        int number = 0;                 //每次前置零
        for (int j = 120-5*i; j <= 120+5*i ; j++){      //小边框
            for (int k = 120-5*i; k <= 120+5*i; k++){
                if (p[j][k]==1){
                    number++;               //有！
                }
            }
        }
        int l=10*i;     //边长
        cout<<l<<","<<number<<","<<log(number)/log(l)<<endl;        //打印
        fprintf(fp,"%d,%d\n",l,number);
    }
}