#include<iostream>
#include<cstring>
#include<sstream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

const int maxn = 1E6 + 10;
int ans[maxn], cnt;

class CharBinNode {
	CharBinNode* left;
	CharBinNode* right;
	char key;
	bool full;
public:
	CharBinNode(const char& t) {
		key = t;
		left = right =NULL;
		full = false;
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

	//前序插入
	//返回值是当前的子树是否为满二叉树

	bool insert(const char& t) {

		//如果左孩子为空，则插入
		if (!left) {
			left = new CharBinNode(t);

			//如果插入的是大写字母了，也就是左子树满了
			if (t >= 'A'&&t <= 'Z')
				left->full = true;
		}

		//如果左子树还没满，重复insert
		else if (!left->full)
			left->insert(t);

		//如果右孩子为空，则插入
		else if (!right) {
			right = new CharBinNode(t);

			//如果插入的是大写字母了，也就是右子树满了，右子树满了也就是整棵树都满了
			if (t >= 'A' && t <= 'Z')
				full = right->full = true;
		}

		//如果右子树还没满，重复insert
		else if (!right->full)
			full = right->insert(t);

		return full;
	}

	//层次遍历输出
	void printByLevelBFS() {
		queue<CharBinNode *> q;
		q.push(this);
		cnt = 0;
		while (!q.empty()) {
			CharBinNode * p = q.front();
			 q.pop();
			ans[cnt++] = p->key;
			if (p->left)   q.push(p->left);
			if (p->right) q.push(p->right);
		}
		for (int i = 0; i < cnt; ++i) {
			cout << (char)ans[i];
		}
		cout << endl;
	}
	

};


int main()
{
	CharBinNode* head = 0;
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		stringstream ss(s);
		char tmp;
		while (ss >> tmp) {
			if (!(tmp >= 'a'&&tmp <= 'z') && !(tmp >= 'A'&&tmp <= 'Z'))
				continue;

			//如果head不等于0
			if (head)
				head->insert(tmp);
			else
				head = new CharBinNode(tmp);
		}
		if (head) {
			head->printByLevelBFS();
			delete head;
		}
		head = 0;
	}
	return 0;
}