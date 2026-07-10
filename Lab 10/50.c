#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *FIRST = NULL;

void insert(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->link = NULL;

    if (FIRST == NULL)
        FIRST = newNode;
    else
    {
        struct Node *temp = FIRST;
        while (temp->link)
        {
            temp = temp->link;
        }

        temp->link = newNode;
    }
}

void swapPairs()
{
    if (FIRST == NULL || FIRST->link == NULL)
    {
        return;
    }

    struct Node *prev = NULL;
    struct Node *save = FIRST;

    FIRST = FIRST->link;

    while (save != NULL && save->link != NULL)
    {
        struct Node *next = save->link;
        struct Node *nextPair = next->link;

        next->link = save;
        save->link = nextPair;

        if (prev != NULL){
          prev->link = next;

        }

        prev = save;
        save = nextPair;
    }
}

void display()
{
    struct Node *temp = FIRST;

    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }

    printf("NULL\n");
}

void main()
{
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insert(value);
    }

    printf("Original List:\n");
    display();

    swapPairs();

    printf("After Swapping Consecutive Nodes:\n");
    display();
}

// input:-
// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
// output:-
// 2 -> 1 -> 4 -> 3 -> 6 -> 5 -> 8 -> 7