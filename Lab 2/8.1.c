// Factorial Using Loop

#include <stdio.h>

void main()
{
    int n, i;
    int fact = 1;

    printf("Enter number: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        fact *= i;

    printf("Factorial = %d", fact);
}

