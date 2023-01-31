#ifndef AMERICAN_OPTION_H
#define AMERICAN_OPTION_H

#include "Option.h"

class AmericanOption : public Option {
public:
	AmericanOption(double S_, double K_, double r_, double sigma_, double T_, int callPutFlag_);
	double price();
};

#endif // AMERICAN_OPTION_H
