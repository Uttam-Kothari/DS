#include "stdio.h"
#include "stdlib.h"
#include "String.h"
#define MAX 50

char S[MAX];
int TOP = -1;

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

char pop()
{ // removes and returns the element at top of stack
    if (TOP <= -1)
    {
        printf("UNDERFLOW !!!");
        return -1;
    }
    else
    {
        return S[TOP--];
    }
}

int main()
{
    int i = 0;
    char str[20];
    printf("Enter The String :");
    gets(str);
    // scanf("%s", str);

    char c = str[0];
    while (c != 'c')
    {
        push(c);
        c = str[++i];
    }

    i++;

    while (str[i] != '\0')
    {

        if (str[i++] != pop())
        {
            printf("Invalid String ");
            return 0;
        }
    }
    printf("Valid String ");
    return 0;
}
