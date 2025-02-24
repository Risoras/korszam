#include <cmath>
#include <iostream>
using namespace std;

long double cosexp(long double x);  // function to be integrated

long double integral(long double ll, long double ul);  // function that will integrate

int main(){


    long double x=0;
    long double result = integral(0,1);
    cout << result <<endl;
    return 0;
}


long double cosexp(long double x){

    return cos(x)*exp(-(x*x));

}


long double integral (long double ll, long double ul) {

    long double I=0;
    long double x = ll;
    long double interval = abs(ul - ll);      // interval on which the function is integrated
    int N = round(interval/(1e-6));                // number of steps integration will take

    long double dx = interval/N;           // size of integration steps
    long double thing =0;

    for (int i = 0; i < N; i++) {          // for loop that does the integration
        thing = (x+x+dx)/2;
        I += cosexp(thing)*dx;
        x += dx;

    }
    return I;


}