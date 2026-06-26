// WAP to find the largest element in the array using Pointer

#include <stdio.h>

void main()
{
    int arr[100], n, i, max;
    int *p;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    p = arr;
    max = *p;

    for(i = 1; i < n; i++)
    {
        if(*(p + i) > max)
            max = *(p + i);
    }

    printf("Largest element = %d", max);

}