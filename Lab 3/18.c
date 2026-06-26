// Program to Calculate Average of First n Numbers

#include <stdio.h>

void main()
{
    int n, i;
    float sum = 0, avg;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        sum += i;
    }

    avg = sum / n;

    printf("Average = %.2f", avg);
}