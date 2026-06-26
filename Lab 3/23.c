// WAP to Sort N Names in Alphabetical Order

#include <stdio.h>
#include <string.h>

void main() {
    char name[100][50], temp[50];
    int n, i, j;

    printf("Enter number of names: ");
    scanf("%d", &n);

    printf("Enter names:\n");
    for(i = 0; i < n; i++) {
        scanf("%s", name[i]);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(strcmp(name[i], name[j]) > 0) {
                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);
            }
        }
    }

    printf("\nNames in alphabetical order:\n");
    for(i = 0; i < n; i++) {
        printf("%s\n", name[i]);
    }

}
// Example

// **Input:**

// 4
// Ravi
// Amit
// Kiran
// Bhavesh

// **Output:**

// Amit
// Bhavesh
// Kiran
// Ravi
