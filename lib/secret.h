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

    string cipher_message = "el3XTwmmomznToihv+M8DtyMEd/eoE/FoO3BACjXPOvejABPDmALZVdNgRXuzYVznfOwij4RdmYai15t52Se8B2tR/Yo9zbCqUOIA9m2+mIEDtVXril1WN6IK/ohcozMnEDXaq1xMFNUUp1m4SueBcPsvhhkMoNK/nkI25mh4FkXfOGedSL6gd0iunA+gzZMJwDjoVnfWoZ8AG+rKw06KprGnn3jMjNmZvwvLDH9lnw38AHvCUC93ix9i2CrXi/UZdvSgrLA/uWO2sSPpRHz7P0gTl8Mar0xLa4K7CgF6BKhLisf2T99IATPCCqafxhR";

public:
    bool is_secret_code(string &code);

    string cypher_aes256(string &message);

    string decipher_aes256(string &cypher_text);

    void execute();

    string get_cipher_message();
};

#endif