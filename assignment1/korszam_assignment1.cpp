#include <cmath>
#include <iostream>
using namespace std;

long double cosexp(long double x);  // function to be integrated

long double integral(long double ll, long double ul, long double (*f)(long double a), long double p=1e-6);  // function that will integrate, if 'p' is very small run time will be pretty long

int main(){

             // this will contain the result
    long double ll = 0;           // lower boundary
    long double ul = 1;           // upper boundary
    long double result = integral(ll, ul, cosexp);
    cout << result <<endl;
    return 0;
}

long double cosexp(long double x){

    return cos(x)*exp(-(x*x));
}


long double integral (long double ll, long double ul, long double (*f)(long double a), long double p) {

    long double I=0;
    long double L = abs(ul - ll);      // interval on which the function is integrated
    int N = round(L/(p));                // number of steps integration will take
    long double dx = L/N;           // size of integration steps

    for (int i = 0; i < N; i++) {          // for loop that does the integration

        I += (f(ll)+f(ll+dx))/2*dx;
        ll += dx;

    }

    return I;
}