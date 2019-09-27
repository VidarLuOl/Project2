#include <iostream>
#include <armadillo> //Matrix maker
#include "jacobi.h"

using namespace std;
using namespace arma;

void bisection(unsigned int n)
{
    /*
    c - En n*1 array med de diagonale verdiene. (2) me kale an for d.
    b - Den andre diagonale verdien. (-1) me kalle an a.

    beta - ???

    n - Størrelsen på matrisen
    m1, m2 - hvor m1 er den minste egenverdien og m2 er den største?
    eps1 - Hvor nøye vi skal være før vi stopper opp loopen
    relfeh - Det minste nummeret hvor (1+relfeh > 1)?
    eps2 -
    z - Totalt antall looper vi må gå igjennom før den forandrer seg mindre en eps1.
    x - Innholder alle de lagde egenverdiene
     */

    //Lager grunnstrukturen
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

    int xmin, xmax, i;

    xmin = d - abs(a);
    xmax = d + abs(a);

    for(i = 1; i < n-1; ){
        cout << "hei" << endl;
    }
}
