#include "AmericanOption.h"
#include <algorithm>
#include<vector>



AmericanOption::AmericanOption(double S_, double K_, double r_, double sigma_, double T_, int callPutFlag_) {
    S = S_;
    K = K_;
    r = r_;
    sigma = sigma_;
    T = T_;
    callPutFlag = callPutFlag_;
}

double AmericanOption::price() {
    int N = 100; // number of steps in the binomial tree
    double deltaT = T / N;
    double u = exp(sigma * sqrt(deltaT));
    double d = 1 / u;
    double q = (exp(r * deltaT) - d / u - d);

    // initialize the price and exercise price arrays
    std::vector<double> Stock(N + 1), V(N + 1), X(N + 1);
    for (int i = 0; i <= N; i++) {
        Stock[i] = S * pow(u, N - i) * pow(d, i);
        X[i] = K;
    }

    // initialize the option value array
    for (int i = 0; i <= N; i++) {
        if (callPutFlag == 1) {
            // Call option pricing
            V[i] = std::max(Stock[i] - K, 0.0);
        }
        else {
            // Put option pricing
            V[i] = std::max(K - Stock[i], 0.0);
        }
    }

    // work backwards through the tree to find the option price
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (callPutFlag == 1) {
                // Call option pricing
                V[j] = (q * V[j + 1] + (1 - q) * V[j]) / (1 + r * deltaT);
                X[j] = std::max(X[j], Stock[j] - K);
            }
            else {
                // Put option pricing
                V[j] = (q * V[j + 1] + (1 - q) * V[j]) / (1 + r * deltaT);
                X[j] = std::max(X[j], K - Stock[j]);
            }
        }
    }

    return V[0];
}
