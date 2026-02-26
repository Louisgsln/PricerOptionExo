#include "Payoff.h"

PayoffCall::PayoffCall(double strike) : K(strike){}
PayoffPut::PayoffPut(double strike) : K(strike) {}

double PayoffCall::operator()(double s_t) const 
{
	return std::max(s_t - K, 0.0);
}

double PayoffPut::operator()(double s_t) const
{
	return std::max(K - s_t, 0.0);
}


