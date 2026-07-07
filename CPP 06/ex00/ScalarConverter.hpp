#pragma once

#include <string>

class ScalarConverter {
public:
	/*
	** Deleted Constructors: Instantiation strictly forbidden.
	*/
	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter& other) = delete;
	ScalarConverter& operator=(const ScalarConverter& other) = delete;
	~ScalarConverter() = delete;

	/*
	** convert: Parses literal and outputs char, int, float, and double.
	*/
	static void convert(const std::string& literal);
};