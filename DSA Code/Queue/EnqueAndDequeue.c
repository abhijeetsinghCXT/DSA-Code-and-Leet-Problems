#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int f;
    int r;
    int size;
    int *arr;
};

int isFull(struct Queue *q){
    if (q->r == q->size-1)
    {
        printf("Queue is Full\n");
        return 1;
    }
    else return 0;
    
}
int isEmpty(struct Queue *q){
    if (q->f == q->r)
    {
        printf("Queue is Empty.\n");
        return 1;
    }
    else return 0;
    
}


void enqueue(struct Queue *q, int val){
    if (isFull(q))
    {
        "Queue is Full\n";
    }
    else {
        q->r++;
        q->arr[q->r] = val;
    }
}
int dequeue(struct Queue *q){
    if (isEmpty(q))
    {
        return 0;
    }
    else {
        q->f++;
        return q->arr[q->f];
    }
}


int main(){
    struct Queue *q;
    q->f = -1;
    q->r = -1;
    q->size = 5;
    q->arr = (int*)malloc(q->size*sizeof(int));

    // isEmpty(q);

  

    isEmpty(q);
    printf("The element %d is dequeued.\n", dequeue(q));


}