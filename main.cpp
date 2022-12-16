#include <iostream>
#include <fstream>
#include "caesar_cipher.h"
// #include "athenian_cipher.h"
 #include "recurrent_cipher.h"

int main() {
    RecurrentCipher c(11, 5, 13, 29);

    // std::ifstream in("input.txt");

    // std::string res;
    // for (std::string line; std::getline(in, line);) {
    //     res += line + " ";
    // }

    std::string s = c.encode("KilluaGon");
    std::string d = c.decode(s);
    std::cout << s << "\n";
    std::cout << d << "\n";
    // std::cout << s << "\n";
    // std::cout << c.crack(s) << "\n";
}
