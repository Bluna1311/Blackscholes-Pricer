#include "cdf.h"
#include <cmath>
/*
Abramowitz and Stegun approximation for CDF.
*/



double cdf(double x) {
    double b1 = 0.31938153;
    double b2 = -0.356563782;
    double b3 = 1.781477937;
    double b4 = -1.821255978;
    double b5 = 1.330274429;
    double p = 0.2316419;
    double c2 = 0.3989423;

    if (x >= 0.0) {
        double t = 1.0 / (1.0 + p * x);
        return (1.0 - c2 * std::exp(-x * x / 2.0) * t *
            (t * (t * (t * (t * b5 + b4) + b3) + b2) + b1));
    }
    else {
        double t = 1.0 / (1.0 - p * x);
        return (c2 * std::exp(-x * x / 2.0) * t *
            (t * (t * (t * (t * b5 + b4) + b3) + b2) + b1));
    }
}
