#include <stdio.h>
#define MAX 7

struct CIRQUEUE
{
    int CQ[MAX];
    int F;
    int R;
};

void CQINSERT(struct CIRQUEUE *CQ,int x);
int CQDELETE(struct CIRQUEUE *CQ);
void CQDISPLAY(struct CIRQUEUE *CQ);

int main()
{
    struct CIRQUEUE CQ;
    CQ.F = -1;
    CQ.R = -1;
    int c,x;

    printf("\nWELCOME to the MENU-DRIVEN PROGRRAM FOR CIRCULAR-QUEUE : \n");

    do
    {
        printf("\nENTER - 1 : for operation CQINSERT\n");
        printf("ENTER - 2 : for operation CQDELETE\n");
        printf("ENTER - 3 : for operation CQDISPLAY\n");
        printf("ENTER - 0 : for EXIT\nENTER : ");
        scanf("%d", &c);

        switch (c)
        {
            case 1 :
                printf("\nENTER THE VALUE FOR ENQQUEUE : ");
                scanf("%d",&x);
                CQINSERT(&CQ,x);
                break;

            case 2 :
                printf("\nCQDELETED ELEMENT = %d",CQDELETE(&CQ));
                break;

            case 3 :
                CQDISPLAY(&CQ);
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

void CQINSERT(struct CIRQUEUE *CQ,int x)
{
    if (((CQ->R) + 1) % MAX == CQ->F)
    {
        printf("\n!!! OVERFLOW !!!\n");
        return ;
    }

    (CQ->R) = ((CQ->R) + 1) % MAX;
    CQ->CQ[CQ->R] = x;

    if((CQ->F) == -1)
    {
        (CQ->F)++;
    }
    return;
}

int CQDELETE(struct CIRQUEUE *CQ)
{
    int y;
    if((CQ->F) == -1) 
    {
        printf("\n!!! UNDERFLOW !!!\n");
        return -1;
    }

    y = CQ->CQ[CQ->F];

    if((CQ->F) == (CQ->R))
    {
        CQ->F = -1;
        CQ->R = -1;
    }
    else{
        (CQ->F) = (CQ->F + 1) % MAX;
    }
    return y;
}

void CQDISPLAY(struct CIRQUEUE *CQ)
{
    if((CQ->F) == -1)
    {
        printf("\n!!! UNDERFLOW !!!\n");
        return;
    }
    int i = CQ->F;
    printf("\nQUEUE : ");
    while (i != CQ->R)
    {
        printf("%d ",CQ->CQ[i]);

        if(i == MAX-1)
        {
            i = (i+1) % MAX;
        }
        else
        {
            i++;
        }
    }
    printf("%d \n",CQ->CQ[CQ->R]);
    return;
}