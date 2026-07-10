#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *FIRST = NULL;

void insert(int info)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->link = NULL;

    if (FIRST == NULL){
        FIRST = newNode;
    }    
    else
    {
        struct Node *temp = FIRST;

        while (temp->link != NULL){
            temp = temp->link; 
        }  
        temp->link = newNode;
    }
}

void display()
{
    struct Node *temp = FIRST;
    while (temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

int countNodes()
{
    int count = 0;
    struct Node *temp = FIRST;

    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }

    return count;
}

void swap(int k)
{
    int n = countNodes();

    if (k > n || 2 * k - 1 == n){
        return; 
    }   

    struct Node *x = FIRST, *xPrev = NULL;

    for (int i = 1; i < k; i++)
    {
        xPrev = x;
        x = x->link;
    }

    struct Node *y = FIRST, *yPrev = NULL;

    for (int i = 1; i < n - k + 1; i++)
    {
        yPrev = y;
        y = y->link;
    }

    if (xPrev){
        xPrev->link = y;
    } 
    else{
         FIRST = y;
    }
       
    if (yPrev){
        yPrev->link = x;
    }   
    else{
        FIRST = x;
    }  

    struct Node *temp = x->link;
    x->link = y->link;
    y->link = temp;
}

void main()
{
    int n, info, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &info);
        insert(info);
    }

    printf("Enter K: ");
    scanf("%d", &k);

    printf("Original List:\n");
    display();

    swap(k);

    printf("After Swapping:\n");
    display();

}