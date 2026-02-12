#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node{
        int data;
        struct Node* next;
} Node;

bool isEmpty(Node* head){
        if(head == NULL){
                return true;
        }
        return false;
}

int len(Node* head){
        if(isEmpty(head))
                return -1;
        int size = 0;
        while(head!= NULL){
                head = head->next;
                size = size + 1;
        }
        return size;
}
Node* add(Node* head, int data){
        /*this function adds the data in front of the list*/
        Node* newNode = (Node*)malloc(sizeof(Node));

        if(newNode == NULL)
                return head;

        newNode->data = data;
        newNode->next = head;
        return newNode;
}



int main(void){
        Node new = {16, NULL};
        Node* newnode = &new;
        newnode = add(newnode, 6);
        printf("%d\t %d", newnode->data, newnode->next->data);
        return 0;
}
