#include <iostream>
#include "one_dimension.h"
#include "three_dimensions.h"
#include "bisection.h"
#include <math.h>
#include <fstream>
#include <armadillo>

using namespace std;
using namespace arma;


int main() {
//    double rho_max = 8.0;

//    one_dimension(n);

//    three_dimensions(n, rho_max);

//    bisection(n);

//    cout << ((1 + 0.000000000000001) > 1) << endl;
//    cout << ((pow(2, 15))) << endl;
//    cout << max(1, 2) << endl;

//    initializing(10);



    /*string file = "iterations.txt";
    ofstream ofile;
    ofile.open(file);

    vec n_values = {10, 50, 100, 200, 500};
    cout << n_values << endl;

    for (int i=0; i<5; i++) {
        unsigned int n = n_values[i];
        ofile << n << one_dimension(n);
    }

    ofile.close();*/


    // writing the relative error to file
    vec n_values = {10, 50, 100, 200, 500};
    vec rho_max_values = {2, 5, 8};

    for (int i=0; i<3; i++) {
        int rho_max = rho_max_values[i];

        ofstream ofile;
        string file = "error-rho_max-";
        file.append(to_string(rho_max));
        ofile.open(file);

        for (int j=0; j<2; j++) {
            int n = n_values[j];

            vec numerical_eigval = three_dimensions(n, rho_max, false);
            double max = relative_error(n, numerical_eigval);
            double h = rho_max/n;

            ofile << n << " " << log10(h) << " " << max << "\n";
        }
        ofile.close();
    }


    return 0;
}
