#include "stdio.h"
#include "stdlib.h"

struct node
{
    int info;
    struct node *rptr;
    struct node *lptr;
};

struct node *FIRST = NULL;


void insert_at_first()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d", &newnode->info);
    if (FIRST == NULL)
    {
        newnode->rptr = NULL;
        newnode->lptr = NULL;
        FIRST = newnode;
    }
    else
    {
        newnode->rptr = FIRST;
        FIRST->lptr = newnode;
        newnode->lptr = NULL;
        FIRST = newnode;
    }
}

void display()
{
    struct node *save;
    save = FIRST;
    while (save != NULL)
    {
        printf("%d<->", save->info);
        save = save->rptr;
    }
    printf("\n");
}

void delete_at_specified_position()
{
    struct node *save, *pred;
    int x;
    save = FIRST;
    printf("enter data to delete:");
    scanf("%d", &x);
    if (FIRST->info == x)
    {
        FIRST = save->rptr;
        save->lptr = NULL;
        free(save);
        return;
    }

    while (save->info != x)
    {

        pred = save;
        save = save->rptr;
    }
    
    if (save->rptr == NULL)
    {
        pred->rptr = NULL;
        free(save);
        return;
    }
    pred->rptr = save->rptr;
    save->rptr->lptr = pred;
    free(save);
}

void insert_at_last()
{
    struct node *save, *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->info);

    newnode->rptr = NULL;

    if (FIRST == NULL)
    {
        FIRST = newnode;
        newnode->lptr = NULL;
        return;
    }

    save = FIRST;

    while (save->rptr != NULL)
    {
        save = save->rptr;
    }

    save->rptr = newnode;
    newnode->lptr = save;
}

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
        switch (c)
        {
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