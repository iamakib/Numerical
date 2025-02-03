#include<bits/stdc++.h>
using namespace std;

struct Points{
    double x,y;
};

class NewtonDivided{
    public:

    double calculateDivided(vector<Points> point, double value){
        int n = point.size();

        double table[n][n];
        
        //first column
        for(int i=0;i<n;i++){
            table[i][0] = point[i].y;
        }
        //other columns
        for(int i=1;i<n;i++){
            for(int j=0;j+i<n;j++){
                table[j][i] = (table[j+1][i-1] - table[j][i-1])/(point[j+i].x - point[j].x);
            }
        }
        double ans = table[0][0];
        double count = 1;
        for(int i=1;i<n;i++){
            count *= (value - point[i-1].x);
            ans += count*table[0][i];
        }
        return ans;
    }
};

int main()
{
   
    
    NewtonDivided *newtonDivided = new NewtonDivided();

    vector<Points> point;
    double value, x, y;
    
    cin>>value;

    while(cin>>x>>y){
        point.push_back({x,y});
    }

    double ans = newtonDivided->calculateDivided(point, value);
    cout<<ans<<endl;
    return 0;
}