#include <iostream>
#include "jacobi.h"
#include <armadillo>

using namespace std;
using namespace arma;


int main() {
    int N;
    N = 10;

    mat A(N,N);

    cout << "A.n_rows = " << A.n_rows << endl;
    cout << "A.n_cols = " << A.n_cols << endl;

    A.print("A:");
}
