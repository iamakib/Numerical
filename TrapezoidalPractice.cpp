#include <bits/stdc++.h>
using namespace std;

struct Points{
    double x,y;
};

class Trapezoidal{
    public:

    double trapezoidalCalc(vector<Points> point, double h){
        double ans;
        int sz = point.size();
        ans = point[0].y + point[sz-1].y;

        for(int i=1;i<sz-1;i++){
            ans+= 2*point[i].y;
        }

        ans = ans*(h/2);

        return ans;
    }

};

int main(){

    //cout<<"Hello World"<<endl;

    Trapezoidal *trapezoidal = new Trapezoidal();

    vector<Points> point;
    double h,x,y;
    cin>>h;

    while(cin>>x>>y){
        point.push_back({x,y});
    }

    double ans =  trapezoidal->trapezoidalCalc(point, h);

    cout<<fixed<<setprecision(6);
    cout<<ans<<endl;

    return 0;
}