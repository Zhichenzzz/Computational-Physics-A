#include <iostream>
#include "Sch.h"
#include "exp_distribution.h"
#include "Poisson.h"
#include "Lorentz.h"
#include "F_function.h"
int main() {
    int select;
    //输入1开始抽样
    cout<<"Put in 1 means running while put in 0 means break:";
    cin>>select;
    if(select) {
        //每种函数取不同的N值
        Exp(2,"exp_2.txt");
        Exp(5,"exp_5.txt");
        Exp(10,"exp_10.txt");
        Exp(100,"exp_100.txt");
        Exp(1000,"exp_1000.txt");
        poisson_distribution(2,"poi_2.txt");
        poisson_distribution(5,"poi_5.txt");
        poisson_distribution(10,"poi_10.txt");
        poisson_distribution(100,"poi_100.txt");
        poisson_distribution(1000,"poi_1000.txt");
        lorentz(2, "lorentz_2.txt");
        lorentz(5, "lorentz_5.txt");
        lorentz(10, "lorentz_10.txt");
        lorentz(100, "lorentz_100.txt");
        func_hw4(2,"func_hw4_2.txt");
        func_hw4(5,"func_hw4_5.txt");
        func_hw4(10,"func_hw4_10.txt");
        func_hw4(100,"func_hw4_100.txt");
    }
    return 0;
}
