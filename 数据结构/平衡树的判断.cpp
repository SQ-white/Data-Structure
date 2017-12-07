#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;

class CharBinNode {
	CharBinNode* left;
	CharBinNode* right;
	CharBinNode* parent;
	char key;
public:
	static char last;
	static int abs(int x) {
		return x > 0 ? x : -x;
	}
	CharBinNode(const char& t) {
		key = t;
		left = right = parent = NULL;
	}
	~CharBinNode() {
		clear();
	}
	void clear() {
		if (left) {
			left->clear();
			delete left;
			left = NULL;
		}
		if (right) {
			right->clear();
			delete right;
			right = NULL;
		}
	}
	CharBinNode* insert(const char& t) {
		if (key >= 'a' && key <= 'z')
		{
			if (left)
				return left->insert(t);
			else {
				left = new CharBinNode(t);
				left->parent = this;
				return left;
			}
		}
		return parent->insertRight(t);
	}
	CharBinNode* insertRight(const char& t) {
		if (!right) {
			right = new CharBinNode(t);
			right->parent = this;
			return right;
		}
		else if (right->key >= 'A' && right->key <= 'Z')
			return parent->insertRight(t);
		return right->insert(t);
	}
	int treeDepth() {
		int nLeft = left ? left->treeDepth() : 0;
		int nRight = right ? right->treeDepth() : 0;
		return nLeft > nRight ? nLeft + 1 : nRight + 1;
	}
	bool balanced() {
		int nLeft = left ? left->treeDepth() : 0;
		int nRight = right ? right->treeDepth() : 0;
		if (abs(nLeft - nRight) > 1)
			return false;
		if (left && !left->balanced())
			return false;
		if (right && !right->balanced())
			return false;
		return true;
	}
};