#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

// Traverse the Circular LL
void traverseCLL(struct Node* head){
    struct Node* ptr = head;

    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
    while (ptr != head);
};

// Insert Node at the Start of Circular LL
struct Node* InsertatStart(struct Node* head, int data){
 struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
struct Node* p = head;

do
{
p = p->link;
} while (p->link != head);

p->link = ptr;
ptr->data = data;
ptr->link = head;
head = ptr;

return head;
};

int main(){

struct Node *head, *node1, *node2, *node3;

head = (struct Node*)malloc(sizeof(struct Node));
node1 = (struct Node*)malloc(sizeof(struct Node));
node2 = (struct Node*)malloc(sizeof(struct Node));
node3 = (struct Node*)malloc(sizeof(struct Node));

head->data = 10;
head ->link = node1;

node1->data = 20;
node1->link = node2;

node2->data = 30;
node2->link = node3;

node3->data = 40;
node3->link = head;

 head = InsertatStart(head, 5);
 traverseCLL(head);

    return 0;
}