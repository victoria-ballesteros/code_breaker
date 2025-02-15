#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <openssl/evp.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>

class encrypt
{
public:
    std::vector<uint8_t> sha256(const std::string &input);
    std::vector<int> decimal(const std::vector<uint8_t> hash);
};

#endif
