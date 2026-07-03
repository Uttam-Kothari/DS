// Check Whether Two Singly Linked Lists are Same or Not

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

void createList(struct Node **FIRST, int n)
{
    struct Node *newNode, *temp;
    int i;

    for (i = 1; i <= n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter info %d : ", i);
        scanf("%d", &newNode->info);

        newNode->link = NULL;

        if (*FIRST == NULL)
        {
            *FIRST = newNode;
            temp = newNode;
        }
        else
        {
            temp->link = newNode;
            temp = newNode;
        }
    }
}

int compare(struct Node *FIRST1, struct Node *FIRST2)
{
    while (FIRST1 != NULL && FIRST2 != NULL)
    {
        if (FIRST1->info != FIRST2->info)
        {
            return 0;
        }

        FIRST1 = FIRST1->link;
        FIRST2 = FIRST2->link;
    }

    if (FIRST1 == NULL && FIRST2 == NULL)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void main()
{
    struct Node *FIRST1 = NULL, *FIRST2 = NULL;
    int n1, n2;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n1);

    createList(&FIRST1, n1);

    printf("Enter number of nodes in second list: ");
    scanf("%d", &n2);

    createList(&FIRST2, n2);

    if (compare(FIRST1, FIRST2))
    {
        printf("Both linked lists are SAME.\n");
    }

    else
    {
        printf("Both linked lists are NOT SAME.\n");
    }
}
