#include <iostream>
#include "jacobi.h"  //Gathers functions from jacobi.cpp
#include <armadillo> //Matrix maker
#include <math.h>    //Sin, cos
#include <chrono>

using namespace std;
using namespace arma;


int main() {
    unsigned int n = 10;
    double h = 1.0/n;
    double d = 2/(h*h);
    double a = -1/(h*h);

    Mat<double> A(n, n, fill::zeros);
    Mat<double> R(n, n, fill::zeros);

    // initializing matrix A
    for(unsigned int i=0; i<n-1; i++){
        A(i,i) = d;
        A(i+1,i) = a;
        A(i,i+1) = a;
    }
    A(n-1, n-1) = d;

    vec eigval;
    mat eigvec;

    // start timing
    auto start = chrono::high_resolution_clock::now();

    // Calculating eigenpairs with armadillo
    eig_sym(eigval, eigvec, A);

    // end timing
    auto finish = chrono::high_resolution_clock::now();

    // print time
    chrono::duration<double> elapsed = (finish - start);
    cout << "Armadillo eig_sym: " << elapsed.count() << " s\n";

    // calculating eigenvectors with Jacobi's method
    jacobi_method(A, R, n);

//    cout << R << "\n " << eigvec << endl;
    return 0;
}
