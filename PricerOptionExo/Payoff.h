#pragma once

#include <string>
#include <iostream>
#include <algorithm>

class Payoff
{

public:
	virtual ~Payoff(){}

	virtual double operator()(double s_t) const = 0;

};


class PayoffCall : public Payoff 
{
private:
	double k;

public:
	PayoffCall(double strike);

	virtual double operator()(double s_t) const override;

};

class PayoffPut : public Payoff
{
private:
	double k;

public:
	PayoffPut(double strike);

	virtual double operator()(double s_t) const override;

};

