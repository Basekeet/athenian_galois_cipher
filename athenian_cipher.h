#ifndef ATHENIAN_CIPHER

#define ATHENIAN_CIPHER

#include <string>

#include "cipher.h"
#include "galois.h"

#include <map>

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

    std::string crack(const std::string &s) {
        std::map<char, int> m;
        for (char sym : s) {
            m[sym]++;
        }

        if (m.size() < 2) {
            return s;
        }

        int m1 = -1, m2 = -1;
        char c1 = ' ', c2 = ' ';

        for (std::pair<char, int> p : m) {
            if (p.second >= m1) {
                m2 = m1;
                m1 = p.second;

                c2 = c1;
                c1 = p.first;
            } else if (p.second >= m2) {
                m2 = p.second;
                c2 = p.first;
            }
        }

        galois_num x1 = get_num(' ');
        galois_num x2 = get_num('e');
        galois_num y1 = get_num(c1);
        galois_num y2 = get_num(c2);

        galois_num a = divide(sum(y2, y1), sum(x2, x1));
        galois_num b = sum(y1, prod(a, x1));
        
        AthenianCipher A(a, b);
        return A.decode(s);
    }
};

#endif