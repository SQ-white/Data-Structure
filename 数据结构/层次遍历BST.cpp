#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<sstream>
using namespace std;
const int maxn = 1E6 + 10;
int ans[maxn], cnt;
typedef int Elem;
class Node {
private:
	Elem item;
	Node * leftTree;
	Node * rightTree;
public:
	Node(Elem _item, Node * _leftTree = NULL, Node * _rightTree = NULL) :
		item(_item), leftTree(_leftTree), rightTree(_rightTree) {}
	void setLeft(Node *_leftTree) {
		leftTree = _leftTree;
	}
	void setRight(Node *_rightTree) {
		rightTree = _rightTree;
	}
	Elem key() {
		return item;
	}
	void setKey(Elem item) {
		this->item = item;
	}
	Node * left() {
		return leftTree;
	}
	Node * right() {
		return rightTree;
	}
	bool hasLeft() {
		return leftTree != NULL;
	}
	bool hasRight() {
		return rightTree != NULL;
	}
	bool isLeaf() {
		return !hasLeft() && !hasRight();
	}
};
class BST {
private:
	Node * root;
	Node* addNodeHelp(Node* hyRoot, Elem item) {
		if (hyRoot == NULL) {
			return new Node(item);
		}
		if (hyRoot->key() > item) {
			hyRoot->setLeft(addNodeHelp(hyRoot->left(), item));
		}
		else {
			hyRoot->setRight(addNodeHelp(hyRoot->right(), item));
		}
		return hyRoot;
	}
	int heightHelp(Node *hyRoot) {
		if (hyRoot == NULL) return 0;
		return max(heightHelp(hyRoot->left()), heightHelp(hyRoot->right())) + 1;
	}
	void clearHelp(Node * hyRoot) {
		if (hyRoot == NULL) return;
		clearHelp(hyRoot->left());
		clearHelp(hyRoot->right());
		delete hyRoot;
	}
	Node * deleteMax(Node *hyRoot, Node * &hyMax) {
		if (!hyRoot->hasRight()) {
			hyMax = hyRoot;
			return NULL;
		}
		else {
			hyRoot->setRight(deleteMax(hyRoot->right(), hyMax));
		}
		return hyRoot;
	}
	Node * removeHelp(Node * hyRoot, const Elem &e, Node * &t) {
		if (hyRoot == NULL) {
			return t = NULL;
		}
		else if (e < hyRoot->key()) {
			hyRoot->setLeft(removeHelp(hyRoot->left(), e, t));
		}
		else if (e > hyRoot->key()) {
			hyRoot->setRight(removeHelp(hyRoot->right(), e, t));
		}
		else {
			if (hyRoot->hasLeft() && !hyRoot->hasRight()) {
				t = hyRoot;
				return hyRoot->left();
			}
			else if (!hyRoot->hasLeft() && hyRoot->hasRight()) {
				t = hyRoot;
				return hyRoot->right();
			}
			else if (hyRoot->isLeaf()) {
				t = hyRoot;
				return NULL;
			}
			else {
				hyRoot->setLeft(deleteMax(hyRoot->left(), t));
				Elem tmp = t->key();
				t->setKey(hyRoot->key());
				hyRoot->setKey(tmp);
			}
		}
		return hyRoot;
	}
public:
	~BST() {
		clear();
	}
	BST() :root(NULL) {}
	void addNode(Elem item) {
		root = addNodeHelp(root, item);
	}
	int height() {
		return heightHelp(root);
	}
	void clear() {
		clearHelp(root);
	}
	void removeNodeOnce(const Elem &e, Node * &t) {
		root = removeHelp(root, e, t);
	}
	void printByLevelBfs() {
		queue<Node *> q;
		q.push(root);
		cnt = 0;
		while (!q.empty()) {
			Node * p = q.front(); q.pop();
			ans[cnt++] = p->key();
			if (p->left())   q.push(p->left());
			if (p->right()) q.push(p->right());
		}
		for (int i = 0; i < cnt; ++i) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
};
int main() {
	int t, tmp;
	string str, tt;
	while (cin >> t)
	{
		getline(cin, str);
		while (t--) {
			getline(cin, str);
			stringstream ss(str);
			BST tree;
			while (ss >> tmp) {
				getline(ss, str, ',');
				tree.addNode(tmp);
			}
			tree.printByLevelBfs();
		}
	}
	return 0;
}