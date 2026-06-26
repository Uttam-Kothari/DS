// Insert a Number in a Sorted Array (Ascending Order)


#include <stdio.h>

void main() {
    int arr[100], n, num, i, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to insert: ");
    scanf("%d", &num);

    for(i = 0; i < n; i++) {
        if(arr[i] > num)
            break;
    }

    pos = i;

    for(i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = num;
    n++;

    printf("Array after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

}