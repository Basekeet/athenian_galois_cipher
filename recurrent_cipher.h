#ifndef RECURRENT_CIPHER

#define RECURRENT_CIPHER

#include <string>

#include "cipher.h"
#include "galois.h"

class RecurrentCipher : Cipher {
private:
    galois_num al1;
    galois_num be1;
    galois_num al2;
    galois_num be2;

public:

    RecurrentCipher(galois_num _al1, galois_num _be1, galois_num _al2, galois_num _be2) {
        al1 = _al1;
        al2 = _al2;
        be1 = _be1;
        be2 = _be2;
    } 

    std::string encode(const std::string &s) {
        std::string formatted_string = format_string(s);
        std::string res = "";

        if (s.size() >= 1) {
            res += get_char(sum(prod(get_num(s[0]), al1), be1));
        } 
        if (s.size() >= 2) {
            res += get_char(sum(prod(get_num(s[1]), al2), be2));
        }

        galois_num coefs[4] = {al1, be1, al2, be2};

        for (int i = 2; i < s.size(); i++) {
            char sym = s[i];
            galois_num tmp_al = prod(coefs[0], coefs[2]);
            galois_num tmp_be = prod(coefs[1], coefs[3]);
            coefs[0] = coefs[2];
            coefs[1] = coefs[3];
            coefs[2] = tmp_al;
            coefs[3] = tmp_be;
            res += get_char(sum(prod(get_num(sym), tmp_al), tmp_be));
        }

        return res;
    };

    std::string decode(const std::string &s) {
        std::string formatted_string = format_string(s);
        std::string res = "";

        if (s.size() >= 1) {
            res += get_char(divide(sum(get_num(s[0]), be1), al1));
        } 
        if (s.size() >= 2) {
            res += get_char(divide(sum(get_num(s[1]), be2), al2));
        }

        galois_num coefs[4] = {al1, be1, al2, be2};

        for (int i = 2; i < s.size(); i++) {
            char sym = s[i];
            galois_num tmp_al = prod(coefs[0], coefs[2]);
            galois_num tmp_be = prod(coefs[1], coefs[3]);
            coefs[0] = coefs[2];
            coefs[1] = coefs[3];
            coefs[2] = tmp_al;
            coefs[3] = tmp_be;
            res += get_char(divide(sum(get_num(sym), tmp_be), tmp_al));
        }

        return res;
    };
};

#endif