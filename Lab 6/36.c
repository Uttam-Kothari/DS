// WAP to calculate the sum of n numbers using Pointer

#include <stdio.h>

void main()
{
    int arr[100], n, i, sum = 0;
    int *p;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    p = arr;

    for(i = 0; i < n; i++)
        sum += *(p + i);

    printf("Sum = %d", sum);

}