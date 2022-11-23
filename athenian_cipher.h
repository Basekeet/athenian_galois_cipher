#ifndef ATHENIAN_CIPHER

#define ATHENIAN_CIPHER

#include <string>

#include "cipher.h"
#include "galois.h"

class AthenianCipher : Cipher {
private:
    galois_num al;
    galois_num be;

public:

    AthenianCipher(galois_num _al, galois_num _be) {
        al = normalize(_al), be = _be;
    } 

    std::string encode(const std::string &s) {
        std::string formatted_string = format_string(s);
        std::string res = "";

        for (char sym : formatted_string) {
            res += get_char(sum(prod(get_num(sym), al), be));
        }

        return res;
    };

    std::string decode(const std::string &s) {
        std::string formatted_string = format_string(s);
        std::string res = "";

        for (char sym : formatted_string) {
            res += get_char(divide(sum(get_num(sym), be), al));
        }

        return res;
    };
};

#endif