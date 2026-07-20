#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char info;
    struct Node *link;
};

struct Node *FIRST = NULL;

void push(char ch)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    newNode->info = ch;
    newNode->link = FIRST;
    FIRST = newNode;
}

char pop()
{
    struct Node *temp;
    char ch;

    if (FIRST == NULL)
        return '\0';

    temp = FIRST;
    ch = temp->info;
    FIRST = FIRST->link;
    free(temp);

    return ch;
}

int isPalindrome(char str[])
{
    int len = strlen(str);
    int i;

    while (FIRST != NULL)
    {
        pop();
    }

    for (i = 0; i < len / 2; i++)
    {
        push(str[i]);
    }

    if (len % 2 != 0)
        i++;

    while (i < len)
    {
        if (pop() != str[i])
            return 0;

        i++;
    }

    return 1;
}

int main()
{
    char str[100];

    printf("Enter String: ");
    scanf("%s", str);

    if (isPalindrome(str))
        printf("%s is Recognized (Palindrome)\n", str);
    else
        printf("%s is Not Recognized\n", str);

    return 0;
}