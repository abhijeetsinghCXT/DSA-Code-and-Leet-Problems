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


//Insertion at Start of Linked List
struct Node* InsertAtStart(struct Node *head, int data){
struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
ptr->link = head;
ptr->data = data;
head = ptr;
};

//Insertion between a Linked List
struct Node* InsertinBetween(struct Node* head, int index, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* counter = head;
    int i = 1;
    while (i!=index)
    {
        counter = counter->link;
        i++;
    }
    ptr->data = data;
    ptr->link = counter->link;
    counter->link = ptr;
    
    return head;
};

//Insertion at the End of Linked List
struct Node* InsertatEnd(struct Node* head, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* counter = head;
    while (counter->link!=NULL)
    {
        counter = counter->link;
    }
    ptr->data = data;
    counter->link = ptr;
    ptr->link = NULL;
    
    return head;
};

//Insertion after a given Node in a Linked List
struct Node* InsertAfterNode(struct Node* head, struct Node* node,  int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* counter = head;

    ptr->data = data;
    ptr->link = node->link;
    node->link = ptr;
    
    return head;
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

    
    // head = InsertAtStart(head, 7);
    // head = InsertinBetween(head, 1, 31);
    // head = InsertatEnd(head, 65);
    head = InsertAfterNode(head, node2, 77);

    printLL(head);

    return 0;
}