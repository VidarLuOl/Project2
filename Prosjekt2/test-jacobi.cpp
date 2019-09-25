#include "catch.hpp"
#include "jacobi.h"
#include <armadillo>

using namespace std;
using namespace arma;

TEST_CASE("Test eigenvalues"){

    int n = 10;
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

    jacobi_method(A, R, n);

    num_eigval = A.diag();

    // the eigenvalues are the same, but in different order - what to do?
    int p = 2;
    REQUIRE(p == 2);
    REQUIRE(num_eigval(0)==Approx(exact_eigval(0)).epsilon(0.000000000001));
    REQUIRE(num_eigval[1]==Approx(exact_eigval(1)).epsilon(0.000000000001));
    REQUIRE(num_eigval[2]==Approx(exact_eigval(2)).epsilon(0.000000000001));
}

