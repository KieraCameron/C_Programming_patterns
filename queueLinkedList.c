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
        return q;
}

void queueDisplay(Queue* q){
        display(q->front);
        display(q->end);
}

int frontData(Queue* q){
        return getData(q->front);
}

Node* createNode(int data){
        return add(NULL, data);
}


void enqueue(Queue* q, int data){//this functions needs fixing
        Node* newnode = createNode(data);
        if(q->end == NULL){
                q->end = q->front = newnode;
        } else {
        q->end->next = newnode;
        q->end = newnode;
        }
}

int dequeue(Queue* q){
        int var = frontData(q);
        q->front = removeHead(q->front);
        if(q->front == NULL)
                q->end = NULL;
        return var;
}       

int main(void){
        Queue* q = queueInit();
        enqueue(q, 16);
        enqueue(q, 17);
        enqueue(q, 18);
        queueDisplay(q);
        while(q->front != NULL)
                printf("%d \t", dequeue(q));
        return 0;
}
