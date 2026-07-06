// Write a Program to Reverse a Linked List

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
    while (temp-> link != NULL)
        temp = temp->link;

    temp->link = newNode;
}

struct Node *reverse(struct Node *FIRST)
{
    struct Node *prev = NULL;
    struct Node *curr = FIRST;
    struct Node *link;

    while (curr != NULL)
    {
        link = curr->link;
        curr->link = prev;
        prev = curr;
        curr = link;
    }

    return prev;
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
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &value);
        insertEnd(&FIRST, value);
    }

    printf("Original List:\n");
    display(FIRST);

    FIRST = reverse(FIRST);

    printf("Reversed List:\n");
    display(FIRST);

}


// ### Example Output

// Original List:
// 10 -> 20 -> 30 -> 40 -> NULL

// Reversed List:
// 40 -> 30 -> 20 -> 10 -> NULL
