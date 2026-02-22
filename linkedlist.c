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
                return 0;
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

int getData(Node* head){
        if(head == NULL){
                fprintf(stderr, "Error: Null linked list provided.\n");
                return INT_MIN;
        }
        return head->data;
}

Node* removeHead(Node* head){
        if(head == NULL)
                return head;
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
}

Node* removeTail(Node* head){
        if(head == NULL)
                return head;
        else if (head->next == NULL){
                free(head);
                return NULL;
        }
        Node* temp = head;
        while(temp->next->next!=NULL){
                temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        return head;
}

Node* destroy(Node* head){
        Node* temp;
        while(head != NULL){
                temp = head;
                head = head->next;
                free(temp);
        }
        return NULL;
}

Node* reverse_rec(Node* head){
        //unsafe : may cause stack overflow in the long run with >100000 stack func calls
        if(head == NULL || head->next == NULL)
                return head;
        Node* newhead = reverse_rec(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
}

Node* reverse(Node* head){
        if(head == NULL || head->next == NULL)
                return head;
        Node* prev = NULL;
        Node* curr = head;
        Node* ahead;
        while(curr!=NULL){
                ahead = curr->next;
                curr->next = prev;
                prev = curr;
                curr = ahead;
        }
        return prev;
}

//int main(void){
//        Node* newnode = NULL;
//        newnode = add(newnode, 16);
//        newnode = add(newnode, 6);
//        newnode = addEnd(newnode, 17);
//        printf("%d", getData(newnode));
//        display(newnode);
//        newnode = reverse(newnode);
//        display(newnode);
//        newnode = RemoveHead(newnode);
//        display(newnode);
//        newnode = removeTail(newnode);
//        display(newnode);
//        newnode = destroy(newnode);
//        display(newnode);
//        
//        return 0;
//}
