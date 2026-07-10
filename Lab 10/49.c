#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *FIRST = NULL;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void insert(int info)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->link = NULL;

    if (FIRST == NULL)
        FIRST = newNode;
    else
    {
        struct Node *temp = FIRST;
        while (temp->link){
            temp = temp->link;
        }
            
        temp->link = newNode;
    }
}

void insertGCD()
{
    struct Node *save = FIRST;

    while (save != NULL && save->link != NULL)
    {
        int g = gcd(save->info, save->link->info);

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->info = g;

        newNode->link = save->link;
        save->link = newNode;

        save = newNode->link;
    }
}

void display()
{
    struct Node *temp = FIRST;

    while (temp)
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }

    printf("NULL\n");
}

void main()
{
    int n, info;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &info);
        insert(info);
    }

    printf("Original List:\n");
    display();

    insertGCD();

    printf("Modified List:\n");
    display();

}
// input:-
// 18 -> 6 -> 10 -> 3
// output:-
// 18 -> 6 -> 6 -> 2 -> 10 -> 1 -> 3