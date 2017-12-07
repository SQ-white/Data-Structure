#include<iostream>
#include<string>

using namespace std;

class BNode {
public:
	int it;
	BNode* Left;
	BNode* Right;
public:
	BNode() {
		Left = Right = NULL;
	}
	BNode(int value, BNode* l = NULL, BNode* r = NULL) {
		Left = l;
		Right = r;
		it = value;
	}

	~BNode() {}
	int& val() {
		return it;
	}
	void setVal(const int value) {
		it = value;
	}
	BNode* left()const {
		return Left;
	}
	BNode* right()const {
		return Right;
	}
	void setLeft(BNode* node = NULL) {
		Left = node;
	}
	void setRight(BNode* node = NULL) {
		Right = node;
	}
	bool isleaf() {
		return (Left = NULL) && (Right == NULL);
	}
};

class BST :public BNode {
public:
	BNode* root;
	int nodecount;
	int height;
public:
	BST() {
		root = NULL;
		nodecount = 0;
		height = 0;
	}
	~BST() {}
	BNode* insert(BNode*& root, BNode* node) {
		if (root == NULL) {
			root = node;
			return root;
		}
		else {
			if (node->val()<root->val() && root->left() == NULL) {
				root->setLeft(node);
				return root;
			}
			if (node->val() >= root->val() && root->right() == NULL) {
				root->setRight(node);
				return root;
			}
			if (node->val()<root->val() && root->left() != NULL) {
				insert(root->Left, node);
			}
			if (node->val() >= root->val() && root->right() != NULL) {
				insert(root->Right, node);
			}
		}
	}
	int max(int m, int n) {
		if (m >= n)return m;
		return n;
	}
	int BSTheight(BNode* root) {
		if (root == NULL)return 0;
		return 1 + max(BSTheight(root->Left), BSTheight(root->Right));
	}

	BNode* getRoot() {
		return root;
	}

};

int main() {
	int n;
	cin >> n;
	int value;
	char divide;
	BST* Oh_BST = new BST();
	while (n--) {
		Oh_BST->root = NULL;
		divide = '\0';
		while (divide != '\n') {
			cin >> value;
			cin.get(divide);
			Oh_BST->insert(Oh_BST->root, new BNode(value));
		}
		cout << Oh_BST->BSTheight(Oh_BST->root) << endl;
	}
}