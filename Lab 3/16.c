//Program to Read and Display n Numbers Using an Array

#include <stdio.h>

void main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array elements are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

}
