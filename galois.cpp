#include "galois.h"
#include <iostream>

const unsigned int G_N = 5;
const unsigned int G_P = 2;

const galois_num X5 = 5;

galois_num sum(galois_num a, galois_num b) {
    return a ^ b;
}

galois_num prod(galois_num a, galois_num b) {
    galois_num res = 0;

    galois_num i = 0;
    while ((1ull << i) <= a) {
        galois_num j = 0;
        while ((1ull << j) <= b) {
            if (((1ull << i) & a) && ((1ull << j) & b)) {
                res ^= (1 << (i + j));
            }
            j++;
        }
        i++;
    }

    return normalize(res);
}

galois_num divide(galois_num a, galois_num b) {
    galois_num res = b;
    while (prod(res, b) != 1) {
        res = prod(res, b);
    }
    return prod(res, a);
}

galois_num normalize(galois_num a) {
    galois_num curr = X5;
    unsigned long long shift = G_N;
    while ((1ull << shift) <= a) {
        a = sum(a, a & (1 << shift) ? curr : 0);
        a = sum(a, a & (1 << shift));
        curr = normalize(curr * G_P);
        shift++;
    }
    return a;
}