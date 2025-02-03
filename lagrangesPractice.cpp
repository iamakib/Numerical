#include <bits/stdc++.h>
using namespace std;

struct points
{
    double x,y;
};


class Lagranges
{
public:

    
    void lagrangesMethod(vector<points>input, double value){
        int n = input.size();
        double ans = 0;

        for(int i=0;i<n;i++){
            double up = 1, down = 1;

            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                up*= value - input[j].x;
                down*= input[i].x - input[j].x;
            }
            ans += (up*input[i].y)/down;
        }
        cout<<ans<<endl;
    }
   
    

   
};

int main()
{

    Lagranges *lagranges = new Lagranges();

    vector<points>input;

    double x,y,value;
    cin>>value;
    while(cin>>x>>y){
        input.push_back({x,y});
    }

    
    lagranges->lagrangesMethod(input,value);

    return 0;
}