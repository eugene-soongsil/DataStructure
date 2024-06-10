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

    void preorder(){
        cout << getData() << " ";
        if(getLeft()) getLeft()->preorder();
        if(getRight()) getRight()->preorder();
    }
    void inorder(){
        if(getLeft()) getLeft()->inorder();
        cout << getData() << " ";
        if(getRight()) getRight()->inorder();
    }
    void postorder(){
        if(getLeft()) getLeft()->postorder();
        if(getRight()) getRight()->postorder();
        cout << getData() << " ";   
    }
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
    TreeNode* getRoot(){
        return root;
    }
    bool isEmpty(){
        return root == NULL;
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

    cout << "inorder: ";
    t.getRoot()->inorder();
    cout << endl;

    cout << "preorder: ";
    t.getRoot()->preorder();
    cout << endl;

    cout << "postorder: ";
    t.getRoot()->postorder();
    cout << endl;
}