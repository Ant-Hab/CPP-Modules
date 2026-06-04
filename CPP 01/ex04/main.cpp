#include <iostream>
#include <fstream>
#include <string>

/*
 * Validates arguments, searches for all occurrences of s1 in a file,
 * replaces them with s2, and writes the result to a new .replace file.
 */
void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
	if (s1.empty())
	{
		std::cout << "Search string can't be empty." << std::endl;
		return;
	}

	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cout << "Can't open input file." << std::endl;
		return;
	}

	std::string outname = filename + ".replace";
	std::ofstream outfile(outname.c_str());
	if (!outfile)
	{
		std::cout << "Can't create output file." << std::endl;
		return;
	}
	
	std::string line;
	while (std::getline(infile, line))
	{
		size_t position = 0;
		while ((position = line.find(s1, position)) != std::string::npos)
		{
			line = line.substr(0, position) + s2 + line.substr(position + s1.length());
			position += s2.length();
		}
		outfile << line << '\n';
	}
	
	infile.close();
	outfile.close();
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of parameters. Only 3 needed!" << std::endl;
		return 1;
	}
	
	replaceInFile(argv[1], argv[2], argv[3]);
	
	return 0;
}