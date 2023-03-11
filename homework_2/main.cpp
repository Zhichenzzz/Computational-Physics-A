#include <iostream>
#include "Sch.h"

using namespace std;

int main() {
    Sch s;
    int N=100,p,q;
    while(true){
        cout<<"please input N,p,q: ";
        cin>>N>>p>>q;
        if(N!=0)
        {
            double a= s.Sch_Test_weight(N);
            double b= s.fibonacci_dalayed(N,p,q);
            cout<<"N= "<<N<<", 16807产生器满足序列比重： "<<a<<endl;
            cout<<"N= "<<N<<", p= "<<p<<", q= "<<q<<", fibonacci产生器满足序列比重： "<<b<<endl;
            }
        else return 0;
    }
}
