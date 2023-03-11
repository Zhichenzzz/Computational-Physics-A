#include <iostream>
#include "Sch.h"
#include "cmath"

void generate_dot(int i){
    double x,y,z,u,v,r2;
    int j=0,i0=i;
    FILE *fp1 = fopen("Random_u.txt","r");                      //生成u随机数
    FILE *fp2 = fopen("Random_v.txt","r");                      //生成v随机数
//    FILE *fp3 = fopen("Random_r.txt","r");
    FILE *f1 = fopen("generate_dot_10000.txt","w");                   //存储(x,y,z)点
    while( i ){
        fscanf(fp1, "%lf", &u);
        fscanf(fp2, "%lf", &v);
        r2 = u * u + v * v;                                                 //r^2值
//        fscanf(fp3,"%lf",&r);
        if (r2 > 1) ;                                               //判断：若r^2>1则重新取样
        else {
            x = 2 * u * pow(1 - r2, 0.5);
            y = 2 * v * pow(1 - r2, 0.5);
            z = 1 - 2 * r2;
            fprintf(f1, "%lf,%lf,%lf\n", x,y,z);                        //计算并返回(x,y,z)
        i--;
        }
        j++;
    }
    fclose(fp1);
    fclose(fp2);
//    fclose(fp3);
    fclose(f1);
    std::cout<<"Marsaglia抽样方法效率："<<(double)i0*1.0/j<<endl;
}

int main() {
    Sch s;
    int N;
    std::cout<<"Please input N:";
    std::cin>>N;
    s.Save_Random(s.Seed(),2*N,"Random_u.txt");
    Sleep(5000);
    s.Save_Random(s.Seed(),2*N,"Random_v.txt");
    generate_dot(N);
    return 0;
}
