#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
        int data;
        struct TreeNode* left;
        struct TreeNode* right;
}TreeNode;

TreeNode* initTreeNode(){
        return NULL;
}

TreeNode* createTreeNode(int data){
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        if(newNode == NULL){// add memory cleanup code
                fprintf(stderr, "Error: Memory allocation failed. Shutting down. \n");
                exit(EXIT_FAILURE);
        }
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->data = data;
        return newNode;
}

void insertTreeNode(TreeNode** root, int data){
        if(*root == NULL){
                *root = createTreeNode(data);
                return;
        }
        if((*root)->data >= data){
                return insertTreeNode(&(*root)->left, data);
        }
        if((*root)->data < data){
                return insertTreeNode(&(*root)->right, data);
        }

}
int main(void){
        TreeNode* root = initTreeNode();
        insertTreeNode(&root, 16);
        insertTreeNode(&root, 17);
        insertTreeNode(&root, 15);
        printf("%d\n",root->data);
        printf("%d\n",root->left->data);
        printf("%d\n",root->right->data);
        return 0;
}
