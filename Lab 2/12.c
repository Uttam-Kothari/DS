// Prime Number Check

#include <stdio.h>

void main()
{
    int n, i, temp = 1;

    printf("Enter number: ");
    scanf("%d", &n);

    if (n <= 1)
        temp = 0;

    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            temp = 0;
            break;
        }
    }

    if (temp)
        printf("Prime");
    else
        printf("Not Prime");
}