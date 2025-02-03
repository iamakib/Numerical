#include <bits/stdc++.h>
using namespace std;

class Bisection
{
public:
double EPS = 0.01;

    double func(double x)
    {
        return (x * x * x) - (x * x) + 2;
    }

    void bisectionMethod()
    {
        srand(time(0));
        double a = (rand() % 1000) * (-1);
        double b = (rand() % 1000);

        while (func(a) * func(b) > 0)
        {
            a = (rand() % 1000) * (-1);
            b = (rand() % 1000);
        }
        cout << "Root for the interval [ " << a << ", " << b << " ] is: ";

        double c;

        while ( (b - a) >= EPS)
        {
            c = (a + b) / 2;

            if(func(c) == 0.0){
                break;
            }
            else if(func(a)*func(c)<0){
                b = c;
            }
            else{
                a = c;
            }
        }
        cout<<c<<endl;
    }
};

int main()
{

    Bisection *bisection = new Bisection();

    bisection->bisectionMethod();

    return 0;
}