#ifndef CAESAR_CIPHER

#define CAESAR_CIPHER

#include <string>
#include <utility>

#include "cipher.h"
#include "galois.h"


class CaesarCipher : Cipher {
private:
    galois_num al{};
    galois_num be{};
    std::string z;

    unsigned long long get_num_z(char c) {
        unsigned int tmp = z.find(c);
        if (tmp != std::string::npos) {
            return tmp;
        } else {
            throw std::invalid_argument("There is no input char in Z");
        }
    }

public:
    explicit CaesarCipher(std::string key) {
        z = std::move(key);
    }

    std::string encode(const std::string &s) override {
        std::string formatted_string = format_string(s);
        std::string res;

        for (char sym : formatted_string) {
            res += z[get_num(sym)];
        }

        return res;
    };

    std::string decode(const std::string &s) override {
        std::string formatted_string = format_string(s);
        std::string res;

        for (char sym : formatted_string) {
            res += ALPHABET[get_num_z(sym)];
        }

        return res;
    };
};

#endif
