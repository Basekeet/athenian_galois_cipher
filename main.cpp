#include <iostream>
#include <string>
#include <fstream>
#include "caesar_cipher.h"
#include "athenian_cipher.h"
 #include "recurrent_cipher.h"

int main() {
    int mode;
    int ci;

    std::cout << "1 encode, 2 decode, 3 crack\n";
    std::cin >> mode;

    std::cout << "1,2 athenian,3 recurrent \n";
    std::cin >> ci;

    if (mode == 1) {
        if (ci == 1) {
            std::cout << "key:\n";
            std::string s;
            std::cin >> s;
            CaesarCipher c(s);
            std::cout << "STR: ";
            std::cin >> s;
            std::cout << c.encode(s) << "\n";
        } else if (ci == 2) {
            std::cout << "keys:\n";
            galois_num g1, g2;
            std::cin >> g1 >> g2;
            AthenianCipher c(g1, g2);
            std::cout << "STR: ";
            std::string s;
            std::cin >> s;
            std::cout << c.encode(s) << "\n";
        } else if (ci == 3) {
            std::cout << "keys:\n";
            galois_num g1, g2, g3, g4;
            std::cin >> g1 >> g2 >> g3 >> g4;
            RecurrentCipher c(g1, g2, g3, g4);
            std::cout << "STR: ";
            std::string s;
            std::cin >> s;
            std::cout << c.encode(s) << "\n";
        }
    } else if (mode == 2) {
        if (ci == 1) {
            std::cout << "key:\n";
            std::string s;
            std::cin >> s;
            CaesarCipher c(s);
            std::cout << "STR: ";
            std::cin >> s;
            std::cout << c.decode(s) << "\n";
        } else if (ci == 2) {
            std::cout << "keys:\n";
            galois_num g1, g2;
            std::cin >> g1 >> g2;
            AthenianCipher c(g1, g2);
            std::cout << "STR: ";
            std::string s;
            std::cin >> s;
            std::cout << c.decode(s) << "\n";
        } else if (ci == 3) {
            std::cout << "keys:\n";
            galois_num g1, g2, g3, g4;
            std::cin >> g1 >> g2 >> g3 >> g4;
            RecurrentCipher c(g1, g2, g3, g4);
            std::cout << "STR: ";
            std::string s;
            std::cin >> s;
            std::cout << c.decode(s) << "\n";
        }
    } else if (mode == 3) {
        if (ci == 2) {
            AthenianCipher c(0, 0);
            std::cout << "STR: ";
            std::string s;
            std::cin >> s;
            std::cout << c.crack(s);
        } else if (ci == 3) {
            std::cout << "keys:\n";
            galois_num g1, g2, g3, g4;
            std::cin >> g1 >> g2 >> g3 >> g4;
            RecurrentCipher c(g1, g2, g3, g4);
            std::cout << "STR: ";
            std::string s;
            std::cin >> s;
            std::cout << c.crack(s) << "\n";
        }
    }
}
