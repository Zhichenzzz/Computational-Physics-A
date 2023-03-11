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
            fp<<2*double(z/M)-1<<endl;                             //2*z/M-1,映射到[-1,1]上
    //      cout<<double(z/M)<<endl;
        }
    }
    //debug    cout<<"not open!"<<endl;
    fp.close();
}


