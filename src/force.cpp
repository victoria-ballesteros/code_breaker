#include "../lib/force.h"

std::atomic<bool> force::found(false);
secret force::threads_check;

void force::execute()
{
    unsigned int num_threads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    force::found.store(false); 

    for (auto const &[month, days] : months_dictionary)
    {
        int step = days / num_threads + 1;

        for (int i = 0; i < num_threads; i++)
        {
            int start = i * step + 1;
            int end = std::min(start + step, days + 1);

            if (start <= days)
            {
                threads.emplace_back(test_combinations, month, start, end);
            }
        }
    }

    for (auto &t : threads)
    {
        t.join();
    }
}

bool force::test_combinations(const char month, int start_day, int end_day)
{
    for (int day = start_day; day < end_day && !found.load(); ++day)
    {
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << day;
        std::string code = oss.str() + month;

        bool flag = threads_check.is_secret_code(code);

        if (flag)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(0, 2);

            int random_number = distrib(gen);

            found.store(true);
            std::cout << "Don't try to cheat, Mike!... ";

            if (random_number == 0)
            {
                std::cout << "Fine, I'll give you a clue: " << code[random_number] << " _ _" << std::endl;
            }
            else if (random_number == 1)
            {
                std::cout << "You can do it alone, but okay: " << "_ " << code[random_number] << " _" << std::endl;
            }
            else
            {
                std::cout << "*Insert angry emoji*: " << "_ _ " << code[random_number] << std::endl;
            }

            return true;
        }
    }
    return false;
}