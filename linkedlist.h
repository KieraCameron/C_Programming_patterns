#include <stdbool.h>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node{
        int data;//remove this 
        struct Node* next;//remove this
}Node;

bool isEmpty(Node* head);
void display(Node* head);

int len(Node* head);

Node* add(Node* head, int data);
Node* addEnd(Node* head, int data);
int getData(Node* head);
Node* removeHead(Node* head);
Node* removeTail(Node* head);
Node* destroy(Node* head);
Node* reverse(Node* head);
#endif
