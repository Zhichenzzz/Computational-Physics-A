//
// Created by HUAWEI on 2022/11/5.
//

#include "DBM.h"
#define accuracy 1e-5       //Laplace方程迭代精度
#define v_para 1       //速率系数
#define l 150          //正方的格点数
#define brown_num 300      //随机游走计算Laplace值的粒子数
#define UPPER_LIMIT 1500    //每个粒子运动的最大位移数
#define BROKEN_NUM 1000    //总共被击穿的点个数
#define phi0 1              //φ0
using namespace std;

float G[l][l]={0};      //每个格点的电势值,记录实际击穿点
float func_data[l][l]={0};      //利用MC模拟得到的结果
float v[l][l]={0};      //每个格点的生长速率
float p[l][l]={0};              //每个格点的占据概率
//int minx=1,miny=1;
//int maxx=l-1,maxy=l-1;
int z0=Sch::Seed();
FILE *f1= fopen("DBM_test.txt","w");     //打印最终结果
//对初始点的电势初始化
void ini_G()
{
    for (int i = 1; i < l-1; ++i) {
        for (int j = 1; j < l-1; ++j) {
                G[i][j] = 0.5;              //G只是电势的一个记号,并不代表真实电势,故可以任意赋不为0/1的值
        }
    }
    G[75][75]=1;            //中心点赋值1
}
//计算周界上的phi值
float phi_calculate(int i, int j)
{
    int N0=0,N1=0;              //分别记录碰到的边界(0)与击穿点(1)数目
    int up_limit=0;             //每个假定粒子运动的次数,不能超过假定上限值
    for (int m = 0; m < brown_num ; ++m) {      //给每个点brown_num个运动次数
        up_limit=0;             //归零
        Particle a;             //定义粒子class
        a.x=i,a.y=j;            //放在周界点(i,j)位置
        while (G[a.x][a.y]!=0&&G[a.x][a.y]!=1) {
            Rdm_walk(&a);               //"粒子"随机游走
            up_limit++;
            if (up_limit>UPPER_LIMIT) break;    //当运动次数大于设置上限则break
        }
        if (G[a.x][a.y]==0) N0++;           //在边界结束运动
        if (G[a.x][a.y]==1) N1++;           //在击穿点结束运动
    }
    float phi=  float(N1)/float(N0+N1);     //返回(i,j)处的phi值
    return phi;
}
//生长速率计算公式
void growth_rate(int i, int j)
{
    v[i][j]=powf(abs(phi0-func_data[i][j]),v_para);
}
//利用Monte-Cole模拟求解Laplace方程
void MC_Laplace(){
    for (int q = 0; q < BROKEN_NUM; ++q) {  //总共需要的击穿点数
        float sum=0,P=0;                    //sum代表Σvij, P代表累计概率函数

        int k,m,all=0;                      //k,m代表被击穿点,all用来计数周界点数
        float boundary[l][l]={0};               //如果i,j是边界则取1
        for (int i = 1; i < l-1; ++i) {
            for (int j = 1; j < l-1; ++j) {
                if ((G[i][j]!=1)&&(G[i-1][j]==1||G[i+1][j]==1||G[i][j+1]==1||G[i][j-1]==1)) //找到边界！
                {
                    boundary[i][j]=1;                           //周界点记为1，等之后方便寻找
                    func_data[i][j] = phi_calculate(i, j);    //存储真实的phi，以免出现舍入误差，真实phi都无限趋近于1
                    growth_rate(i,j);                               //更新i,j速率常数
                    sum += v[i][j];                                 //记录边界速率vij和
                    all++;
                }
            }
        }
        z0 = Sch::Sch_16807(z0);
        auto a = float(1.0 * z0 / M);               //随机数更新
        for (int i = 1; i < l - 1; ++i) {
            for (int j = 1; j < l - 1; ++j) {
                if (boundary[i][j] == 1) {                      //寻找周界的点
                    if (sum==0) p[i][j]=1.0/all;               //这个地方是为了避免所有粒子都没到边界
                    else p[i][j] = v[i][j] / sum;               //计算格子被占据的概率

                    P += p[i][j];                               //离散情况下的抽样
                    if(P-p[i][j]<=a&&a<P) k=i,m=j;              //选中(k,m)的点作为击穿点
                }
                boundary[i][j] = 0;                         //归零，进入下一次寻找
            }
        }

        G[k][m] = 1;                            //G用来记录点是否被击穿，与真实的phi分开处理
        cout << k << "," << m << endl;
        fprintf(f1,"%d,%d\n",k,m);              //打印
//        if(k==1||k==148||m==1||m==148) break;
    }


}

///*****************以下几个函数未能用到**********////
void print()
{
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < l; ++j) {
            if(G[i][j]==1)
                cout<<i<<","<<j<<endl;
        }
    }
}
void single_broken(int i, int j)
{
    //记录上下左右有无击穿点，不是击穿点b[k]=1
    int b[4]={0};
    if (G[i][j+1]!=1){
        b[0]=1;
        G[i][j+1]= phi_calculate(i,j+1);
    }
    if (G[i][j-1]!=1){
        b[1]=1;
        G[i][j-1]= phi_calculate(i,j-1);
    }
    if (G[i-1][j]!=1) {
        b[2] = 1;
        G[i-1][j]= phi_calculate(i-1,j);
    }
    if (G[i+1][j]!=1) {
        b[3] = 1;
        G[i+1][j]= phi_calculate(i+1,j);
    }
    growth_rate(i,j);
//    z0=Sch::Sch_16807(z0);
    int k=i,m=j-1;
    float max=p[i][j-1];
    if (p[i][j+1]>max) k=i,m=j+1,max=p[i][j+1];
//    else k=i,m=j-1,max=p[i][j-1];
    if (p[i-1][j]>max) k=i-1,m=j,max=p[i-1][j];
    if (p[i+1][j]>max) k=i+1,m=j,max=p[i+1][j];
    G[k][m]=1;
}
//length作为正方格点的长度，最外层置0且不更新，G代表group of phi，整个区域内phi的取值（缩到一维）
void Laplace_equations(float* G, int length) {
    auto *Temp = (float *)malloc(sizeof(float )*(length*length));;            //创建一维数组，便于遍历更新；
    float Error=0.0;
    for(int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            Temp[i*length+j] = G[i*length+j];     //初始化
        }
    }
    //用于比较计算两次之间的误差值
    float *T0 = G, *T1 = Temp;            //取地址，T0，T1作为前后两次更新的势能矩阵
    int N = length - 1;                 //真正的粒子可以随机运动的区域
    while(true) {
        Error=0.0;
        for(int i = 1; i < N; i++) {
            for(int j = 1; j < N; j++) {
                T1[i*length+j] = (T0[length*(i-1)+j]+
                                  T0[length*(i+1)+j]+
                                  T0[length*i+j-1]+
                                  T0[length*i+j+1])/4;
                Error+= abs(T1[i*length+j]-T0[i*length+j]);
            }
        }
        if(Error >= accuracy) {
            swap(T0, T1);
        }
        else break;
    }
    free(Temp);
}