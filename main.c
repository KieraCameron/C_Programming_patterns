#include <stdio.h>
#include "linkedlist.h"


int main(void){
        Node* newnode = NULL;
        newnode = add(newnode, 6);
        newnode = add(newnode, 16);
        newnode = add(newnode, 17);
        display(newnode);
        return 0;
}
