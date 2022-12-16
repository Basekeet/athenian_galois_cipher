#ifndef RECURRENT_CIPHER

#define RECURRENT_CIPHER

#include <string>

#include <map>
#include "cipher.h"
#include "galois.h"

class RecurrentCipher : Cipher {
private:
    galois_num al1;
    galois_num be1;
    galois_num al2;
    galois_num be2;

    bool analyse_string(const std::string& s) {
        std::map<char, int> m;
        for (char sym : s) {
            m[sym]++;
        }

        if (m.size() < 3) {
            return false;
        }

        int m1 = -1, m2 = -1, m3 = -1;
        char c1 = ' ', c2 = ' ', c3 = ' ';

        for (std::pair<char, int> p : m) {
            if (p.second >= m1) {
                m3 = m2;
                m2 = m1;
                m1 = p.second;

                c3 = c2;
                c2 = c1;
                c1 = p.first;
            } else if (p.second >= m2) {
                m3 = m2;
                m2 = p.second;
                
                c3 = c2;
                c2 = p.first;
            } else if (p.second >= m3) {
                m3 = p.second;
                c3 = p.first;
            }
        }

        return c1 == ' ' && c2 == 'e' && c3 == 't';
    }
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
            res += get_char(sum(prod(get_num(formatted_string[0]), al1), be1));
        } 
        if (s.size() >= 2) {
            res += get_char(sum(prod(get_num(formatted_string[1]), al2), be2));
        }

        galois_num coefs[4] = {al1, be1, al2, be2};

        for (size_t i = 2; i < formatted_string.size(); i++) {
            char sym = formatted_string[i];
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
            res += get_char(divide(sum(get_num(formatted_string[0]), be1), al1));
        } 
        if (s.size() >= 2) {
            res += get_char(divide(sum(get_num(formatted_string[1]), be2), al2));
        }

        galois_num coefs[4] = {al1, be1, al2, be2};

        for (size_t i = 2; i < formatted_string.size(); i++) {
            char sym = formatted_string[i];
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

    std::string crack(const std::string &s) {
        std::string tmp = s;

        while(!analyse_string(tmp)) {
            tmp = encode(tmp);
        }
        return tmp;
    }
};

#endif