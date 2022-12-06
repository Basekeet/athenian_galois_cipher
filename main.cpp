#include <iostream>
#include <fstream>
#include "caesar__cipher.h"
#include "athenian_cipher.h"
#include "recurrent_cipher.h"

int main() {
    RecurrentCipher c(13, 15, 2, 14);

    std::ifstream in("input.txt");

    std::string res;
    for (std::string line; std::getline(in, line);) {
        res += line + " ";
    }

    std::string s = c.encode(res);
    std::cout << s << "\n";
    std::cout << c.crack(s) << "\n";
}