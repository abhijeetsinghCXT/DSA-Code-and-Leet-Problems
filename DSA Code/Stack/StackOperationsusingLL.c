#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * link;
};

// Traverse Stack
void printStack(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
};

// Check whether stack is full
int isFull(){
    struct Node* ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    
if (ptr == NULL)
{
    return 1;
}
else return 0;
};

// Check whether stack is empty
int isEmpty(struct Node* top){
if (top == NULL)
{
    return 1;
}
else return 0;
}

// Push Element into stack
struct Node* push(struct Node* top, int data){
struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
if (isFull() == 1)
{
    printf("Stack Overflow");
}
else
{
    ptr->data = data;
    ptr->link = top;
    // top = ptr;
    printf("The element %d is pushed successfully.\n", data);
    return ptr;
}
}

// Pop Element out of stack
struct Node* pop(struct Node* top){
    struct Node* ptr = top;
if (isEmpty(ptr) == 1)
{
    printf("Stack Underflow");
}
else
{
    int x = ptr->data;
    top = ptr->link;
    free(ptr);
    printf("The element %d is popped successfully.\n", x);
    return top;
}
}

// Peek at a given position of stack
int peek(struct Node* top, int position){
    struct Node* counter = top;
    int i = 0;
    while (i<position-1 && counter != NULL)
    {
        counter = counter->link;
        i++;
    }
    if (counter != NULL)
    {
        return counter->data;
    }
    else return -1;  
}

// Fetch Top Element of stack
int StackTop(struct Node* top){
    if(top != NULL){
    return top->data;
} else return -1;
}

// Fetch Bottom Element of stack
int StackBottom(struct Node* top){
    struct Node * counter = top;
    while(counter->link != NULL)
    {
        counter = counter->link;
    }
    return counter->data;

}


int main() {

struct Node *top = NULL;


// isFull();
// isEmpty(top);

top = push(top, 10);
top = push(top, 20);
top = push(top, 30);
top = push(top, 40);
top = push(top, 50);
printf("Stack Elements:\n");
printStack(top);

printf("Removed Element: ");
top = pop(top);


printf("Remaining Stack Elements:\n");
printStack(top);

printf("Given Stack Element is: %d\n", peek(top, 3));
printf("Top Stack Element is: %d\n", StackTop(top));
printf("Bottom Stack Element is: %d\n", StackBottom(top));


return 0;
}