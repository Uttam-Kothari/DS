#include "stdio.h"
#include "stdlib.h"
struct node
{
    int info;
    struct node *link;
};

struct node *FIRST = NULL;

void insert_at_first();
void delete_at_specified_position();
void insert_at_last();
void display();

void main()
{
    int c = 1;
    while (c != 0)
    {
        printf("0.to exit\n");
        printf("1.to insert node at first for circular\n");
        printf("2.delete node at specified position\n");
        printf("3.insert node at end\n");
        printf("4.display\n");
        scanf("%d", &c);
        if (c == 0)
        {
            break;
        }
        switch (c) {
        case 1:
            insert_at_first();
            break;
        case 2:
            delete_at_specified_position();
            break;
        case 3:
            insert_at_last();
            break;
        case 4:
            display();
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}
void insert_at_first()
{
    struct node *newnode, *save;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data: ");
    scanf("%d", &newnode->info);

    if (FIRST == NULL)
    {
        FIRST = newnode;
        newnode->link = FIRST;
    }
    else
    {
        save = FIRST;

        while (save->link != FIRST)
        {
            save = save->link;
        }
        newnode->link = FIRST;
        FIRST = newnode;
        save->link = FIRST;
    }
}

void delete_at_specified_position()
{
    struct node *save, *pred;
    int x;
    printf("Enter the data to delete:");
    scanf("%d", &x);

    if (FIRST->info == x)
    {
        if (FIRST->link == FIRST)
        {
            free(FIRST);
            FIRST = NULL;
            return;
        }

        save = FIRST;

        while (save->link != FIRST){
            save = save->link;
        }

        FIRST = FIRST->link;
        save->link = FIRST;
        return;
    }
    save = FIRST;
    pred = NULL;

    while (save->info != x)
    {
        pred = save;
        save = save->link;
    }
    pred->link = save->link;
    free(save);
}
void insert_at_last()
{
    struct node *save, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data: ");
    scanf("%d", &newnode->info);

    if (FIRST == NULL)
    {
        FIRST = newnode;
        newnode->link = FIRST;
    }
    else
    {
        save = FIRST;

        while (save->link != FIRST)
        {
            save = save->link;
        }
        newnode->link = FIRST;
        save->link = newnode;
    }
}

void display()
{
    struct node *save;
    save = FIRST;
    if (FIRST == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        do
        {
            printf("%d ", save->info);
            save = save->link;
        } while (save != FIRST);
    }
    printf("\n");
}