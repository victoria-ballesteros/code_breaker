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

std::string helper::getCode()
{
    const char *clue = "../assets/clue.txt";
    std::string input;

    print_txt(clue);

    bool is_valid_input = false;

    while (!is_valid_input)
    {
        std::cout << "Code: ";
        std::cin >> input;

        is_valid_input = is_valid(input);
    }

    return input;
}

void helper::clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
