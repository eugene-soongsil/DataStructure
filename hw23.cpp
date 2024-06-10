#include <iostream>
using namespace std;

class TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(int d = 0, TreeNode* l = NULL, TreeNode* r =NULL){
        data = d;
        left = l;
        right = r;
    }

    void setData(int d){data = d;}
    void setLeft(TreeNode* l){left = l;}
    void setRight(TreeNode* r){right = r;}
    int getData(){return data;}
    TreeNode* getLeft(){return left;}
    TreeNode* getRight(){return right;}
};

class BinaryTree{
    TreeNode* root;
public:
    BinaryTree(TreeNode* r = NULL){
        root = r;
    }
    void setRoot(TreeNode* r){
        root = r;
    }
    bool isEmpty(){
        return root == NULL;
    }

    void preorder(){
        cout << "preorder: ";
        preorder(root);
        cout << endl;
    }
    void preorder(TreeNode* root){
        if(root){
            cout << root->getData() << " ";
            preorder(root->getLeft());
            preorder(root->getRight());
        }
    }
    void inorder(){
        cout << "inorder: ";
        inorder(root);
        cout << endl;
    }
    void inorder(TreeNode* root){
        if(root){
            inorder(root->getLeft());
            cout << root->getData() << " ";
            inorder(root->getRight());
        }
    }
    void postorder(){
        cout << "postorder: ";
        postorder(root);
        cout << endl;
    }
    void postorder(TreeNode* root){
        if(root){
            postorder(root->getLeft());
            postorder(root->getRight());
            cout << root->getData() << " ";
        }
    }
};

int main(){
    //15
    //4 20
    //1 16 25
    TreeNode n1 = {1, NULL, NULL};
    TreeNode n2 = {16, NULL, NULL};
    TreeNode n3 = {25, NULL, NULL};
    TreeNode n4 = {4, &n1, NULL};
    TreeNode n5 = {20, &n2, &n3};
    TreeNode n6 = {15, &n4, &n5};

    BinaryTree t;
    t.setRoot(&n6);
    t.inorder();
    t.preorder();
    t.postorder();
}