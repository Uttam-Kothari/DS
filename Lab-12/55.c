#include "stdio.h"
#include "stdlib.h"
struct node
{
    int info;
    struct node *rptr;
    struct node *lptr;
};
struct node *FIRST = NULL;

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

void delete_alternate()
{
    struct node *save, *pred, *succ;

    if (FIRST == NULL)
        return;

    save = FIRST;

    while (save != NULL && save->rptr != NULL)
    {
        pred = save;
        succ = save->rptr;

        pred->rptr = succ->rptr;

        if (succ->rptr != NULL)
            succ->rptr->lptr = pred;

        free(succ);

        save = pred->rptr;
    }
}

void main()
{
    int c = 1;
    while (c != 0)
    {
        printf("0.to exit\n");
        printf("1.to insert node:");
        scanf("%d", &c);
        if (c == 0)
        {
            break;
        }
        insert_at_last();
    }
    delete_alternate();
    display();
}
