#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

void inorder(struct TreeNode* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct TreeNode* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct TreeNode* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    //      15
    //   4      20
    //1       16  25
    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n2 = {16 , NULL, NULL};
    struct TreeNode n3 = {25, NULL, NULL};
    struct TreeNode n4 = {4, &n1, NULL};
    struct TreeNode n5 = {20, &n2, &n3};
    struct TreeNode n6 = {15, &n4, &n5};

    preorder(&n6);
    printf("\n");
    inorder(&n6);
    printf("\n");
    postorder(&n6);
    printf("\n");
}