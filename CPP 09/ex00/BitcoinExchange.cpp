#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) _data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// Loads the database into a map for fast lookup
void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("Error: could not open database.");
    
    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        size_t sep = line.find(',');
        if (sep != std::string::npos) {
            _data[line.substr(0, sep)] = std::stof(line.substr(sep + 1));
        }
    }
}

// Parses input file and calculates values using the closest available date
void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("Error: could not open file.");
    
    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        size_t sep = line.find(" | ");
        if (sep == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = line.substr(0, sep);
        std::string valStr = line.substr(sep + 3);
        
        try {
            float val = std::stof(valStr);
            if (val < 0) throw std::runtime_error("not a positive number.");
            if (val > 1000) throw std::runtime_error("too large a number.");
            
            // Find the closest date <= input date
            auto it = _data.lower_bound(date);
            if (it != _data.begin() && (it == _data.end() || it->first != date)) --it;
            
            std::cout << date << " => " << val << " = " << val * it->second << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}