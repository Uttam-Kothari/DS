#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *FIRST = NULL;

void push(int info)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    newNode->info = info;
    newNode->link = FIRST;
    FIRST = newNode;

    printf("%d inserted into stack.\n", info);
}

void pop()
{
    struct Node *temp;

    if (FIRST == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = FIRST;
    printf("%d deleted from stack.\n", temp->info);

    FIRST = FIRST->link;
    free(temp);
}

void peek()
{
    if (FIRST == NULL)
        printf("Stack is Empty.\n");
    else
        printf("Top Element = %d\n", FIRST->info);
}

void display()
{
    struct Node *temp;

    if (FIRST == NULL)
    {
        printf("Stack is Empty.\n");
        return;
    }

    temp = FIRST;

    printf("\nStack Elements:\n");

    while (temp != NULL)
    {
        printf("%d\n", temp->info);
        temp = temp->link;
    }
}

int main()
{
    int choice, info;

    while (1)
    {
        printf("\n===== STACK MENU =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d", &info);
            push(info);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}