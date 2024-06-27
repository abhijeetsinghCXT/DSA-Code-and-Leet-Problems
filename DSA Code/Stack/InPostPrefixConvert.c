#include <stdio.h>
#include <stdlib.h>
#include<string.h>

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
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top -= 1;
        return val;
    }
}

int stackTop(struct Stack* ptr){
    if (!isEmpty(ptr))
    {
    return ptr->arr[ptr->top]; 
    }
    return 0;
}


int operator(char a){
    if (a == '+' || a == '-' || a == '*' || a == '/')
    {
       return 1;
    }
    else return 0;
}

int precedence(char a){
    if (a == '+' || a == '-')
    {
       return 1;
    }
    else if (a == '*' || a == '/')
    {
       return 2;
    }
    else return 0;
    
}

char* InfToPost(char* exp){
struct Stack *S = (struct Stack*)malloc(sizeof(struct Stack));
S->size = 100;
S->top = -1;
S->arr = (char*)malloc(S->size*sizeof(char));
char* post = (char*)malloc(strlen(exp)+1*sizeof(char)); //Added +1 becoz have to add '/0' in the end.

int i = 0;
int j = 0;
while (exp[i]!='\0')
{
    if (!operator(exp[i]))
    {
        post[j] = exp[i];
        i++;
        j++;
        
    } else {
        if (precedence(exp[i]) > precedence(stackTop(S)))
        {
        push(S, exp[i]);
        i++;
        }
        else { post[j] = pop(S);
        j++;  
        } 
    }
}

while(!isEmpty(S)){
post[j] = pop(S);
j++;
}
post[j] = '\0';
return post;
}



int main()
{
    char * exp = "4-5/9-3*1";

    printf("The post fix expression is: %s", InfToPost(exp));

    return 0;
}