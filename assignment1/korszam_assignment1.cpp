#include <cmath>
#include <iostream>
using namespace std;


struct Tin {                   // holds data for testing 'integral'
    long double n[6];
    long double I[6] = {0,0,0,0,0,0};
    long double d;
    long double e;
};

long double cosexp(long double x);  // function to be integrated

long double integral(long double ll, long double ul, long double (*f)(long double a), long double p=1e-4);  // function that will integrate, if 'p' is very small run time will be pretty long

void test(Tin& s);               // tests 'integral' at different number of steps

int main(){

    Tin t;
    t.d = -1;        // lower boundary
    t.e = 3;         // upper boundary
    t.n[0] = 10;
    t.n[1] = 100;
    t.n[2] = 1000;
    t.n[3] = 10000;
    t.n[4] = 100000;
    t.n[5] = 1000000;
    t.I;

    cout.precision(23);

    test(t);

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


        I += (dx/8)*(f(ll) + f(ll+dx) + 3*f((2*ll+ll+dx)/3) + 3*f((ll+2*(ll+dx))/3));
        ll += dx;

    }

    return I;
}

void test(Tin& s) {

    long double p[6];

    for (int i =0; i < 6; i++) {

        p[i] = (s.e - s.d)/s.n[i];                  // p value that will make 'integral' take n number of steps

        s.I[i]= integral(s.d, s.e, cosexp, p[i]);
    }

    for (int j = 0; j < 6; j++) {
        
        cout << "number of steps: " << s.n[j] << endl << "result: " << s.I[j] << endl << endl;
    }

}