// Replace 1st Number with 2nd Number in an Array and Print Its Index

#include <stdio.h>

void main() {
    int arr[100], n, oldNum, newNum, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to replace: ");
    scanf("%d", &oldNum);

    printf("Enter new number: ");
    scanf("%d", &newNum);

    printf("Indexes where replacement occurred: ");

    for(i = 0; i < n; i++) {
        if(arr[i] == oldNum) {
            arr[i] = newNum;
            printf("%d ", i);
        }
    }

    printf("\nFinal Array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}






