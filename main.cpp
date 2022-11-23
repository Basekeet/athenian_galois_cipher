#include <iostream>

#include "caesar__cipher.h"
#include "athenian_cipher.h"
#include "recurrent_cipher.h"

int main() {
    RecurrentCipher c(3, 10, 2, 12);

    std::cout << c.encode("my mother name is alena") << "\n";
    std::cout << c.decode(c.encode("my mother name is alena")) << "\n";
}