//Insert a Number at a Given Location in an Array

#include <stdio.h>

void main() {
    int arr[100], n, pos, num, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);

    printf("Enter number to insert: ");
    scanf("%d", &num);

    for(i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = num;
    n++;

    printf("Array after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

}
