// WAP to Print Pascal Triangle

#include <stdio.h>

void main() {
    int n, i, j;
    int num;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        for ( j = 0; j < n-i; j++)
        {
            printf("   ");
        }
        
        num = 1;

        for(j = 0; j <= i; j++) {
            printf("%d  ", num);
            num = num * (i - j) / (j + 1);
        }

        printf("\n");
    }
}

// ### Output (n = 5)

//          1
//        1   1
//      1   2   1
//    1   3   3   1
//  1   4   6   4   1