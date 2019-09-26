#include <iostream>
#include "one_dimension.h"
#include "three_dimensions.h"

using namespace std;


int main() {
    unsigned int n = 100;
    double rho_max = 8.0;

    one_dimension(n);

    three_dimensions(n, rho_max);


    return 0;
}
