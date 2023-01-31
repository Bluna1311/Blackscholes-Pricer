#ifndef OPTION_H
#define OPTION_H

#include <iostream>
#include <cmath>

class Option {
public:
	double S, K, r, sigma, T, C, P;
	int callPutFlag;


	virtual double price() = 0;
};

#endif // OPTION_H
