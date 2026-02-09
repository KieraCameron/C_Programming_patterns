#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
        int arr[MAX_SIZE];
        int front;
        int back;
} Queue;


void initialize(Queue *q){
        q->front = -1;
        q->back = 0;
}

bool isEmpty(Queue *q){
        return q->front == q->back-1;
}

bool isFull(Queue* q) {return (q->back == MAX_SIZE);}

void enqueue(Queue* q, int value)
{
        if(isFull(q)){
                printf("Queue is full\n");
                return;
        }
        q->arr[q->back] = value;
        q->back++;
}

void dequeue(Queue* q){
        if(isEmpty(q)){
                printf("Queue is empty\n");
                return;
        }
        q->front++;
}

int peek(Queue* q){
        if(isEmpty(q)){
                printf("Queue is empty\n");
                return -1;
        }
        return q->arr[q->front+1];
}

void printQueue(Queue* q){
        if(isEmpty(q)){
                printf("Queue is empty\n");
                return;
        }
        for(int i = q->front+1; i< q->back; i++){
                printf("%2d ", q->arr[i]);
        }
        printf("\n");
}

int main(){
        Queue q;
        initialize(&q);
        enqueue(&q, 10);
        printQueue(&q);

        enqueue(&q, 20);
        printQueue(&q);

        enqueue(&q, 30);
        printQueue(&q);

        printf("Front element: %d\n", peek(&q));

        dequeue(&q);
        printQueue(&q);

        printf("Front element after dequeue: %d\n", peek(&q));

        return 0;
}

