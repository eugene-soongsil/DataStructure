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
    void setright(TreeNode* r){right = r;}
    int getData(){return data;}
    TreeNode* getLeft(){return left;}
    TreeNode* getRight(){return right;}
    bool isLeaf(){
        return(left==NULL && right == NULL);
    }
};

class Node{
    TreeNode* data;
    Node* link;
public:
    Node(TreeNode* d = NULL){
        data = d;
        link = NULL;
    }
    TreeNode* getData(){return data;}
    Node* getLink(){return link;}
    void setLink(Node* n){link = n;}
};

class LinkedQueue{
    Node* front;
    Node* rear;
public:
    LinkedQueue(){
        front = rear = NULL;
    }
    bool isEmpty(){
        return front == NULL;
    }
    void enqueue(TreeNode* item){
        Node* newNode = new Node(item);
        if(isEmpty()){
            front = rear = newNode;
        }
        else{
            rear->setLink(newNode);
            rear = newNode;
        }
    }
    TreeNode* dequeue(){
        if(isEmpty()){
            return NULL;
        }
        else{
            Node* temp = front;
            front = front->getLink();
            if(front == NULL){
                rear = NULL;
            }
            TreeNode* data = temp->getData();
            delete temp;
            return data;
        }
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
    bool isEmpty(){
        return root == NULL;
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
    void levelorder(){
        cout << "level order: ";
        if(root == nullptr) return;

        LinkedQueue queue;
        queue.enqueue(root);

        while(!queue.isEmpty()){
            TreeNode* current = queue.dequeue();
            cout << current->getData() << " ";

            if(current->getLeft() != nullptr){
                queue.enqueue(current->getLeft());
            }
            if(current->getRight() != nullptr){
                queue.enqueue(current->getRight());
            }
        }
        cout << endl;
    }
};


int main(){
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
    t.levelorder();
}