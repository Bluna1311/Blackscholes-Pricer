#include <iostream>
#include "VanillaOption.h"
#include "AmericanOption.h"

int main() {
	double S = 100;
	double K = 90;
	double r = 0.05;
	double sigma = 0.2;
	double T = 1;
	int callPutFlag = 1;

	VanillaOption vanOptCall(S, K, r, sigma, T, callPutFlag);
	AmericanOption amOptCall(S, K, r, sigma, T, callPutFlag);

	std::cout << "Vanilla option price: " << vanOptCall.price() << std::endl;
	std::cout << "American option price: " << amOptCall.price() << std::endl;

	callPutFlag = 0;

	VanillaOption vanOptPut(S, K, r, sigma, T, callPutFlag);
	AmericanOption amOptPut(S, K, r, sigma, T, callPutFlag);

	std::cout << "Vanilla option price: " << vanOptPut.price() << std::endl;
	std::cout << "American option price: " << amOptPut.price() << std::endl;

	return 0;
}