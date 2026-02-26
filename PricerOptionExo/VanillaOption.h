#pragma once

#include <iostream>
#include "Payoff.h"

class VanillaOption
{
private:
	std::unique_ptr<Payoff> payoff_;
	double T;
};

