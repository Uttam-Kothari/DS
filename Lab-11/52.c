#include "stdio.h"
#include "stdlib.h"
struct node
{
    int info;
    struct node *link;
};
struct node *FIRST = NULL;
struct node *SECOND = NULL;

void halves();
void insert_at_last();
void display1();
void display2();
int count();

void main()
{
    int c = 1;
    while (c != 0)
    {
        printf("0.to exit\n");
        printf("1.to insert node\n");
        scanf("%d", &c);
        if (c == 0)
        {
            break;
        }
        insert_at_last();
    }
    halves();
    display1();
    display2();
}

int count()
{
    struct node *save;
    save = FIRST;
    int count = 0;
    do
    {
        count++;
        save = save->link;
    } while (save != FIRST);

    return count;
}

void halves()
{
    if (FIRST == NULL){

        return;
    }

    int n = count();
    struct node *save = FIRST;
    struct node *save2 = FIRST;

    while (save2->link != FIRST)
    {
        save2 = save2->link;
    }

    for (int i = 1; i < (n + 1) / 2; i++)
    {
        save = save->link;
    }

    SECOND = save->link;
    save->link = FIRST;
    save2->link = SECOND;
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

void display1()
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

void display2()
{
    struct node *save;
    save = SECOND;
    if (SECOND == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        do
        {
            printf("%d ", save->info);
            save = save->link;
        } while (save != SECOND);
    }
    printf("\n");
}