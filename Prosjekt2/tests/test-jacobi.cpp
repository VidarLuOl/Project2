#include "catch.hpp"
#include "../main-program/jacobi.h"
#include <armadillo>

using namespace std;
using namespace arma;

TEST_CASE("Test eigenvalues"){

    int n = 5;
    // Set up exact eigenvalues
    vec exact_eigval(n);

    double pi = acos(-1.0);
    double h = 1.0/n;
    double d = 2.0/(h*h);
    double a = -1.0/(h*h);

    for (int i = 0; i < n; i++) {
       exact_eigval(i) = d + 2*a*cos((i+1)*pi/(n + 1));
    }

    // Get numerical eigenvalues
    vec num_eigval(n);

    Mat<double> A(n, n, fill::zeros);
    Mat<double> R(n, n, fill::zeros);

    // initializing matrix A
    for(int i=0; i<n-1; i++){
        A(i,i) = d;
        A(i+1,i) = a;
        A(i,i+1) = a;
    }
    A(n-1, n-1) = d;

    jacobi_method(A, R, n, false);

    num_eigval = sort(A.diag());


    for (int i=0; i < n; i++) {
    REQUIRE(num_eigval(i)==Approx(exact_eigval(i)).epsilon(0.000000000001));
    }
}

TEST_CASE("Test preserved orthogonality"){
    int n = 5;
    // Set up exact eigenvalues
    vec exact_eigval(n);

    double pi = acos(-1.0);         // ?????????????????????
    double h = 1.0/n;
    double d = 2.0/(h*h);
    double a = -1.0/(h*h);

    for (int i = 0; i < n; i++) {
       exact_eigval(i) = d + 2*a*cos((i+1)*pi/(n + 1));
    }

    // Get numerical eigenvalues
    vec num_eigvec(n);

    Mat<double> A(n, n, fill::zeros);
    Mat<double> R(n, n, fill::zeros);
    Mat<double> U(n, n, fill::zeros);


    // initializing matrix A
    for(int i=0; i<n-1; i++){
        A(i,i) = d;
        A(i+1,i) = a;
        A(i,i+1) = a;
        U(i,i) = 1;
    }
    A(n-1, n-1) = d;
    U(n-1, n-1) = 1;

    U(n/2-1, n-1) = -sin(pi/4);
    U(n-1, n/2-1) = sin(pi/4);
    U(n-1, n-1) = cos(pi/4);
    U(n/2-1, n/2-1) = cos(pi/4);

    jacobi_method(A, R, n, false);

    cout << dot(U*R.col(0), U*R.col(0)) << endl;

    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            if (i == j) {
                REQUIRE(dot(U*R.col(i), U*R.col(i))==Approx(1.0).epsilon(0.000000000001));
            }
            else {
//                cout << dot(U*R.col(j), U*R.col(i)) << endl;
//                cout << Approx(0.0).epsilon(0.1)) << endl;
                 REQUIRE((dot(U*R.col(j), U*R.col(i)))==Approx(0.0).margin(0.000000000001));

//                REQUIRE(-0.00001==Approx(0.0).margin(0.1));
            }
        }
    }

}
