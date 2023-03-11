#include <iostream>
#include <cmath>
#include "Sch.h"
#include "Sample_solution.h"

int Read(int a[],int b[]){                  //用于读取data.txt文件，获取其中的能量与intensity数据
    FILE *fp= fopen("./data_change.txt","r");       //打开文件，注意到此处将头行汉字手动删去
    int i=0,s=0;
    while (!feof(fp)){                          //文件结尾
        fscanf(fp,"%d\t%d",&a[i],&b[i]);        //取数据
//        std::cout<<a[i]<<"\t"<<b[i]<<std::endl;
        s=s+b[i];                               //记录总数：396002
        i++;
    }
    fclose(fp);
    return s;
}
void Probability(int b[], double P[], int s){       //计算各个柱体对应概率
    auto *p=(double*) malloc(num*sizeof(double));
    for (int i = 0; i < num-1; ++i) {
        p[i]=1.0*b[i]/s;                            //算p
        if (i==0) P[i]=p[i];
        else P[i]=P[i-1]+p[i];                      //算P
    }
    free(p);
}

int main() {
    int a[num]={0},b[num]={0};
    double P[num]={0.0};
    int s;
    int N;
    std::cout<<"Please input N:";
    std::cin>>N;
    s=Read(a,b);
//    std::cout<<s;
    Probability(b,P,s);
    Direct_sample(N,P,a);                   //直接抽样
    Acceptance_rejection_sample(N,P,a);     //舍选抽样
    return 0;
}