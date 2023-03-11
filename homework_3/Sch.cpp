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
            fp<<double(z/M)<<endl;                             //z/M，写文件
            //      cout<<double(z/M)<<endl;
        }
    }
    //debug    cout<<"not open!"<<endl;
    fp.close();

}

void Sch::Cos(int N, const char *url) {
    Save_Random(Seed(),N,"Ran_1.txt");                  //生成Ran_1.txt文件，用于存储抽样x的数值
    string line;
    double k,cos=0,theta;
    ifstream fp;
    fp.open("Ran_1.txt",ios::in);
    ofstream f;
    f.open(url,ios::out);                               //将x抽样来表示cos(theta)
    while (!fp.eof()){
        getline(fp,line);
        istringstream sin(line);
        string Waypoints;
        getline(sin,Waypoints);
        stringstream sx; //transform string to double
        sx << Waypoints;
        sx >> k;
        cos = 1-2*k;                                            //cos
        theta = acos(cos);                                       //反三角函数
        f<<theta<<endl;
    }
    fp.close();
    f.close();
}

void Sch::Phi(int N, const char *url) {
    Save_Random(Seed(),N,"Ran_2.txt");                       //生成Ran_2.txt文件，用于存储抽样y的数值
    string line;
    double k,phi;
    ifstream fp;
    fp.open("Ran_2.txt",ios::in);
    ofstream f;
    f.open(url,ios::out);                                   //将y抽样表示phi=2*PI*y
    while (!fp.eof()){
        getline(fp,line);
        istringstream sin(line);
        string Waypoints;
        getline(sin,Waypoints);
        stringstream sx; //transform string to double
        sx << Waypoints;
        sx >> k;
        phi=2*PI*k;                                                 //phi计算
        f<<phi<<endl;
    }
    fp.close();
    f.close();
}
