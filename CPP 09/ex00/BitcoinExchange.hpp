#pragma once

#include <string>
#include <map>

class BitcoinExchange {
private:
    std::map<std::string, float> _data;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    // Loads the exchange rate database from a CSV file
    void loadDatabase(const std::string& filename);
    
    // Processes the input file and prints calculated results
    void processInput(const std::string& filename);
};