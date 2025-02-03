#include <bits/stdc++.h>
using namespace std;

class FalsePosition
{
public:
    double EPS = 0.0001;
    //const int ub = 1000;
    //const int lb = -1000;
    const int mx = 2e6;
    double func(double x)
    {
            return x*x*x*x - x - 10; //x^3 + x^2 +7
    }

    void FalsePositionMethod()
    {   
        cout<<fixed<<setprecision(3);
        srand(time(0));

        double a = (rand() % 1000) * (-1);
        double b = (rand() % 1000);

        while (func(a) * func(b) > 0)
        {
            a = (rand() % 1000) * (-1);
            b = (rand() % 1000);
        }
        cout << " [ " << a << ", " << b << " ] is: ";

        double c;

         //while ((b - a) > EPS)
        for (int i = 0; i < mx; i++)
        {
            c = (a * func(b) - b * func(a)) / (func(b) - func(a));

            // c = (a+b)/2;

            if ( func(c) == 0.0)
            {
                break;
            }
            else if (func(a) * func(c) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
        }
        cout << c << endl;
    }
};

int main()
{

    FalsePosition *falsePos = new FalsePosition();

    falsePos->FalsePositionMethod();

    return 0;
}