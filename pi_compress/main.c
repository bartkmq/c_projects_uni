#include <stdio.h>
#include "pi.h"

#define lli long long int

int main()  {
    lli digit = pi_calc_digit(1);
    printf((int)digit);
}