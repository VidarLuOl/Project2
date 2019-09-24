#include "catch.hpp"
#include "test_jacobi.h"
#include <armadillo>

using namespace std;
using namespace arma;

/*TEST_CASE ("Test eigenvalues") {
    int n=4,interact=0;
    double conv=0.001,wr=0.01, pmin=0, pmax=10,h = (pmax-pmin)/(double(n));
    n=n-1;
    mat a = zeros<mat>(n,n);
    mat v = zeros<mat>(n,n);
    vec r(n);
    //initialize matrices and vector
    initialize(n,h,a,r,v,0,0);
    //do jacobi algorithm until convergence
    jacobi_method(n,interact,conv,wr,a,r,v);
    //get eigenvalue vector
    vector<double>eigen=get_eigenvals(a,n);

    REQUIRE(eigen[0]==Approx(6.56863));
    REQUIRE(eigen[1]==Approx(25.32055));
    REQUIRE(eigen[2]==Approx(56.57082));
}*/

