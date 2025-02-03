#include <bits/stdc++.h>
using namespace std;

class NewtonRaphson
{
double diff = 0.01;
public:
   
    double func(double x)
    {
        return (x * x * x) + (x * x) + 7; // x^3 + x^2 + 7
    }

    double ddxf(double x){
        return (3*x*x) + 2*x; //3x^2 + 2x
    }

    void newtonRaphsonMethod()
    {
        srand(time(0));

        // finout interval
        double a = (rand() % 1000) * (-1);
        double b = (rand() % 1000);

        while (func(a) * func(b) > 0)
        {
            a = (rand() % 1000) * (-1);
            b = (rand() % 1000);
        }
        cout << "interval [ " << a << ", " << b << " ] "<<endl;

        // value which closer to 0
        double x;
        if(abs(a)<abs(b)){
            x=a;
        }
        else{
            x=b;
        }
        
        cout<<"Assume value of x = "<<x<<endl;

        double h = func(x)/ddxf(x);

        while(abs(h)>diff){
            x = x-h;
            h = func(x)/ddxf(x);
            //cout<<h<<endl;
        }

        cout<<"Root : "<<x<<endl;
    }
};

int main()
{

    NewtonRaphson *newtonrap = new NewtonRaphson();

    newtonrap->newtonRaphsonMethod();

    return 0;
}