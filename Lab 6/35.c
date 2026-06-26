// WAP to get and print the array elements using Pointer

#include <stdio.h>

void main()
{
    int arr[100], n, *p, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    p = arr;

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }

    printf("Array elements are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }

}