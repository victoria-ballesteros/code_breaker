#include "../lib/secret.h"

bool secret::is_secret_code(std::string code)
{
    std::vector<int> encryptedCode = encryptation.decimal(encryptation.sha256(code));

    if (secret_code == encryptedCode)
    {
        return true;
    }

    return false;
}