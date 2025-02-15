#include "../lib/helper.h"

bool helper::print_txt(const char *filename)
{
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open())
    {
        return false;
    }

    while (getline(file, line))
    {
        std::cout << line << std::endl;
    }

    file.close();
    return true;
}

bool helper::is_valid(const std::string input)
{
    if (input.length() != 3)
    {
        std::cout << "The number of code's characters must be of 3." << std::endl;
        return false;
    }

    for (char c : input)
    {
        if (c < '0' || c > '9')
        {
            std::cout << "Only numeric characters accepted." << std::endl;
            return false;
        }
    }

    return true;
}
