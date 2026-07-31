#include <stdio.h>
#include <string.h>
#define MAX 50

struct STACK
{
    int S[MAX];
    int TOP;
};
void push(struct STACK *stack, int x);
int pop(struct STACK *stack);

int main()
{

    struct STACK stack;
    stack.TOP = -1;
    char polish[50];
    printf("enter polish equation:");
    scanf("%s", polish);

    for (int i = 0; polish[i] != '\0'; i++)
    {

        if (polish[i] <= '9' && polish[i] >= '0')
        {
            int m = (int)polish[i] - (int)'0';
            push(&stack, m);
        }

        else if (polish[i] == '+' || polish[i] == '-' || polish[i] == '*' || polish[i] == '/')
        {
            int a2 = pop(&stack);
            int a1 = pop(&stack);

            switch (polish[i])
            {
            case '+':
                push(&stack, a1 + a2);
                break;

            case '-':
                push(&stack, a1 - a2);
                break;

            case '*':
                push(&stack, a1 * a2);
                break;

            case '/':
                push(&stack, a1 / a2);
                break;

            default:
                break;
            }
        }
    }

    
    printf("%d", pop(&stack));
    return 0;
}

void push(struct STACK *stack, int x)
{
    if (stack->TOP >= MAX - 1)
    {
        printf("OVERFLOW !!!");
        return;
    }
    else
    {
        stack->S[++(stack->TOP)] = x;
        return;
    }
}

int pop(struct STACK *stack)
{ // removes and returns the element at top of stack
    if (stack->TOP <= -1)
    {
        printf("UNDERFLOW !!!");
        return '\0';
    }
    else
    {
        return stack->S[(stack->TOP)--];
    }
}