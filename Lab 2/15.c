// Armstrong Numbers from 1 to 1000

#include <stdio.h>

void main()
{
    int num, temp, rem, sum;

    printf("Armstrong Numbers from 1 to 1000:\n");

    for (num = 1; num <= 1000; num++)
    {
        temp = num;
        sum = 0;

        while (temp > 0)
        {
            rem = temp % 10;
            sum += rem * rem * rem;
            temp /= 10;
        }

        if (sum == num)
            printf("%d ", num);
    }
}