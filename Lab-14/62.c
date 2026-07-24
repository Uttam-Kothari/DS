#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char stack[100];
    int top = -1;

    printf("Enter string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '*')
        {
            if (top != -1)
                top--;
        }
        else
        {
            stack[++top] = str[i];
        }
    }

    stack[top + 1] = '\0';

    printf("Result = %s\n", stack);

    return 0;
}