//
// Created by HUAWEI on 2022/9/11.
//

#include "Sch.h"

//利用系统时间生成种子，参数自己可任意修改
int Sch::Seed(){
    SYSTEMTIME sys;
    GetLocalTime( &sys );
    int seed;
    seed = sys.wYear + 70 * ( sys.wMonth + 12 *( sys.wDay + 31 * ( sys.wHour + 23 * ( sys.wMinute\
            + 59 * sys.wSecond))));
    return seed;
}
void Sch::save_seed(int N){          //提前利用不同的时间存储N个种子值在txt文件，以免后续每次产生种子需要休眠
    FILE *fp= fopen("seed.txt","w");
    for (int i = 0; i < N; ++i) {
        int m=Seed();
        fprintf(fp,"%d\n",m);
        Sleep(5000);
    }
    fclose(fp);
}

// 16807产生器
int Sch::Sch_16807(int z) {
    if(z<0)
        return -1;
    int result = A*(z%Q)-R*(z/Q);               //Schrage方法
    if(result<0)
        return result+M;
    else
        return result;
}

//生成随机数并存在Random_data.txt内
void Sch::Save_Random(int seed, int N, char const url[]){
    int i;
    fstream fp;
    fp.open(url,ios::out);
    if(fp.is_open()){
        //   cout<<"open!"<<endl;
        double z=seed;
        //debug    cout<<"bug1"<<endl;
        for(i=0;i<=N-1;i++){
            //      cout<<"The "<<i<<" Random number:"<<endl;
            z = Sch_16807(z);                               //生成随机数
            fp<<double(z/M)<<endl;                             //z/M，写文件
            //      cout<<double(z/M)<<endl;
        }
    }
    //debug    cout<<"not open!"<<endl;
    fp.close();
}

//double Sch::Sch_Test_weight(int N) {
//    int i =0,z= Seed();                     //生成种子
//    int k[3]={0,2,1};           //n-1>n+1>n的排列，初始为0，2，1
//    int sum=0,num=0;
//    auto* tempArray = (double*)malloc(3 * sizeof(double));  //创建动态数组，存入每次比较的三个数字
//    for(int j:k){                                           //初始三个数
//        z= Sch_16807(z);
//        tempArray[j]=double(z)/M;
//
//    }
//    if((tempArray[0]>tempArray[2])&&(tempArray[2]>tempArray[1])) num++;         //序号为n-1>n+1>n，计数加一
//    sum++;                                                                          //每次比较加一
//    for(i=3;i<N+2;i++){
//        tempArray[0]=tempArray[2];                                                  //继承上一次的n和n+1
//        tempArray[2]=tempArray[1];
//        z= Sch_16807(z);                                                                //生成新的随机数
//        tempArray[1]=double(z)/M;
//        if((tempArray[0]>tempArray[2])&&(tempArray[2]>tempArray[1])) num++;         //序号为n-1>n+1>n
//        sum++;                                                                      //同上
//    }
// //测试数据   cout<<sum<<endl;
//    free(tempArray);                                                        //释放内存
//    return double(num)/sum;                                                         //返回比重
//}
//
//double Sch::fibonacci_dalayed(int N, int p, int q) {
//    int i =0,z= Seed(),j=0;                     //生成种子
////    int k[3]={0,2,1};
//    int sum=0,num=0;
//    long int F=0;
//    auto* tempArray = (long int*)malloc(100 * sizeof(long int));  //创建动态数组，存入初始数值
//    double B[3]={0};
//    for(j=0;j<100;j++){                                           //初始100个数，用来计算后续值大小
//        z= Sch_16807(z);
//        tempArray[j]=z;
//    }
//    for(i=0;i<N;i++){
//        F= tempArray[99-p]-tempArray[99-q];
//        if(F<0) F=F+O;                                              //o大小为2^32-5-1
//        for(j=99;j>0;j--){tempArray[j]=tempArray[j-1];}
//        tempArray[0]=F;
//    //此时不用化为[0,1]内比大小,因为都是公约数
//        if((tempArray[0]>tempArray[2])&&(tempArray[2]>tempArray[1])) num++;         //序号为n-1>n+1>n
//        sum++;                                                                      //计数加加
//    }
////测试数据    cout<<num<<endl;
//    free(tempArray);                                                                 //释放内存
//    return double(num)/sum;                                                         //返回比重
//
//}


