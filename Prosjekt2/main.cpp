#include <iostream>
#include "jacobi.h"  //Gathers functions from jacobi.cpp
#include <armadillo> //Matrix maker
#include <math.h>    //Sin, cos

using namespace std;
using namespace arma;


int main() {
    unsigned int n = 3;
    double h = 1.0/n;
    double d = 2/h*h;
    double a = -1/h*h;

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

    Mat<double> R(n, n, fill::zeros);

    //Skal sammenligne eigval med verdiene fra rotasjon funksjonen i jacobi.cpp
    eig_sym(eigval, eigvec, A);

    //Må finne ut en måte å kalle på funksjonen
    jacobi_method(A, R, n);


    cout << eigval << " " << eigvec << endl;
    return 0;
}
