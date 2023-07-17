#include "headers/utils.h"

bool is_valid_prime(int prime) {
    // make sure it's above the alphabet
    if (prime < 128) {
        return false;
    }
    // get factorial
    long long int factorial = 1;
    for (int i = 2; i <= prime; i++) {
        factorial *= i;
    }
    // Wilson’s Theorem
    return factorial % prime == prime - 1;
}

int next_prime(int x) {
    while (is_valid_prime(x)) {
        x++;
    }
    return x;
}