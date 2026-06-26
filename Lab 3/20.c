//Program to Check Whether an Array Contains Duplicate Numbers

#include <stdio.h>

void main()
{
    int n, i, j, duplicate = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                duplicate = 1;
                break;
            }
        }
        if(duplicate)
            break;
    }

    if(duplicate)
        printf("Array contains duplicate number.");
    else
        printf("Array does not contain duplicate number.");

}

