#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cctype>

enum e_type { CHAR, INT, FLOAT, DOUBLE, INVALID };

/*
** detectType: Determines the scalar type of the input string.
*/
static e_type detectType(const std::string& str)
{
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
		return DOUBLE;
	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
		return FLOAT;
	
	if (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]))
		return CHAR;
	
	char* end;
	long l = std::strtol(str.c_str(), &end, 10);
	if (*end == '\0' && str.length() > 0)
	{
		if (l >= std::numeric_limits<int>::min() && l <= std::numeric_limits<int>::max())
			return INT;
		return DOUBLE; 
	}
	
	if (str.length() > 1 && str[str.length() - 1] == 'f')
	{
		std::string temp = str.substr(0, str.length() - 1);
		std::strtod(temp.c_str(), &end);
		if (*end == '\0' && temp != "+" && temp != "-")
			return FLOAT;
	}
	
	std::strtod(str.c_str(), &end);
	if (*end == '\0' && str.length() > 0 && str != "+" && str != "-")
		return DOUBLE;
		
	return INVALID;
}

/*
** convert: Identifies type, converts, and casts to the other three.
*/
void ScalarConverter::convert(const std::string& str)
{
	e_type type = detectType(str);
	
	if (type == INVALID)
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		return;
	}

	char c = 0;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;
	
	bool charPossible = true;
	bool intPossible = true;
	
	switch (type)
	{
		case CHAR:
			c = str[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
			
		case INT:
			i = static_cast<int>(std::strtol(str.c_str(), NULL, 10));
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
				charPossible = false;
			break;
			
		case FLOAT:
			if (str == "nanf") f = std::numeric_limits<float>::quiet_NaN();
			else if (str == "+inff" || str == "inff") f = std::numeric_limits<float>::infinity();
			else if (str == "-inff") f = -std::numeric_limits<float>::infinity();
			else f = static_cast<float>(std::strtod(str.c_str(), NULL));
			
			d = static_cast<double>(f);
			
			if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
				charPossible = false;
			else
				c = static_cast<char>(f);
				
			if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
				intPossible = false;
			else
				i = static_cast<int>(f);
			break;
			
		case DOUBLE:
			if (str == "nan") d = std::numeric_limits<double>::quiet_NaN();
			else if (str == "+inf" || str == "inf") d = std::numeric_limits<double>::infinity();
			else if (str == "-inf") d = -std::numeric_limits<double>::infinity();
			else d = std::strtod(str.c_str(), NULL);
			
			f = static_cast<float>(d);
			
			if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
				charPossible = false;
			else
				c = static_cast<char>(d);
				
			if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
				intPossible = false;
			else
				i = static_cast<int>(d);
			break;
			
		default:
			break;
	}
	
	std::cout << "char: ";
	if (!charPossible)
		std::cout << "impossible\n";
	else if (std::isprint(c))
		std::cout << "'" << c << "'\n";
	else
		std::cout << "Non displayable\n";

	std::cout << "int: ";
	if (!intPossible)
		std::cout << "impossible\n";
	else
		std::cout << i << "\n";

	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf\n";
	else if (std::isinf(f))
		std::cout << (f > 0 ? "+inff" : "-inff") << "\n";
	else
	{
		std::cout << f;
		if (f - std::floor(f) == 0.0f)
			std::cout << ".0";
		std::cout << "f\n";
	}

	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan\n";
	else if (std::isinf(d))
		std::cout << (d > 0 ? "+inf" : "-inf") << "\n";
	else
	{
		std::cout << d;
		if (d - std::floor(d) == 0.0)
			std::cout << ".0";
		std::cout << "\n";
	}
}