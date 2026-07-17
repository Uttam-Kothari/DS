#include<stdio.h>
#include<stdlib.h>

void push(int a[], int n)
{
    printf("Enter push element: ");
    scanf("%d", &a[n]);
    printf("Pushed element is: %d\n", a[n]);
    printf("\n");
}

void pop(int a[], int n)
{
    printf("Poped element is: %d", a[n-1]);
    printf("\n");
    printf("\n");
}

void display(int a[], int n)
{
    printf("Array elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("\n");

}

void peep(int a[], int n) {
    printf("peep element are: %d" , a[n-1]);
    printf("\n");
    printf("\n");
}

void change(int a[], int n) {
    int b,x;

    printf("Enter index would you change: ");
    scanf("%d",&b);

    printf("Enter would you change: ");
    scanf("%d",&x);

    a[b]=x;

    printf("\n");
    printf("\n");

}

int main()
{
    int n = 0, c;
    int a[n];

    while (1)
    {
        printf("1.pushed elements are:\n");
        printf("2.popped elements are:\n");
        printf("3.display elements are:\n");
        printf("4.peep elements are:\n");
        printf("5.Change elements are:\n");
        printf("6.Exit\n");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            push(a, n);
            n++;
            break;

        case 2:
            pop(a, n);
            n--;
            break;

        case 3:
            display(a, n);
            break;

        case 4:
            peep(a, n);
            break;

        case 5:
            change(a, n);
            break;

        case 6:
            printf("Exiting...");
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}