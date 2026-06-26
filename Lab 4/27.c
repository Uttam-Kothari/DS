// Delete a Number from a Sorted Array (Ascending Order)

#include <stdio.h>

void main() {
    int arr[100], n, num, i, pos = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to delete: ");
    scanf("%d", &num);

    for(i = 0; i < n; i++) {
        if(arr[i] == num) {
            pos = i;
            break;
        }
    }

    if(pos == -1) {
        printf("Number not found.");
    } else {
        for(i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;

        printf("Array after deletion:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }
}