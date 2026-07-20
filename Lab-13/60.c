// 6351028624 dhruv Limbasiya
#include "stdio.h"
#include "stdlib.h"
#include "String.h"
#define MAX 50

char S[MAX];
int TOP = -1;

void push(char x);
char pop();

int main()
{
    int i = 0, count = 0;
    char str[20];
    printf("Enter The String :");
    gets(str);
    // scanf("%s", str);

    char c = str[0];
    while (c != '\0')
    {
        if (c == 'a')
        {
            push(c);
        }
        else if (c == 'b')
        {
            count++;
        }
        else
        {
            printf("Invalid input");
            return 0;
        }

        c = str[++i];
    }

    if (TOP + 1 == count)
    {
        printf("Valid String ");
    }
    else
    {
        printf("Invalid String ");
    }

    return 0;
}

void push(char x)
{ // insrt element at the top of stack
    if (TOP >= MAX - 1)
    {
        printf("OVERFLOW !!!");
        return;
    }
    else
    {
        S[++TOP] = x;
        return;
    }
}

