// Remove Duplicate Nodes from Sorted Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};
struct Node *FIRST;
void insertEnd(int info)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->link = NULL;

    if (FIRST == NULL)
    {
        FIRST = newNode;
        return;
    }

    temp = FIRST;

    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = newNode;
}

void display()
{
    struct Node *save=FIRST;
    while (save != NULL)
    {
        printf("%d", save->info);

        if (save->link != NULL)
        {
            printf(" -> ");
        }

        save = save->link;
    }
    printf("\n");
}

void removeDuplicates()
{
    struct Node *save;
    struct Node *temp = FIRST;
    struct Node *pred;

    while (temp->link != NULL)
    {
        save = temp->link;
        pred = temp;
        while (save->link != NULL)
        {
            if (save->info == temp->info)
            {
                pred->link = save->link;
                save = save->link;
            }
            else
            {
                pred = save;
                save = save->link;
            }
        }
        temp = temp->link;
    }
}

void main()
{
    int n, i, info;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order:\n");

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &info);
        insertEnd(info);
    }

    printf("Original List:\n");
    display();

    removeDuplicates();

    printf("List after removing duplicates:\n");
    display();
}
