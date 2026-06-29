// Menu Driven Program for Singly Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *FIRST = NULL;

void insertFront()
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->link = FIRST;
    FIRST = newNode;
}

void insertEnd()
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->link = NULL;

    if (FIRST == NULL)
    {
        FIRST= newNode;
        return;
    }

    temp = FIRST;
    while (temp->link != NULL){
        temp = temp->link;
    }

    temp->link = newNode;
}

void display()
{
    struct Node *temp = FIRST;

    if (FIRST == NULL)
    {
        printf("List is Empty\n");
        return;
    }                                   

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void deleteFirst()
{
    struct Node *temp;

    if (FIRST == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    temp = FIRST;
    FIRST = FIRST->link;
    free(temp);
}

void deleteLast()
{
    struct Node *temp, *prev;

    if (FIRST == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (FIRST->link == NULL)
    {
        free(FIRST);
        FIRST = NULL;
        return;
    }

    temp = FIRST;

    while (temp->link != NULL)
    {
        prev = temp;
        temp = temp->link ;
    }

    prev->link = NULL;
    free(temp);
}

void deletePosition()
{
    int pos, i;
    struct Node *temp, *prev;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        deleteFirst();
        return;
    }

    temp = FIRST;

    for (i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    prev->link = temp->link;
    free(temp);
}

void countNodes()
{
    int count = 0;
    struct Node *temp = FIRST;

    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }

    printf("Total Nodes = %d\n", count);
}

void main()
{
    int ch;

    while (1)
    {
        printf("\n1. Insert Front");
        printf("\n2. Insert End");
        printf("\n3. Display");
        printf("\n4. Delete First");
        printf("\n5. Delete Last");
        printf("\n6. Delete Position");
        printf("\n7. Count Nodes");
        printf("\n8. Exit");

        printf("\nEnter Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insertFront();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            display();
            break;
        case 4:
            deleteFirst();
            break;
        case 5:
            deleteLast();
            break;
        case 6:
            deletePosition();
            break;
        case 7:
            countNodes();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid Choice");
        }
    }

}