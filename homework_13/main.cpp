#include <iostream>
#include <cmath>
#include "Sch.h"
//p=f(x)时，计算P[j]T[j][i]/P[i]T[i][j]
double function1(double a,double b, double alpha, double beta, double gamma)
{
    double tmp1=pow((a/b),(alpha-1));
    double tmp2=exp((b-a)/beta)*exp((a-b)/gamma);
    return tmp1*tmp2;
}
//p=f(x)*(x-ab)^2时，计算P[j]T[j][i]/P[i]T[i][j]
double function2(double a,double b, double alpha, double beta, double gamma)
{
    double tmp1=pow((a/b),(alpha-1));
    double tmp2=exp((b-a)/beta)*exp((a-b)/gamma);
    double tmp3= pow((a-alpha*beta)/(b-alpha*beta),2);
    return tmp1*tmp2*tmp3;
}
//此函数完成对第一个权重函数的处理
void Metropolis_Hasting_Sampling_1(double alpha, double beta, double gamma, int N)
{
    FILE* fp1 = fopen("results_gamma_error_try.txt", "a"); //打开文件
//    FILE* fp2 = fopen("results_N_error_try.txt", "a"); //打开文件

    int num=0;                  //用于计数抽样成功数值，得到抽样效率
    int z=Sch::Seed();          //生成初始种子值
    double R0=1.0*z/M;
    double R1;           //R0为[0, 1]随机数
    double x0=1;                //初始值x0=1
    double sam=0,r=0,I=0;
    for (int i = 0; i < N; ++i) {
        z=Sch::Sch_16807(z);
        R0=1.0*z/M;             //R0为[0, 1]
        sam=-1*gamma*log(R0);   //抽样
        r= function1(sam,x0,alpha,beta,gamma);      //计算P[j]T[j][i]/P[i]T[i][j]
        z=Sch::Sch_16807(z);
        R1=1.0*z/M;                     //用于舍选的随机数
        if (R1 < min(1.0,r))
        {
            x0=sam;                                 //抽取该点
            num++;
        }
        else
        {
            x0=x0;
        }
        if (i>=0.2*N)                                   //开始有一定的热化效应，等预热完毕开始计算
        {
            I = I+ pow((x0-alpha*beta),2);          //计算第一种情况的积分值
        }

    }
    double Int=I/(0.8*N);
    double error=abs(alpha*beta*beta-Int);            //误差
    double accuracy=num/(0.8*N);            //精度
    cout<<"When gama="<<gamma<<", M_H_P results:"<<Int<<", error="<<error<<", efficiency="<<accuracy<<endl;
//    fprintf(fp1,"gamma\t \terror\t \taccuracy");
    fprintf(fp1,"%f,%lf,%lf\n",gamma,error,accuracy);
//    cout<<"When N="<<N<<", M_H_P results:"<<Int<<", error="<<error<<", efficiency="<<accuracy<<endl;
//    fprintf(fp2,"N\t \terror\t \tefficiency");
//    fprintf(fp2,"%d,%lf,%lf\n",N,error,accuracy);

}
//此函数完成对第二个权重函数的处理
void Metropolis_Hasting_Sampling_2(double alpha, double beta, double gamma, int N)
{
    FILE* fp1 = fopen("results_gamma_error_try.txt", "a"); //打开文件
//    FILE* fp2 = fopen("results_N_error_try.txt", "a"); //打开文件

    int num=0;                  //用于计数抽样成功数值，得到抽样效率
    int z=Sch::Seed();          //生成初始种子值
    double R0=1.0*z/M;
    double R1;           //R0为[0, 1]随机数
    double x0=1;                //初始值x0=1
    double sam=0,r=0,I=0;
    for (int i = 0; i < N; ++i) {
        z=Sch::Sch_16807(z);
        R0=1.0*z/M;             //R0为[0, 1]
        sam=-1*gamma*log(R0);   //抽样
        r= function2(sam,x0,alpha,beta,gamma);      //计算P[j]T[j][i]/P[i]T[i][j]
        z=Sch::Sch_16807(z);
        R1=1.0*z/M;                     //用于舍选的随机数
        if (R1 < min(1.0,r))
        {
            x0=sam;                                 //抽取该点
            num++;                                  //抽取成功！
        }
        else
        {
            x0=x0;
        }
        if (i>=0.2*N)                                   //开始有一定的热化效应，等预热完毕开始计算
        {
            /***************计算第二种p(x)积分值******************/
            if(x0-alpha*beta!=0)
                I = I+ pow((x0-alpha*beta),-2);
            else
                i--;                                    //此种情况为防止分母为0
        }

    }
    double Int=1/(I/(0.8*N));                       //第二种情况下积分值
    double error=abs(alpha*beta*beta-Int);                        //误差
    double accuracy=num/(0.8*N);                    //效率
    cout<<"When gama="<<gamma<<", M_H_P results:"<<Int<<", error="<<error<<", efficiency="<<accuracy<<endl;
//    fprintf(fp1,"gamma\t \terror\t \taccuracy");
    fprintf(fp1,"%f,%lf,%lf\n",gamma,error,accuracy);
//    cout<<"When N="<<N<<", M_H_P results:"<<Int<<", error="<<error<<", efficiency="<<accuracy<<endl;
////    fprintf(fp2,"N\t \terror\t \taccuracy");
//    fprintf(fp2,"%d,%lf,%lf\n",N,error,accuracy);

}
int main() {
    /******运行时，注意要更改函数为1or2***************************/
    /************************探讨gamma与error关系*******************************/
    for (int i = 0; i < 20; ++i) {              //0~2每0.1取一个点
        double gamma=0.1*i;
        Metropolis_Hasting_Sampling_1(2,1,gamma,1000000);
    }
    for (int i = 2; i <= 200; ++i) {            //2~200每1取一个点
        double gamma=i;
        Metropolis_Hasting_Sampling_1(2,1,gamma,1000000);
    }

    /************************探讨N与error关系*******************************/

//    for (int i = 2; i < 9 ; ++i) {            //N从100到10^8
//        int N=pow(10,i);
//        Metropolis_Hasting_Sampling_1(2,1,2.,N);          //选取gamma=3.0
//    }


    return 0;
}

