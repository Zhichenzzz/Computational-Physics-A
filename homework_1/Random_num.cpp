//
// Created by HUAWEI on 2022/9/11.
//
#include "Sch.h"
#include <fstream>
#include <sstream> //字符串转换
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

// 计算x^k的平均值
double xk_average(int k, int N, char const p[]){
    ifstream fp;
    fp.open(p,ios::in);
    string line;
    double s=0;
    if(fp) // 有该文件
    {
        while (getline(fp,line))
        {
            istringstream sin(line);
//            string info;
//            string Waypoints;
//            while (getline(sin, info,","))
//            {
//                //
//                Waypoints=info;
//            }
            string Waypoints;
            getline(sin,Waypoints);
//          cout << "Waypoints:" << Waypoints << endl;
            double x;
            stringstream sx;        //transform string to double
            sx << Waypoints;
            sx >> x;
            s = s + pow(x,k);   //求和
        }
    }
    else cout <<"no such file" << endl;
    fp.close();
    return s/N;                     //求平均值
}
//验证独立性
double C_l(int l, int N, char const p[]){
    double b = pow(xk_average(1,N,p),2);  //由xk_average()函数可以直接计算出来，直接调用
    double c = xk_average(2,N,p);               //同上
    double a;
    ifstream fp;
    fp.open(p,ios::in);
    string line;
    double s=0,x=0;
    int i=0;
    auto* tempArray = (double*)malloc(l * sizeof(double));      //创建动态数组，存储l个数据
    if(fp) // 有该文件
    {
        for(i=0;i<l;i++)                        //先把前l个存起来
        {
            getline(fp,line);
            istringstream sin(line);
            string Waypoints;
            getline(sin,Waypoints);
            stringstream sx;            //transform string to double
            sx << Waypoints;
            sx >> x;
            tempArray[i]=x;
        }
        for (int j = l; j < N; j++) {           //对于后面的则不断更改数组对应元素值
            getline(fp,line);
            istringstream sin(line);
            string Waypoints;
            getline(sin,Waypoints);
            stringstream sx; //transform string to double
            sx << Waypoints;
            sx >> x;
            s += x * tempArray[(i - l)%l];          //累加
            tempArray[i%l] = x;                     //前一个数记在数组，以供后面用
        }
    }
    else cout <<"no such file" << endl;
    free(tempArray);                                //释放内存
    fp.close();
    a=s/N;
    return (a-b)/(c-b);                             //C(l)公式


}
int main(){
    Sch s;

    int N[7]={100,1000,10000,100000,500000,1000000,10000000};   //不同N大小
    int k[4]={1,2,4,7};                                                     //不同k取值
    double m,n;
    char const *p[7]={"N=100.txt","N=1000.txt","N=10000.txt",\
        "N=100000.txt","N=500000.txt","N=1000000.txt","N=10000000.txt"};    //存入读取文件名
    //用于生成随机数，存入文件后注释
    for (int i:N) {
        int seed = s.Seed();
        char *str;
        sprintf(str, "N=%d.txt", i);                                                        //对应文件名
        cout<<"生成随机数中……"<<endl;
        s.Save_Random(seed,i,str);                                                  //生成随机数

    }


//  cout<<p[0];
    cout<<"均匀性验证："<<endl;                                                               //均匀性检验
    for (int i = 0; i < 7; i++) {
        for (int j : k) {
            m = xk_average(j, N[i], p[i]);
            cout <<"when k="<<j<< ",N="<<N[i]<<", <x^k>: "<<m<<endl;
            cout << "   <x^k>-1/k+1: " <<m-1.0/(j+1)<<endl;
//          cout << "   |<x^k>-1/k+1|*sqrt(N): "<<(m-1.0/(j+1)) * sqrt(N[i])<<endl;         //不知道为啥，这句加上去程序就会寄www
        }
    }
    cout<<"独立性验证："<<endl;                                                           //独立性检验
    for (int i = 1; i < 6; ++i) {
        n = C_l(i,N[6],p[6]);
        cout <<"when l="<<i<< ", N=1e7, "<<"C(l) = "<<n<<endl;
    }


    return 0;
}