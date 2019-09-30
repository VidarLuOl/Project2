#ifndef THREE_DIMENSIONS_H
#define THREE_DIMENSIONS_H

#include <armadillo>

using namespace arma;

vec three_dimensions(unsigned int n, double rho_max, bool timing);
double relative_error (int n, vec numerical);

#endif // THREE_DIMENSIONS_H
