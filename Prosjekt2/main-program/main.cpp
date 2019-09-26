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
    double hh = h*h;

    double d = 2/(hh);      // leading diagonal elements
    double a = -1/(hh);     // off-diagonal elements

    Mat<double> A(n, n, fill::zeros);       // Matrix for one dimension
    Mat<double> R(n, n, fill::zeros);       // Matrix to fill with eigenvectors
    Mat<double> H(n, n, fill::zeros);       // Matrix for three dimensions


    // initializing matrix A and H
    for(unsigned int i=0; i<n-1; i++){
        A(i,i) = d;
        A(i+1,i) = a;
        A(i,i+1) = a;

        H(i, i) = d + i*i*hh;
        H(i+1,i) = a;
        H(i,i+1) = a;
    }
    A(n-1, n-1) = d;
    H(n-1, n-1) = d + (n-1)*(n-1)*hh;

    vec eigval;
    mat eigvec;



    cout << "One dimension" << endl;

    // start timing
    auto start_1 = chrono::high_resolution_clock::now();

    // Calculating eigenpairs with armadillo
    eig_sym(eigval, eigvec, A);

    // end timing
    auto finish_1 = chrono::high_resolution_clock::now();

    // print time
    chrono::duration<double> elapsed_1 = (finish_1 - start_1);
    cout << "Armadillo eig_sym: " << elapsed_1.count() << " s\n";

    // calculating eigenvectors with Jacobi's method
    jacobi_method(A, R, n);




    cout << "Three dimensions" << endl;

    // start timing
    auto start_3 = chrono::high_resolution_clock::now();

    // Calculating eigenpairs with armadillo
    eig_sym(eigval, eigvec, H);

    // end timing
    auto finish_3 = chrono::high_resolution_clock::now();

    // print time
    chrono::duration<double> elapsed_3 = (finish_3 - start_3);
    cout << "Armadillo eig_sym: " << elapsed_3.count() << " s\n";

    // calculating eigenvectors with Jacobi's method
    jacobi_method(H, R, n);

//    cout << R << "\n " << eigvec << endl;
//    cout << eigval << endl;
    return 0;
}
