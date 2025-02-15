#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <iomanip>
#include <iostream>
#include <openssl/buffer.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <sstream>
#include <vector>

using namespace std;

class encrypt
{
public:
    vector<uint8_t> to_sha256(const string &input);

    vector<int> to_decimal(const vector<uint8_t> &hash);

    vector<unsigned char> to_aes256(const string &plaintext, const vector<unsigned char> &key, vector<unsigned char> &iv);

    string from_aes256(vector<unsigned char> &cipher_bytes, const vector<unsigned char> &key, vector<unsigned char> &iv);

    string to_base64(const vector<unsigned char> &in);

    vector<unsigned char> from_base64(const string& text);
};

#endif
