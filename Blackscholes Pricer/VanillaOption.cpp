#include "VanillaOption.h"



VanillaOption::VanillaOption(double S_, double K_, double r_, double sigma_, double T_, int callPutFlag_) {
    S = S_;
    K = K_;
    r = r_;
    sigma = sigma_;
    T = T_;
    callPutFlag = callPutFlag_;
}

double VanillaOption::price() {
    double d1 = (log(S / K) + (r + sigma * sigma / 2) * T) / (sigma * sqrt(T));

    double d2 = d1 - sigma * sqrt(T);
    if (callPutFlag == 1) {
        C = S * cdf(d1) - K * exp(-r * T) * cdf(d2);
        return C;
    }
    else {
        P = K * exp(-r * T) * cdf(-d2) - S * cdf(-d1);
        return P;
    }
}

double VanillaOption::cdf(double x) {
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
