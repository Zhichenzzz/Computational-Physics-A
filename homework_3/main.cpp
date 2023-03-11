#include <iostream>
#include "vector"
#include "Sch.h"
#include "cmath"
#include "time.h"
void Generate_pot(char const* p){                           //利用生成的theta和phi，计算坐标值(x,y,z)
    double x,y,z,theta,phi;
    FILE *fp1 = fopen("theta.txt","r");
    FILE *fp2 = fopen("phi.txt","r");
    FILE *f = fopen(p,"w");                     //按行存入坐标值(x,y,z)

    while( (fgetc(fp1)) != EOF&&(fgetc(fp2)) != EOF){
        fscanf(fp1,"%lf",&theta);
        fscanf(fp2,"%lf",&phi);
        x= sin(theta)* cos(phi);                            //球坐标系下坐标(x,y,z)
        y= sin(theta)* sin(phi);
        z= cos(theta);
        fprintf(f,"%lf,%lf,%lf\n",x,y,z);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(f);
}
int main() {
    Sch s;
    int N;
    cout<<"please input N: ";
    cin>>N;                                             //输入N
    s.Cos(N,"theta.txt");                        //生成theta.txt
    Sleep(5000);                            //sleep一段时间非常非常非常重要！！具体在报告解释
    s.Phi(N,"phi.txt");                          //生成phi.txt
    Generate_pot("R_Generate.txt");                     //利用theta，phi生成坐标值
    return 0;
}
