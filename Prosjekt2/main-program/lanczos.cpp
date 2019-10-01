#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

void lanczos (unsigned int n) {
    double rho_max = 5;
    double h = rho_max/n;
    double hh = h*h;

    double d = 2/(hh);      // leading diagonal elements
    double e = -1/(hh);     // off-diagonal elements

    Mat<double> A(n, n, fill::zeros);


    // initializing matrix H
    for(unsigned int i=0; i<n-1; i++){
        A(i, i) = d + (i+1)*(i+1)*hh;
        A(i+1,i) = e;
        A(i,i+1) = e;
    }
    A(n-1, n-1) = d + (n*n*hh);


    vec beta(n);
    vec alpha(n);

    beta[0] = 1;

    Mat<double> Q(n, n, fill::zeros);
    Mat<double> R(n, n, fill::zeros);

    for (int i=0; i<n; i++) {
        Q(i, 1) = rand();
    }
    Q.col(1) = Q.col(1)/norm(Q.col(1));

    R.col(0) = Q.col(1);



    int k = 0;
    while (beta[k] != 0) {
        Q.col(k+1) = R.col(k)/beta[k];
        k = k + 1;

        alpha[k] = dot(trans(A)*Q.col(k), Q.col(k));

        R.col(k) = (A - alpha[k]*eye(n, n))*Q.col(k) - beta[k-1]*Q.col(k-1);

        beta[k] = norm(R.col(k));
    }

}
