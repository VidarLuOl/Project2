#include <iostream>
#include "jacobi.h"
#include <armadillo>

using namespace std;
using namespace arma;


int main() {
    unsigned int n = 10;
    int d = 3;
    int a = 1;

    Mat<double> A(n, n, fill::zeros);

    for(unsigned int i=0; i<n; i++){
        A(i,i) = d;
    }

    for(unsigned int i=0; i<n-3; i++){
        A(i+3,i) = a;
        A(i,i+3) = a;
    }

    Mat<double> P, L, U;

    lu(P, L, U, A);

    cout << A << endl << P << endl << L << endl << U << endl;

    return 0;
}
