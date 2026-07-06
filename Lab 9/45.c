// Write a Program to Copy a Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

void insertEnd(struct Node **FIRST, int info)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->link = NULL;

    if (*FIRST == NULL)
    {
        *FIRST = newNode;
        return;
    }

    temp = *FIRST;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = newNode;
}

struct Node *copyList(struct Node *FIRST)
{
    struct Node *newFIRST = NULL;
    struct Node *temp = FIRST;

    while (temp != NULL)
    {
        insertEnd(&newFIRST, temp->info);
        temp = temp->link;
    }

    return newFIRST;
}

void display(struct Node *FIRST)
{
    while (FIRST != NULL)
    {
        printf("%d -> ", FIRST->info);
        FIRST = FIRST->link;
    }
    printf("NULL\n");
}

void main()
{
    struct Node *FIRST = NULL;
    struct Node *copy = NULL;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &value);
        insertEnd(&FIRST, value);
    }

    copy = copyList(FIRST);

    printf("Original List:\n");
    display(FIRST);

    printf("Copied List:\n");
    display(copy);
}

// Example Output

// Original List:
// 10 -> 20 -> 30 -> 40 -> NULL

// Copied List:
// 10 -> 20 -> 30 -> 40 -> NULL
