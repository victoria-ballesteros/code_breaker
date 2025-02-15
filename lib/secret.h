#ifndef SECRET_H
#define SECRET_H

#include "encrypt.h"
#include <string>
#include <vector>

class secret
{
    std::vector<int> secret_code = {94, 193, 160, 201, 157, 66, 134, 1, 206, 66, 180, 7, 174, 156, 103, 94,
                                    8, 54, 168, 186, 89, 28, 140, 166, 226, 162, 207, 85, 99, 217, 127, 240};

    encrypt encryptation;

public:
    bool is_secret_code(std::string code);
};

#endif