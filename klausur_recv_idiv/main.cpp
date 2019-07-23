#include <iostream>

unsigned int idiv_rec(unsigned a, unsigned b, unsigned &l, unsigned &h) {
    unsigned int m = (l + h) / 2;
    bool greater = m * b > a;
    h = greater ? m : h;
    l = greater ? l : m;
    if (h - 1 > 1) {
        return idiv_rec(a, b, l, h);
        std::cout << "CALLED" << std::endl;
    }
    else
        return 1;
}

unsigned int idiv_rec(unsigned int a, unsigned int b) {
    if (b == 0) exit(EXIT_FAILURE);
    unsigned int l = 0, h = a;
    return idiv_rec(a, b, l, h);
}

int main() {
    std::cout << idiv_rec(27, 3) << std::endl;
    return 0;
}