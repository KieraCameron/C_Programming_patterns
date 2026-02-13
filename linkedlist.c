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

void display(Node* head){
        while(head !=NULL){
                printf("%d ", head->data);
                head = head->next;
        }
        printf("\n");
        return;
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

Node* addEnd(Node* head, int data){
        Node* newNode = (Node*)malloc(sizeof(Node));
        
        if(newNode == NULL)
                return head;
        newNode->data = data;
        newNode->next = NULL;

        if(head == NULL)
                return newNode;
        Node* temp = head;
        while(temp->next != NULL){
                temp = temp->next;
        }
        temp->next = newNode;
        return head;
}

Node* RemoveHead(Node* head){
        if(head == NULL)
                return head;
        return head->next;
}

Node* removeTail(Node* head){
        if(head == NULL)
                return head;
        else if (head->next == NULL)
                return NULL;

        Node* temp = head;
        while(temp->next->next!=NULL){
                temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        return head;
}

int main(void){
        Node new = {16, NULL};
        Node* newnode = &new;
        newnode = add(newnode, 6);
        newnode = addEnd(newnode, 17);
        display(newnode);
        newnode = RemoveHead(newnode);
        display(newnode);
        newnode = removeTail(newnode);
        display(newnode);
        return 0;
}
