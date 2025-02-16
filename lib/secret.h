#ifndef SECRET_H
#define SECRET_H

#include "encrypt.h"
#include <string>
#include <vector>

class secret
{
    vector<int> secret_code = {94, 193, 160, 201, 157, 66, 134, 1, 206, 66, 180, 7, 174, 156, 103, 94,
                                    8, 54, 168, 186, 89, 28, 140, 166, 226, 162, 207, 85, 99, 217, 127, 240};

    encrypt encryptation;

    string custom_key = "SinMiedoAlExitoYConDolorDeCabeza";

    string cipher_message = "L/bCV3oxGeQhdSt5CbDuW6h2ds+lEgj5kCRu00uMsXOKt7er4oAXw2hDELIz81lN0DSDLqgFNeCTrp/DuEzcNqDkdn+Dv+GwH3Hu2x/PBjUe1yH5gJf6h7lGHo7m1hkosXfeYnRL2kuKchLIOIjD1TrV7myU2kgJZFOzE8iSEZw6SNAuwbbYNqE2QZqg+9vVGTjQGUZH8NsGtcjjTZQBxAtd6nTjAYR+NI0FKGrd1+Uy//IBPaFUdzediAhBSbw4FeQYNg+5nkojp6/RngQOBJolZA1NDJRAD1eAXLAqOOoXOWUv/Rp7cA0RwDs01V+3";

public:
    bool is_secret_code(string &code);

    string cypher_aes256(string &message);

    string decipher_aes256(string &cypher_text);

    void execute();

    string get_cipher_message();
};

#endif