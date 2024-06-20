#include<stdio.h>
#include<stdlib.h>

struct Stack{
int top;
int size;
int *arr;
};

// Check whether Stack is full
int isFull(struct Stack *ptr){
    if (ptr->top == ptr->size-1)
    {
    return 1;
    }
    return 0;
}

// Check whether stack is empty
int isEmpty(struct Stack *ptr){
    if (ptr->top == -1)
    {
    return 1;
    }
    return 0;
}

// Push value in Stack
void push(struct Stack *ptr, int val){
    if (isFull(ptr))
    {
        printf("Stack Overflow");
    }
    else ptr->top += 1;
    ptr->arr[ptr->top] = val;
}

// Pop value from Stack
int pop(struct Stack *ptr){
    if (isEmpty(ptr))
    {
        printf("Stack Underflow");
    }
    else{
    int val = ptr->arr[ptr->top]; 
    ptr->top -= 1;
    return val;
    }
}

// Peek at a given position inside a Stack
int peek(struct Stack* ptr, int position){
if ((ptr->top-position+1) < 0)
{
    printf("Invalid Input");
}
else {
    return ptr->arr[ptr->top-position+1];
}
};

// Fetch Top element of Stack
int stackTop(struct Stack* ptr){
return ptr->arr[ptr->top]; 
}

// Fetch Bottom element of Stack
int stackBottom(struct Stack* ptr){
return ptr->arr[0]; 
}

int main(){

// Dynamic Memory allocated to Stack
struct Stack *S = (struct Stack*)malloc(sizeof(struct Stack));
S->size = 10;
S->top = -1;
S->arr = (int*)malloc(S->size * sizeof(int));

printf("%d\n",isFull(S));
printf("%d\n",isEmpty(S));

push(S, 4);
push(S, 5);
push(S, 6);
push(S, 8);

printf("Push %d\n", S->arr[S->top]);
printf("Pop %d\n", pop(S));
printf("The value is %d\n", peek(S, 2));
printf("Top Value is: %d\n", stackTop(S));
printf("Bottom Value is: %d\n", stackBottom(S));

return 0;
}