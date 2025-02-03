#include <bits/stdc++.h>
using namespace std;

struct points
{
    double x,y;
};


class NewtonForward
{
public:

    double calculate_u(double u, int n){
        double result = u;

        for(int i=1;i<n;i++){
            result = result*(u-i);
        }

        return result;
    }

    long long int fact(int n){
        long long int result = 1;
        for(int i=2;i<=n;i++){
            result = result*i;
        }
        return result;
    }

    void newtonForwardMethod(vector<points>input, int value){
        int n = input.size();

        double table[n][n];
        
        //first column
        for(int i=0;i<n;i++){
            table[i][0] = input[i].y;
        }
        //other columns
        for(int i=1;i<n;i++){
            for(int j=0;j+i<n;j++){
                table[j][i] = table[j+1][i-1] - table[j][i-1];
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j+i<n;j++){
        //         cout<<table[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        double ans = table[0][0];

        double u = (value - input[0].x)/(input[1].x - input[0].x);

        for(int i=1;i<n;i++){
            ans = ans + (calculate_u(u,i)*table[0][i])/(double)fact(i);
        }

        cout<<ans<<endl;
    }
   
    

   
};

int main()
{

    NewtonForward *newtonForward = new NewtonForward();

    vector<points>input;

    double x,y,value;
    cin>>value;
    while(cin>>x>>y){
        input.push_back({x,y});
    }

    newtonForward->newtonForwardMethod(input,value);

    return 0;
}

/*
4
3 180
5 150
7 120
9 90

ans = 165*/