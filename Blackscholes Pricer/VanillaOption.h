#ifndef VANILLA_OPTION_H
#define VANILLA_OPTION_H

#include "Option.h"

class VanillaOption : public Option {
public:
	VanillaOption(double S_, double K_, double r_, double sigma_, double T_, int callPutFlag_);
	double price();

private:
	double cdf(double x);
};

#endif // VANILLA_OPTION_H
