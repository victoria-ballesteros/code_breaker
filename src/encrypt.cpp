#include "../lib/encrypt.h"

std::vector<uint8_t> encrypt::sha256(const std::string &input)
{
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    if (!ctx)
    {
        throw std::runtime_error("Error: EVP_MD_CTX");
    }

    std::vector<uint8_t> hash(EVP_MD_size(EVP_sha256()));
    
    unsigned int length = 0;

    EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr);
    EVP_DigestUpdate(ctx, input.c_str(), input.size());
    EVP_DigestFinal_ex(ctx, hash.data(), &length);

    EVP_MD_CTX_free(ctx);

    return hash;
}

std::vector<int> encrypt::decimal(const std::vector<uint8_t> hash)
{
    std::vector<int> decimal;

    for (uint8_t byte : hash)
    {
        decimal.push_back((int)byte);
    }

    return decimal;
}