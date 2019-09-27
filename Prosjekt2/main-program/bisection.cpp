#include "bisection.h"
#include <iostream>
#include <armadillo> //Matrix maker
#include <chrono>

using namespace std;
using namespace arma;

void bisection(unsigned int n)
{
    /*
    c - En n*1 array med de diagonale verdiene. (2) også kalt d i de andre opg.
    b - Den andre diagonale verdien. (-1) også kalt a i de andre opg.

    beta - ???

    n - Størrelsen på matrisen
    m1, m2 - hvor m1 er den minste egenverdien og m2 er den største?
    eps1 - Hvor nøye vi skal være før vi stopper opp loopen
    relfeh - Det minste nummeret hvor (1+relfeh > 1)?
    eps2 -
    z - Totalt antall looper vi må gå igjennom før den forandrer seg mindre en eps1.
    x - Innholder alle de lagde egenverdiene
     */
}
