#ifndef JACOBI_H
#define JACOBI_H

double maxoffdiag ( double ** A, int * k, int * l, int n );
void rotate ( double ** A, double ** R, int k, int l, int n );
void jacobi_method ( double ** A, double ** R, int n );

#endif // JACOBI_H
