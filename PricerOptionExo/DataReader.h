#pragma once

#include <string>
#include <vector>
#include "OHLCVData.h"

class DataReader
{
public:
	DataReader(const std::string& filename);
	std::vector<OHLCVData> read();
	std::vector<double> computeLogReturns(const std::vector<OHLCVData>& data);

private:
	std::string filename_;
	OHLCVData parseline(const std::string& line);
};

