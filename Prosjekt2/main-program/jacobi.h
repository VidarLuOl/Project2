#include <armadillo>
#ifndef JACOBI_H
#define JACOBI_H

using namespace arma;

double maxoffdiag ( mat &A, int * k, int * l, int n );
void rotate ( mat &A, mat &R, int k, int l, int n );
int jacobi_method ( mat &A, mat &R, int n, bool timing );

#endif // JACOBI_H
