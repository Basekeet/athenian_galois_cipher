#ifndef CAESAR_CIPHER

#define CAESAR_CIPHER

#include <string>

#include "cipher.h"
#include "galois.h"

class CaesarCipher : Cipher {
private:
    galois_num al;
    galois_num be;

public:

    CaesarCipher(galois_num _al) {
        al = normalize(_al);
    } 

    std::string encode(const std::string &s) {
        std::string formatted_string = format_string(s);
        std::string res = "";

        for (char sym : formatted_string) {
            res += get_char(sum(get_num(sym), al));
        }

        return res;
    };

    std::string decode(const std::string &s) {
        std::string formatted_string = format_string(s);
        std::string res = "";

        for (char sym : formatted_string) {
            res += get_char(sum(get_num(sym), al));
        }

        return res;
    };
};

#endif