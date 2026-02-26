#pragma once
#include <string>

struct OHLCVData
{
    std::string date;
    double adjClose;
    double close;
    double high;
    double low;
    double open;
    long long volume;
    double returns;
    double volatility20d;
    double ma50;
    double trend;
};