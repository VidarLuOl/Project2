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

    for(unsigned int i=0; i<n-1; i++){
        A(i,i) = d;
        A(i+1,i) = a;
        A(i,i+1) = a;
    }

    A(n-1, n-1) = d;


    Mat<double> P, L, U;

    lu(P, L, U, A);

    cout << L << endl;

    vec eigval;
    mat eigvec;

    eig_sym(eigval, eigvec, A);

    cout << eigval << endl;
    return 0;
}
