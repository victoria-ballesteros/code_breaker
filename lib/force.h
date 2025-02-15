#ifndef FORCE_H
#define FORCE_H

#include <atomic>
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
#include <thread>
#include <vector>

#include "secret.h"

class force
{

    std::map<char, int> months_dictionary = {
        {'1', 31}, {'2', 29}, {'3', 31}, {'4', 30}, {'5', 31}, {'6', 30}, {'7', 31}, {'8', 31}, {'9', 30}};

    static std::atomic<bool> found;

    static secret threads_check;

public:
    void execute();
    static bool test_combinations(const char month, int start_day, int end_day);
};

#endif