#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    int a[n][2];

    for (int i = 0; i < n; i++)
    {
        printf("Enter interval %d: ", i + 1);
        scanf("%d %d", &a[i][0], &a[i][1]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][0] > a[j][0])
            {
                int temp;

                temp = a[i][0];
                a[i][0] = a[j][0];
                a[j][0] = temp;

                temp = a[i][1];
                a[i][1] = a[j][1];
                a[j][1] = temp;
            }
        }
    }

    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[index][1] >= a[i][0])
        {
            if (a[i][1] > a[index][1])
            {
                a[index][1] = a[i][1];
            }
        }
        else
        {
            index++;

            a[index][0] = a[i][0];
            a[index][1] = a[i][1];
        }
    }

    printf("Merged intervals:\n");
    printf("{");
    for (int i = 0; i <= index; i++)
    {
        printf("(%d, %d), ", a[i][0], a[i][1]);
    }
    printf("}");

    return 0;
}