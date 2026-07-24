#include <stdio.h>
#include <string.h>
#define MAX 50

struct STACK
{
    char S[MAX];
    int TOP;
};
int G(char c);
int F(char c);
int R(char c);
void push(struct STACK *stack, char x);
char pop(struct STACK *stack);
void display(struct STACK *stack);

int main()
{

    struct STACK stack;
    stack.TOP = 0;
    stack.S[0] = '(';

    char infix[50], polish[50], next;
    int rank, i = 0,p=0;

    polish[0] = '\0';
    rank = 0;

    printf("Enter An Infix Expression : ");
    scanf("%s", infix);

    infix[strlen(infix)] = ')';

    next = infix[0];

    while (next != '\0')
    {
        if (stack.TOP < 0)
        {
            printf("Invalid Infix Expression !!!");
            return 0;
        }

        while (G(stack.S[stack.TOP]) > F(next))
        {
            polish[p++] = pop(&stack);
            polish[p] = '\0';
            rank = rank + R(polish[p-1]);

            if (rank < 1)
            {
                printf("Invalid Infix Expression !!!");
                return 0;
            }
        }

        if (G(stack.S[stack.TOP]) != F(next))
        {
            push(&stack, next);
        }
        else
        {
            pop(&stack);
        }

        next = infix[++i];
    }

    if (stack.TOP != -1 || rank != 1)
    {
        printf("Invalid Infix Expression !!!");
        return 0;
    }
    else
    {
        printf("POLISH EXPRESSION :");
        for (i = 0; polish[i] != '\0'; i++)
        {
            printf("%c", polish[i]);
        }
    }
    return 0;
}

int G(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '^':
        return 5;
    case '(':
        return 0;

    default:
        return 8;
    }
}

int F(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 3;
    case '^':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    default:
        return 7;
    }
}

int R(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return -1;

    default:
        return 1;
    }
}

void push(struct STACK *stack, char x)
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

char pop(struct STACK *stack)
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