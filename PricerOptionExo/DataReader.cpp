#include "DataReader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

DataReader::DataReader(const std::string& filename) : filename_(filename){}

std::vector<OHLCVData> DataReader::read() 
{
	std::ifstream file(filename_);
	if (!file.is_open())
	{
		throw std::runtime_error("Impossible d'ouvrir le fichier :" + filename_);
	}

	std::vector<OHLCVData> data;
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		if (!line.empty()) {
			data.push_back(parseline(line));
		}
	}
	return data;
}

OHLCVData DataReader::parseline(const std::string& line) 
{
	std::stringstream ss(line);
	std::string token;
	OHLCVData row;

    std::getline(ss, row.date, ',');

    std::getline(ss, token, ',');
    row.adjClose = std::stod(token);

    std::getline(ss, token, ',');
    row.close = std::stod(token);

    std::getline(ss, token, ',');
    row.high = std::stod(token);

    std::getline(ss, token, ',');
    row.low = std::stod(token);

    std::getline(ss, token, ',');
    row.open = std::stod(token);

    std::getline(ss, token, ',');
    row.volume = std::stoll(token);

    std::getline(ss, token, ',');
    row.returns = std::stod(token);

    std::getline(ss, token, ',');
    row.volatility20d = std::stod(token);

    std::getline(ss, token, ',');
    row.ma50 = std::stod(token);

    std::getline(ss, token, ',');
    row.trend = std::stod(token);

    return row;

}



