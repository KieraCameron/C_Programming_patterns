#include <stdio.h>
#include <stdlib.h>


struct node {
        int value;
        struct node *left;
        struct node *right;
};

typedef void (*node_visitor)(struct node *n, void *ctx);

void inorder_visit(struct node *root, node_visitor visit, void *ctx){
        if(!root){
                return;
        }
        inorder_visit(root->left, visit, ctx);
        visit(root, ctx);
        inorder_visit(root->right, visit, ctx);
}
void print_node(struct node *n, void *ctx){
        (void)ctx;
        printf("%d\n", n->value);
}
