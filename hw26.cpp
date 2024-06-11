#include <iostream>
using namespace std;

class TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(int d = 0, TreeNode* l = NULL, TreeNode* r = NULL){
        data = d;
        left = l;
        right = r;
    }

    void setData(int d){data = d;}
    void setLeft(TreeNode* l){left = l;}
    void setright(TreeNode* r){right = r;}
    int getData() { return data; }
	TreeNode* getLeft() { return left; }
	TreeNode* getRight() { return right;}
	bool isLeaf() {
		return (left == NULL && right == NULL);
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
    void preorder(){
        cout << "preorder: ";
        preorder(root);
        cout << endl;
    }
    void preorder(TreeNode* root){
        cout << root->getData() << " ";
        preorder(root->getLeft());
        preorder(root->getRight());
    }
    int getCount(){
        return root == NULL ? 0 : getCount(root);
    }
    int getCount(TreeNode* node){
        if(node == NULL) return 0;
        return 1 + getCount(node->getLeft()) + getCount(node->getRight());
    }
    int getHeight(){return isEmpty() ? 0 : getHeight(root);}

    int getHeight(TreeNode* node){ //use stack form recall
        if(node ==NULL) return 0;
        int hLeft = getHeight(node->getLeft());
        int hRight = getHeight(node->getRight());
        return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
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

    cout << endl << "# of nodes in the tree:" << t.getCount();
    cout << endl << "Height of the tree:" << t.getHeight();
}