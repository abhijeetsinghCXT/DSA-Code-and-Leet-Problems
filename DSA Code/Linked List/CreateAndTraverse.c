#include <stdio.h>
#include <stdlib.h>

// Create Node
struct Node
{
    int data;
    struct Node *link;
};

// Traverse and Print func()
void printLL(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
};

int main()
{

    struct Node *head, *node2, *node3;
    // Dynamic Memory Allocation in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    node2 = (struct Node *)malloc(sizeof(struct Node));
    node3 = (struct Node *)malloc(sizeof(struct Node));

    // Initialize data of Node
    head->data = 10;
    head->link = node2;

    node2->data = 39;
    node2->link = node3;

    node3->data = 52;
    node3->link = NULL;

    printLL(head);

    return 0;
}