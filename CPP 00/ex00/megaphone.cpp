#include <iostream>
#include <string>
#include <cctype>

/*
 * Converts and outputs all provided arguments in uppercase.
 * Manually inserts a space between each argument.
 * If no arguments are provided, outputs a default noise message.
 */
int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND SMASHING NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (size_t j = 0; j < str.length(); j++)
			{
				std::cout << (char)std::toupper(str[j]);
			}
			
			if (i < argc - 1)
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	
	return 0;
}