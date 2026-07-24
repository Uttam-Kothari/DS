#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 50

char s[MAX];
int TOP = -1;

void push(char x)
{
    if (TOP >= MAX-1)
    {
        printf("OVERFLOW !!!");
        return;
    }
    else
    {
        s[++TOP] = x;
    }
}

char pop()
{

    if (TOP <= -1)
    {
        printf("UNDERFLOW !!!");
        return -1;
    }
    else
    {
        return s[TOP--];
    }
}

int main()
{
    char str[50];
    int i = 0,t;
    
    printf("How many string enter: ");
    scanf("%d",&t);

    printf("enter the string:");
    scanf("%s", str);
    while (str[i] != '\0')
    {

        if ((str[i] == '(') || (str[i] == '[') || (str[i] == '{'))
        {
            push(str[i]);
        }

        else if ((str[i] == ']') || (str[i] == ')') || (str[i] == '}'))
        {

            if ((s[TOP] == '[' && (str[i] == ']')) || (s[TOP] == '(' && (str[i] == ')')) || (s[TOP] == '{' && (str[i] == '}')))
            {
                pop();
            }
            else
            {
                printf("invalid string");
                return 0;
            }
        }
        i++;
    }

    if (TOP == -1)
    {
        printf("valid string\n");
        return 0;
    }
    else
    {
        printf("invalid string");
    }
    return 0;
}