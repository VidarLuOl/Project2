#include <iostream>
#include "one_dimension.h"
#include "three_dimensions.h"
#include "lanczos.h"
#include <math.h>
#include <fstream>
#include <armadillo>

using namespace std;
using namespace arma;


int main() {

    // writing the relative error to file
    vec n_values = {10, 25, 50, 75, 100, 200, 500};
    // vec rho_max_values = {2, 4, 6, 8, 10, 20, 50, 100, 300};
    vec rho_max_values = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};

    for (int i=0; i<6; i++) {
        int n = n_values[i];
        cout << n << endl;

        ofstream ofile;
        string file = "error-small-n-";
        file.append(to_string(n));
        ofile.open(file);

        for (int j=0; j<10; j++) {
            double rho_max = rho_max_values[j];

            vec numerical_eigval = three_dimensions(n, rho_max, false);
            double average = relative_error(n, numerical_eigval);

            ofile << n << " " << rho_max << " " << average << "\n";
        }
        ofile.close();
    }

    return 0;
}
