#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    char *arr;
};

// Check whether Stack is full
int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

// Check whether stack is empty
int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

// Push value in Stack
void push(struct Stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow");
    }
    else
        ptr->top += 1;
    ptr->arr[ptr->top] = val;
}

// Pop value from Stack
char pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow");
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top -= 1;
        return val;
    }
}

// Match the opening and closing brackets
int MP(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    else
        return 0;
}

int paranthesisCheck(char *exp)
{
    // Dynamic Memory allocated to Stack
    struct Stack *S = (struct Stack *)malloc(sizeof(struct Stack));
    S->size = 10;
    S->top = -1;
    S->arr = (char *)malloc(S->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(S, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(S))
            {
                return 0;
            }
            else
            {
                int a = pop(S);
                if (MP(a, exp[i]))
                {
                    continue;
                }
                else
                    return 0;
            }
        }
    }

    if (isEmpty(S))
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    char *exp = "(3+4)+4*54/{5}";
    if (paranthesisCheck(exp))
    {
        printf("Paranthesis is balanced.");
    }
    else
    {
        printf("Paranthesis is unbalanced.");
    }

    return 0;
}