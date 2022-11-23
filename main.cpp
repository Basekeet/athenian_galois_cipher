#include <iostream>

#include "caesar__cipher.h"
#include "athenian_cipher.h"

int main() {
    AthenianCipher c(3, 10);

    std::cout << c.encode("abcdef") << "\n";
    std::cout << c.decode(c.encode("abcdef")) << "\n";
}