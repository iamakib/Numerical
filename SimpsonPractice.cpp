#include<bits/stdc++.h>
using namespace std;

struct Points{
    double x,y;
};

class Simpson{
    public:
    double simpsonCalc(vector<Points> point, double h){
        int sz = point.size();
        double ans;
        
        ans = point[0].y + point[sz-1].y;

        for(int i=1;i<sz-1;i++){
            if(i%2){
                ans+= 4*point[i].y;
            }
            else{
                ans+= 2*point[i].y;
            }
        }

        ans = ans*(h/3);

        return ans;
    }
};

int main()
{   
    //cout<<"Hello World"<<endl;

    Simpson *simpson = new Simpson();

    vector<Points> point;
    double h,x,y;
    cin>>h;

    while(cin>>x>>y){
        point.push_back({x,y});
    }

    double ans = simpson->simpsonCalc(point, h);
    cout<<ans<<endl;
    return 0;
}