#ifndef CIPHER

#define CIPHER

#include <string>
#include <iostream>

const std::string ALPHABET = "abcdefghijklmnopqrstuvwxyz _',-.";

class Cipher {
protected:

    unsigned long long get_num(char c) {
        unsigned int tmp = ALPHABET.find(c);
        if (tmp != std::string::npos) {
            return tmp;
        } else {
            throw std::invalid_argument("There is no input char in APHABET");
        }
    }

    char get_char(unsigned long long n) {
        if (n >= ALPHABET.size()) {
            throw std::invalid_argument("N is larger than alphabet size");
        }
        return ALPHABET[n]; 
    }   

    std::string format_string(const std::string &s) {
        std::string res = "";

        for (size_t i = 0; i < s.size(); i++) {
            char tmp = tolower(s[i]);
            if (ALPHABET.find(tmp) != std::string::npos) {
                res += tmp;   
            } else {
                std::cout << "Symbo " << s[i] << " rid\n";
            }
        }

        return res;
    }

public:

    virtual std::string decode(const std::string &s);
    virtual std::string encode(const std::string &s);

};

#endif