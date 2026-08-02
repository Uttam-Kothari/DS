#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *FIRST = NULL;
void Enqueue();
int dequeue();
void display();

int main()
{
     
    int c;

    printf("\nWELCOME to the MENU-DRIVEN PROGRRAM FOR QUEUE : \n");

    do
    {
        printf("\nENTER - 1 : for operation ENQUEUE\n");
        printf("ENTER - 2 : for operation DEQUEUE\n");
        printf("ENTER - 3 : for operation DISPLAY\n");
        printf("ENTER - 0 : for EXIT\nENTER : ");
        scanf("%d", &c);

        switch (c)
        {
            case 1 :
            
                Enqueue();
                break;

            case 2 :
                printf("\nDEQUEUED ELEMENT = %d",dequeue());
                break;

            case 3 :
                display();
                break;
            
            case 0 :
                printf("Existing...");
                break;
                
            default:
            printf("\nInavlid Input !");
                break;
        }

    } while (c != 0);

    return 0;
}
void Enqueue()
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter info: ");
    scanf("%d", &newNode->info);

    newNode->link = NULL;

    if (FIRST == NULL)
    {
        FIRST= newNode;
    }
    else{

        temp = FIRST;
        while (temp->link != NULL){
            temp = temp->link;
        }
        
        temp->link = newNode;
    }
}
int dequeue()
{
    struct Node *temp;
    int y;
    if (FIRST == NULL)
    {
        printf("List is Empty\n");
        return 0;
    }
    else{

        temp = FIRST;
        y=temp->info;
        FIRST = FIRST->link;
        free(temp);
    }
    return y;
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
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}