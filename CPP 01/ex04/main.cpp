#include <iostream>
#include <fstream>
#include <string>

/* Replaces every occurrence of s1 with s2 using find() and substr() */
std::string replace_content(std::string content, const std::string& s1, const std::string& s2) 
{
    if (s1.empty())
        return content;
    
    std::string result;
    size_t start = 0;
    size_t pos;

    while ((pos = content.find(s1, start)) != std::string::npos) {
        result += content.substr(start, pos - start);
        result += s2;
        start = pos + s1.length();
    }
    result += content.substr(start);
    return result;
}

/* Handles file I/O and validates the command line arguments */
int main(int argc, char** argv) 
{
    if (argc != 4) {
        std::cerr << "Usage: ./sed_is_for_losers <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream ifs(filename.c_str());
    if (!ifs.is_open()) {
        std::cerr << "Error: Cannot open input file" << std::endl;
        return 1;
    }

    std::string content;
    std::string line;
    while (std::getline(ifs, line)) {
        content += line;
        if (!ifs.eof())
            content += "\n";
    }
    ifs.close();

    std::ofstream ofs((filename + ".replace").c_str());
    if (!ofs.is_open()) {
        std::cerr << "Error: Cannot create output file" << std::endl;
        return 1;
    }

    ofs << replace_content(content, s1, s2);
    ofs.close();

    return 0;
}