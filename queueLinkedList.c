#include<stdio.h>
#include"linkedlist.h"
#include<stdlib.h>

typedef struct {
        Node* front;
        Node* end;
}Queue;

Queue* queueInit(){
        Queue* q = (Queue*)malloc(sizeof(Queue));
        q->front = NULL;
        q->end = NULL;
}

void queueDisplay(Queue* q){
        display(q->front);
        display(q->end);
}

void enqueue(Queue* q, int data){
        q->front = addEnd(q->front, data);
        if(q->end == NULL){
                q->end = q->front;
        }
        else{
                q->end = next(q->end);
        }
}
                

int main(void){
        Queue* q = queueInit();
        enqueue(q, 16);
        enqueue(q, 17);
        enqueue(q, 18);
        queueDisplay(q);
        return 0;
}
