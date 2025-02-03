#include <bits/stdc++.h>

using namespace std;

class Bisection
{
public:
double EPSILON = 0.001;


    double func(double x)
    {
        return (x * x * x) - (x*x) + 2; //x^3 - x^2 + 2
    }

    void bisection_method()
    {   
        cout<<fixed<<setprecision(3);
        srand(time(0));
        double a = (rand()%1000)*(-1);
        double b = (rand()%1000);

        while(func(a)*func(b)>=0){
            a = (rand()%1000)*(-1);
            b = (rand()%1000);
        }

        cout<<"Interval [ "<<a<<" , "<<b<<" ]"<<endl;
        double c;

        while((b-a) > EPSILON){
            c = (a+b)/2;

            if(func(c)==0.0){
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

    bisection->bisection_method();

    return 0;
}
