// Sum of Series

#include <stdio.h>

void main()
{
    int n, i;
    int sum = 0, temp = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        temp += i;
        sum += temp;
    }

    printf("Sum = %d", sum);
}