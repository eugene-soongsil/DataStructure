#include <iostream>
using namespace std;


class TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

public:
	TreeNode(int d = 0, TreeNode* l = NULL, TreeNode* r = NULL) {
		data = d;
		left = l;
		right = r;
	}

	void setData(int d) { data = d; }
	void setLeft(TreeNode* l) { left = l; }
	void setRight(TreeNode* r) { right = r; }
	int getData() { return data; }
	TreeNode* getLeft() { return left; }
	TreeNode* getRight() { return right; }
	bool isLeaf() {
		return (left == NULL && right == NULL);
	}
};



class BinaryTree {
protected:
	TreeNode* root;
public:
	BinaryTree(TreeNode* r = NULL) {
		root = r;
	}

	TreeNode* getRoot() {
		return root;
	}
	void setRoot(TreeNode* r) {
		root = r;
	}
	bool isEmpty() {
		return root == NULL;
	}

	void preorder() {
		cout << "preorder: ";
		preorder(root);
		cout << endl;
	}
	void preorder(TreeNode* root) {
		if (root) {
			cout << root->getData() << " ";
			preorder(root->getLeft());
			preorder(root->getRight());
		}
	}

	int getCount() {
		return root == NULL ? 0 : getCount(root);
	}

	int getCount(TreeNode* node) {
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}

	int getHeight() { return isEmpty() ? 0 : getHeight(root); }

	int getHeight(TreeNode* node) {
		if (node == NULL) return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}
};

class BinSrchTree : public BinaryTree{
public:
    TreeNode* searchRecur(TreeNode* n, int key){
        if(n==NULL) return NULL;
        if(key == n->getData()) return n;
        else if(key < n->getData()) return searchRecur(n->getLeft(), key);
        else return searchRecur(n->getRight(), key);
    }
    TreeNode* searchInter(TreeNode* n, int key){
        while(n != NULL){
            if(key == n->getData()) return n;
            else if(key < n->getData()) n = n->getLeft();
            else n = n->getRight();
        }
        return NULL;
    }
    void insetRecur(TreeNode* r, TreeNode* n){
        if(n->getData() == r->getData()) return ;
        else if(n->getData() < r->getData()){
            if(r->getLeft() == NULL) r->setLeft(n);
            else insetRecur(r->getLeft(), n);
        }
        else{
            if(r->getRight() == NULL) r->setRight(n);
            else insetRecur(r->getRight(), n);
        }
    }
    void remove(int data){
        TreeNode* parent = NULL;
        TreeNode* node = root;

        while(node != NULL && node->getData() != data){
            parent = node;
            if(data < node->getData()) node = node->getLeft();
            else node = node->getRight();
        }
        if(node == NULL){
            cout << "ERROR: no key in the tree" << endl;
            return ;
        }
        else remove(parent, node);
    }
    void remove(TreeNode* parent, TreeNode* node){
        if(node->isLeaf()){ //remove node is leaf (no child)
            if(parent == NULL) root = NULL;
            else{
                if(parent->getLeft() == node)
                    parent->setLeft(NULL);
                else parent->setRight(NULL);
            }
        }
        else if(node->getLeft() == NULL || node->getRight() == NULL){ //remove node have child
            TreeNode* child;
            if(node->getLeft() == NULL) child = node->getRight();
            else child = node->getLeft();
            if(node == root) root = child;
            if(parent->getLeft() == node) parent->setLeft(child);
            if(parent->getRight() == node) parent->setRight(child);
        }
        else{
            TreeNode* succp = node;
            TreeNode* succ = node->getRight();
            while(succ->getLeft() != NULL){
                succp = succ;
                succ = succ->getLeft();
            }
            if(succp->getLeft() == succ)
                succp->setLeft(succ->getRight());
            else
                succp->setRight(succ->getRight());
            node->setData(succ->getData());
            node = succ;
        }
        delete node;
    }
};

int main(){
    BinSrchTree t2;
    TreeNode r1 = {5, NULL, NULL};
    t2.setRoot(&r1);

    t2.insetRecur(t2.getRoot(), new TreeNode(2));
    t2.insetRecur(t2.getRoot(), new TreeNode(6));
    t2.insetRecur(t2.getRoot(), new TreeNode(4));
    t2.insetRecur(t2.getRoot(), new TreeNode(7));
    t2.insetRecur(t2.getRoot(), new TreeNode(9));
    t2.insetRecur(t2.getRoot(), new TreeNode(8));

    t2.preorder();

    TreeNode* temp=t2.searchRecur(t2.getRoot(), 25);
    if(temp == NULL) cout << "25없음" << endl;
    else cout << temp->getData() << "있음" << endl;

    temp = t2.searchRecur(t2.getRoot(), 9);
    if(temp==NULL) cout<<"9없음"<<endl;
    else cout << temp->getData()<<"있음"<<endl;

    cout<<"9삭제"<<endl;
    t2.remove(9);

    temp=t2.searchInter(t2.getRoot(), 9);
    if(temp==NULL) cout<<"9없음" <<endl;
    else cout<<temp->getData()<<"있음"<<endl;

    t2.preorder();
}