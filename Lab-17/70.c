#include <stdio.h>
#define MAX 20

struct QUEUE
{
    int Q[MAX];
    int F;
    int R;
};

void enqueue(struct QUEUE *Q,int x);
int dequeue(struct QUEUE *Q);
void display(struct QUEUE *Q);

int main()
{
    struct QUEUE Q;
    Q.F = -1;
    Q.R = -1;
    int c,x;

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
                printf("\nENTER THE VALUE FOR ENQQUEUE : ");
                scanf("%d",&x);
                enqueue(&Q,x);
                break;

            case 2 :
                printf("\nDEQUEUED ELEMENT = %d",dequeue(&Q));
                break;

            case 3 :
                display(&Q);
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

void enqueue(struct QUEUE *Q,int x)
{
    if ((Q->R) >= MAX)
    {
        printf("\n!!! OVERFLOW !!!\n");
        return ;
    }

    (Q->R)++;
    Q->Q[Q->R] = x;

    if((Q->F) == -1)
    {
        (Q->F)++;
    }
    return;
}

int dequeue(struct QUEUE *Q)
{
    int y;
    if(Q->F == -1) 
    {
        printf("\n!!! UNDERFLOW !!!\n");
        return -1;
    }
    y = Q->Q[Q->F];
    if(Q->F == Q->R)
    {
        Q->F = -1;
        Q->R = -1;
    }
    else{
        (Q->F)++;
    }
    return y;
}

void display(struct QUEUE *Q)
{
    if(Q->F == -1)
    {
        printf("\n!!! UNDERFLOW !!!\n");
        return;
    }
    int i = Q->F;
    printf("\nQUEUE : ");
    while (i != Q->R)
    {
        printf("%d ",Q->Q[i]);
        i++;
    }
    printf("%d \n",Q->Q[Q->R]);
    return;
}