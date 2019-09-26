#include <iostream>
#include "jacobi.h"  //Gathers functions from jacobi.cpp
#include <armadillo> //Matrix maker
#include <chrono>

using namespace std;
using namespace arma;


void one_dimension (unsigned int n) {
    double h = 1.0/n;
    double hh = h*h;

    double d = 2/(hh);      // leading diagonal elements
    double a = -1/(hh);     // off-diagonal elements

    Mat<double> A(n, n, fill::zeros);       // Matrix for one dimension
    Mat<double> R(n, n, fill::zeros);       // Matrix to fill with eigenvectors


    // initializing matrix A
    for(unsigned int i=0; i<n-1; i++){
        A(i,i) = d;
        A(i+1,i) = a;
        A(i,i+1) = a;
    }
    A(n-1, n-1) = d;

    vec eigval;
    mat eigvec;


    cout << "One dimension" << endl;

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

}
