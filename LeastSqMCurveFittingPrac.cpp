#include <bits/stdc++.h>
using namespace std;

struct points{
    double x,y;
};

class LeastSqM{
    public:

    points leastSqMCurve(vector<points> point){
        points result;

        double x=0,y=0,xy=0, sqx=0;
        double n = point.size();

        for(auto i:point){
            x += i.x;
            y += i.y;
            xy += i.x*i.y;
            sqx += i.x*i.x;

        }
        result.y = ((n*xy) - (x*y))/(n*sqx -(x*x));
        result.x = (y-(result.y)*x)/n;
        // result.x = (y/n)-((result.y * x)/n);

        return result;
    }
    

};

int main(){
    
    LeastSqM *leastSqM = new LeastSqM();

    vector<points> point;
    double x,y;

    while(cin>>x>>y){
        point.push_back({x,y});
    }
    
    points res = leastSqM->leastSqMCurve(point);

    cout<<res.x<<" "<<res.y<<" ";

    return 0;
}