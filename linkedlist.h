#include <stdbool.h>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node Node;

bool isEmpty(Node* head);
void display(Node* head);

int len(Node* head);

Node* add(Node* head, int data);
Node* addEnd(Node* head, int data);
int getData(Node* head);
Node* RemoveHead(Node* head);
Node* removeTail(Node* head);
Node* destroy(Node* head);
#endif
