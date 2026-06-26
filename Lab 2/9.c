// Power of a Number

#include <stdio.h>

void main()
{
    int base, exp;
    int power = 1;

    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &exp);

    for (int i = 1; i <= exp; i++)
        power *= base;

    printf("Power = %d", power);

}