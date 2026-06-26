//Program to Find Position of the Smallest and Largest Number

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

    int smallest = arr[0], largest = arr[0];
    int smallPos = 0, largePos = 0;

    for(i = 1; i < n; i++)
    {
        if(arr[i] < smallest)
        {
            smallest = arr[i];
            smallPos = i;
        }

        if(arr[i] > largest)
        {
            largest = arr[i];
            largePos = i;
        }
    }

    printf("Smallest number = %d at position %d\n", smallest, smallPos + 1);
    printf("Largest number = %d at position %d\n", largest, largePos + 1);

}