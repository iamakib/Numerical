#include <bits/stdc++.h>
using namespace std;

class Secant
{
double diff = 0.0001;
public:
   
    double func(double x)
    {
        return (x * x * x) + (x * x) + 7; // x^3 + x^2 + 7
    }

    void secantMethod()
    {   
        cout<<fixed<<setprecision(2);

        // findout Interval
        srand(time(0));
        double a = (rand() % 1000) * (-1);
        double b = (rand() % 1000);
        while (func(a) * func(b) > 0)
        {
            a = (rand() % 1000) * (-1);
            b = (rand() % 1000);
        }
        //cout << "interval [ " << a << ", " << b << " ] "<<endl;
        //cout<<func(a)<<" "<<func(b)<<endl;

        double x1,x0;
        x1 = max(a,b);
        x0 = min(a,b);
        cout<<x0<<" "<<x1<<endl;


        double minus = ((x1-x0)/(func(x1) - func(x0)))*func(x1);
        double root;

        while(abs(minus)>diff){
            root = x1 - ((x1-x0)/(func(x1) - func(x0)))*func(x1);

            int temp = x1;
            x1=root;
            x0 = temp;

            minus = ((x1-x0)/(func(x1) - func(x0)))*func(x1);
            //cout<<minus<<endl;
        }

        cout<<root<<endl;

    }
};

int main()
{

    Secant *secant = new Secant();

    secant->secantMethod();

    return 0;
}