#include <stdio.h>

#define MAX 1000

int stack[MAX];
int top;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int peek()
{
    return stack[top];
}

int isEmpty()
{
    return top == -1;
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int n;
        scanf("%d", &n);

        int a[MAX];
        int sorted[MAX];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            sorted[i] = a[i];
        }

       
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (sorted[j] > sorted[j + 1])
                {
                    int temp = sorted[j];
                    sorted[j] = sorted[j + 1];
                    sorted[j + 1] = temp;
                }
            }
        }

        top = -1;
        int index = 0;

        for (int i = 0; i < n; i++)
        {
            push(a[i]);

            while (!isEmpty() && peek() == sorted[index])
            {
                pop();
                index++;
            }
        }

        if (index == n)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}