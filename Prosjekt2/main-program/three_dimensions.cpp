#include <iostream>
#include "jacobi.h"  //Gathers functions from jacobi.cpp
#include <armadillo> //Matrix maker
#include <chrono>

using namespace std;
using namespace arma;


vec three_dimensions (unsigned int n, double rho_max, bool timing){
    double h = rho_max/n;
    double hh = h*h;

    double d = 2/(hh);      // leading diagonal elements
    double e = -1/(hh);     // off-diagonal elements

    Mat<double> H(n, n, fill::zeros);       // Matrix for one dimension
    Mat<double> R(n, n, fill::zeros);       // Matrix to fill with eigenvectors


    // initializing matrix H
    for(unsigned int i=0; i<n-1; i++){
        H(i, i) = d + (i+1)*(i+1)*hh;
        H(i+1,i) = e;
        H(i,i+1) = e;
    }
    H(n-1, n-1) = d + (n*n*hh);


    vec eigval;
    mat eigvec;

    if (timing) {
        cout << "Three dimensions" << endl;

        // start timing
        auto start = chrono::high_resolution_clock::now();

        // Calculating eigenpairs with armadillo
        eig_sym(eigval, eigvec, H);

        // end timing
        auto finish = chrono::high_resolution_clock::now();

        // print time
        chrono::duration<double> elapsed = (finish - start);
        cout << "Armadillo eig_sym: " << elapsed.count() << " s\n";
    }

    // calculating eigenvectors with Jacobi's method
    jacobi_method(H, R, n, timing);

    return sort(H.diag());
}



double relative_error (int n, vec numerical) {
    vec analytical(n);

    int a = 3;
    for (int i=0; i<n; i++) {
        analytical[i] = a;
        a += 4;
    }

    //Calculate relative error
    double* eps = new double[n];

    for (int i=1; i<n; i++){
        eps[i-1] = log10(abs((numerical[i]-analytical[i])/analytical[i]));
    }

    //Find maximum element in error array
    double max = eps[0];
    for (int i=1; i<n; i++){
        if (abs(eps[i]) > abs(max)) {
            max = eps[i];
        }
    }

    return max;
}
