#include<bits/stdc++.h>
using namespace std;

class Euler{
    public:

    double func(double x, double y){
        return x - y*y; 
        //dy/dx =  x - y^2
    }

    double EulerCalc(double x, double h, double x0, double y0){

        while(x0<x){
            y0 += h*func(x0,y0);
            x0 += h;
        }
        return y0;
    }
};
int main(){

    //cout<<"hello world"<<endl;

    Euler *euler = new Euler();

    double x0, y0,x,h;

    cin>>x>>h>>x0>>y0;

    double ans = euler->EulerCalc(x,h,x0,y0);

    cout<<fixed<<setprecision(4);
    cout<<ans<<endl;
    return 0;
}