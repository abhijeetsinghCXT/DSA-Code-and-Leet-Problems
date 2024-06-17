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


// struct Node* DeleteatStart(struct Node* head){
//     struct Node* ptr = head;
//     head = head ->link;
//     free(ptr);

//     return head;
// };

struct Node* DeleteinBetween(struct Node* head, int index ){
    struct Node* ptr = head;
    struct Node* counter1 = head;
    int i = 1;

    while (i!=index-1)
    {
        counter1 = counter1->link;
        i++;
    }

    struct Node* counter2 = counter1->link;
    counter1->link = counter2->link;
    free(counter2);

    return head;
};

int main()
{

    struct Node *head, *node2, *node3, *node4, *node5, *node6;
    // Dynamic Memory Allocation in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    node2 = (struct Node *)malloc(sizeof(struct Node));
    node3 = (struct Node *)malloc(sizeof(struct Node));
    node4 = (struct Node *)malloc(sizeof(struct Node));
    node5 = (struct Node *)malloc(sizeof(struct Node));
    node6 = (struct Node *)malloc(sizeof(struct Node));

    // Initialize data of Node
    head->data = 10;
    head->link = node2;

    node2->data = 20;
    node2->link = node3;

    node3->data = 30;
    node3->link = node4;

    node4->data = 40;
    node4->link = node5;

    node5->data = 50;
    node5->link = node6;

    node6->data = 60;
    node6->link = NULL;

    // head = DeleteatStart(head);
    head = DeleteinBetween(head, 2);
    printLL(head);

    return 0;
}