#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

Node* stack_init(){
        Node* newnode = NULL;
        return newnode;
}

int peek(Node** top){
        if(*top == NULL){
                fprintf(stderr, "Error: Peek on empty stack\n");
                return INT_MIN;
        }
        return getData(*top);
}

int stackLen(Node** top){
        return len(*top);
}

void push(Node** top, int data){
        *top = add(*top, data);
        return;
}


int pop(Node** top){
        if(*top == NULL){
                fprintf(stderr, "Error: pop on empty stack \n");
                return -1;
        }
        int var = getData(*top);// local variable will get destroyed when the function is done
                                // good practice to not return the pointer of the local variable
                                // to avoid memory leaks and overflows and what not
        *top = removeHead(*top);
        return var;
}

int main(void){
        Node* ptr = stack_init();
        push(&ptr, 16);
        push(&ptr, 12);
        push(&ptr, 13);
        push(&ptr, 17);
        printf("data at the top is : %d \n", peek(&ptr));
        printf("length of the stack is : %d \n", stackLen(&ptr));
        display(ptr);
        while(!isEmpty(ptr)){
                printf("%3d ", pop(&ptr));
        }
        return 0;
}


