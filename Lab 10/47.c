#include "stdio.h"
#include "stdlib.h"

void ins_At_First(int x);
void display_All();
void sort_List_Element();

struct Node
{
    int info;
    struct Node *link;
};

struct Node *FIRST = NULL;

int main() {
    
    int c, x;
    do
    {
        printf("\nENTER - '1' : To Insert a Node At the Front Of Linked List\n");
        printf("ENTER - '2' : To Display All Nodes\n");
        printf("ENTER - '3' : To Sort The Linked List Elements\n");
        printf("ENTER - '0' : To Exit The Progrram\n\n");
        scanf(" %d", &c);

        switch (c)
        {
        case 1:
            printf("Enter A Data for Node :\n");
            scanf("%d", &x);
            ins_At_First(x);
            break;
        case 2:
            display_All();
            break;
        case 3:
            sort_List_Element();
            break;
        case 0:
            printf("Exiting...\n");
            break;
            break;
        default:
            printf("Invalid Input \n");
            break;
        }
    } while (c != 0);
    return 0;
}


void ins_At_First(int x)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = x;
    newNode->link = FIRST;

    FIRST = newNode;

    printf("\nins_At_First : Complete\n");
}

void display_All()
{
    struct Node *save;
    save = FIRST;

    while (save != NULL)
    {
        printf("%p\t<=\t%d\t=>\t%p\n", save, save->info, save->link);
        save = save->link;
    }
}


void sort_List_Element()
{
    struct Node *save = FIRST;
    struct Node *temp;

    while (save != NULL)
    {
        temp = save;
        while (temp != 0)
        {
            if (save->info > temp->info)
            {
                int num = temp->info;
                temp->info = save->info;
                save->info = num;
            }
            temp = temp->link;
        }
        save = save->link;
    }
}