#include "../lib/encrypt.h"

vector<uint8_t> encrypt::to_sha256(const string &input)
{
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    if (!ctx)
    {
        throw runtime_error("Error: EVP_MD_CTX");
    }

    vector<uint8_t> hash(EVP_MD_size(EVP_sha256()));

    unsigned int length = 0;

    EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr);
    EVP_DigestUpdate(ctx, input.c_str(), input.size());
    EVP_DigestFinal_ex(ctx, hash.data(), &length);

    EVP_MD_CTX_free(ctx);

    return hash;
}

vector<int> encrypt::to_decimal(const vector<uint8_t> &hash)
{
    vector<int> decimal;

    for (uint8_t byte : hash)
    {
        decimal.push_back((int)byte);
    }

    return decimal;
}

vector<unsigned char> encrypt::to_aes256(const string &plaintext, const vector<unsigned char> &key, vector<unsigned char> &iv)
{
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx)
        exit(1);

    // Inicializar el IV si no se pasó un valor
    iv.resize(16);
    if (!RAND_bytes(iv.data(), iv.size()))
        exit(1);

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key.data(), iv.data()) != 1)
        exit(1);

    int len;
    vector<unsigned char> buffer(plaintext.size() + 16); // Espacio para el padding
    if (EVP_EncryptUpdate(ctx, buffer.data(), &len, reinterpret_cast<const unsigned char *>(plaintext.data()), plaintext.size()) != 1)
        exit(1);

    int paddingLen;
    if (EVP_EncryptFinal_ex(ctx, buffer.data() + len, &paddingLen) != 1)
        exit(1);

    buffer.resize(len + paddingLen); // Ajustar el tamaño del buffer

    // Incluye el IV al principio del texto cifrado
    vector<unsigned char> ciphertext;
    ciphertext.insert(ciphertext.end(), iv.begin(), iv.end());         // Agregar IV
    ciphertext.insert(ciphertext.end(), buffer.begin(), buffer.end()); // Agregar datos cifrados

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext;
}

string encrypt::from_aes256(vector<unsigned char> &cipher_bytes, const vector<unsigned char> &key, vector<unsigned char> &iv)
{
    string decrypted_text;

    // Extraer IV de los primeros 16 bytes
    iv.assign(cipher_bytes.begin(), cipher_bytes.begin() + 16);
    cipher_bytes.erase(cipher_bytes.begin(), cipher_bytes.begin() + 16); // Eliminar IV de los datos cifrados

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx)
        exit(1);

    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key.data(), iv.data()) != 1)
        exit(1);

    int len;
    vector<unsigned char> decrypted_buffer(cipher_bytes.size()); // Usar un buffer separado para el texto descifrado

    if (EVP_DecryptUpdate(ctx, decrypted_buffer.data(), &len, cipher_bytes.data(), cipher_bytes.size()) != 1)
        exit(1);

    int paddingLen;
    if (EVP_DecryptFinal_ex(ctx, decrypted_buffer.data() + len, &paddingLen) != 1)
        exit(1);

    decrypted_buffer.resize(len + paddingLen); // Ajustar el tamaño del buffer de salida
    decrypted_text.assign(decrypted_buffer.begin(), decrypted_buffer.end());

    EVP_CIPHER_CTX_free(ctx);

    return decrypted_text;
}

string encrypt::to_base64(const vector<unsigned char> &in)
{
    string out;

    const char b[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    int val = 0, valb = -6;
    for (unsigned char c : in)
    {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0)
        {
            out.push_back(b[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6)
    {
        out.push_back(b[((val << 8) >> (valb + 8)) & 0x3F]);
    }
    while (out.size() % 4)
    {
        out.push_back('=');
    }

    return out;
}

vector<unsigned char> encrypt::from_base64(const string &in)
{
    vector<unsigned char> out;
    vector<int> T(256, -1);

    const char b[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    for (int i = 0; i < 64; i++)
    {
        T[b[i]] = i;
    }

    int val = 0, valb = -8;
    for (unsigned char c : in)
    {
        if (T[c] == -1)
            break;
        val = (val << 6) + T[c];
        valb += 6;
        if (valb >= 0)
        {
            out.push_back(static_cast<unsigned char>((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    return out;
}
