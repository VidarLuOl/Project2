#include <iostream>
#include "one_dimension.h"
#include "three_dimensions.h"
#include "bisection.h"

using namespace std;


int main() {
    unsigned int n = 100;
    double rho_max = 8.0;

    one_dimension(n);

    three_dimensions(n, rho_max);

//    bisection(n);


    return 0;
}
