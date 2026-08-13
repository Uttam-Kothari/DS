#include <stdio.h>
#define MAX 20

struct QUEUE
{
    int Q[MAX];
    int F;
    int R;
};

void ENQUEUE_At_Last(struct QUEUE *Q, int x);
void ENQUEUE_At_First(struct QUEUE *Q, int x);
int DEQUEUE_At_First(struct QUEUE *Q);
int DEQUEUE_At_Last(struct QUEUE *Q);
void display(struct QUEUE *Q);

int main()
{
    struct QUEUE Q;
    Q.F = -1;
    Q.R = -1;
    int c, x;

    printf("\nWELCOME to the MENU-DRIVEN PROGRRAM FOR DOUBLE-ENDED-QUEUE : \n");

    do
    {
        printf("\nENTER - 1 : for operation ENQUEUE_At_Last\n");
        printf("ENTER - 2 : for operation ENQUEUE_At_First\n");
        printf("ENTER - 3 : for operation DEQUEUE_At_First \n");
        printf("ENTER - 4 : for operation DEQUEUE_At_Last \n");
        printf("ENTER - 5 : for operation DISPLAY\n");
        printf("ENTER - 0 : for EXIT\nENTER : ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("\nENTER THE VALUE FOR ENQQUEUE : ");
            scanf("%d", &x);
            ENQUEUE_At_Last(&Q, x);
            break;

        case 2:
            printf("\nENTER THE VALUE FOR ENQQUEUE : ");
            scanf("%d", &x);
            ENQUEUE_At_First(&Q, x);
            break;
        case 3:
            printf("\nDEQUEUE_At_FIRST D ELEMENT = %d", DEQUEUE_At_First(&Q));
            break;

        case 4:
            printf("\nDEQUEUE_At_FIRST D ELEMENT = %d", DEQUEUE_At_Last(&Q));
            break;
        case 5:
            display(&Q);
            break;

        case 0:
            printf("Existing...");
            break;

        default:
            printf("\nInavlid Input !");
            break;
        }

    } while (c != 0);

    return 0;
}

void ENQUEUE_At_Last(struct QUEUE *Q, int x)
{
    if ((Q->R) >= MAX)
    {
        printf("\n!!! OVERFLOW !!!\n");
        return;
    }

    (Q->R)++;
    Q->Q[Q->R] = x;

    if ((Q->F) == -1)
    {
        (Q->F)++;
    }
    return;
}

void ENQUEUE_At_First(struct QUEUE *Q, int x)
{
    int y;
    if ((Q->F) == 0)
    {
        printf("\n!!! OVERFLOW !!!\n");
        return;
    }
    else if ((Q->F) == -1 && Q->R == -1)
    {
        Q->Q[++(Q->F)] = x;

        (Q->R)++;
    }
    else
    {
        Q->Q[--(Q->F)] = x;
    }
}

int DEQUEUE_At_First(struct QUEUE *Q)
{
    int y;
    if (Q->F == -1)
    {
        printf("\n!!! UNDERFLOW !!!\n");
        return -1;
    }
    y = Q->Q[Q->F];
    if (Q->F == Q->R)
    {
        Q->F = -1;
        Q->R = -1;
    }
    else
    {
        (Q->F)++;
    }
    return y;
}

void display(struct QUEUE *Q)
{
    if (Q->F == -1)
    {
        printf("\n!!! UNDERFLOW !!!\n");
        return;
    }
    int i = Q->F;
    printf("\nQUEUE : ");
    while (i != Q->R)
    {
        printf("%d ", Q->Q[i]);
        i++;
    }
    printf("%d \n", Q->Q[Q->R]);
    return;
}
int DEQUEUE_At_Last(struct QUEUE *Q)
{
    int y;
    if ((Q->R) == -1)
    {
        printf("\n!!! UNDERFLOW !!!\n");
        return 0;
    }
    else if ((Q->F) == Q->R)
    {
        (Q->F) = -1;

        (Q->R) = -1;
    }
    else
    {
        y = Q->Q[(Q->R)--];
    }
    return y;
}
