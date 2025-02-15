#ifndef HELPER_H
#define HELPER_H

#include <fstream>
#include <iostream>
#include <string>

class helper
{
public:
    bool print_txt(const char *filePath);

    bool is_valid(const std::string input);
};

#endif
