#include "../lib/secret.h"

bool secret::is_secret_code(string &code)
{
    vector<int> encryptedCode = encryptation.to_decimal(encryptation.to_sha256(code));

    if (secret_code == encryptedCode)
    {
        return true;
    }

    return false;
}

string secret::cypher_aes256(string &message)
{
    vector<unsigned char> key(custom_key.begin(), custom_key.end());

    vector<unsigned char> iv;

    string cypher_text = encryptation.to_base64(encryptation.to_aes256(message, key, iv));

    return cypher_text;
}

string secret::decipher_aes256(string &cypher_text)
{    
    vector<unsigned char> cipher_bytes = encryptation.from_base64(cypher_text);

    vector<unsigned char> key(custom_key.begin(), custom_key.end());

    vector<unsigned char> iv;

    string plaintext = encryptation.from_aes256(cipher_bytes, key, iv);

    return plaintext;
}

void secret::execute()
{
    string message = decipher_aes256(cipher_message);

    cout << message << endl;
}

string secret::get_cipher_message()
{
    return cipher_message;
}

