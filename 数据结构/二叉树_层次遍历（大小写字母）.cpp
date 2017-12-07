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

	//ǰ�����
	//����ֵ�ǵ�ǰ�������Ƿ�Ϊ��������

	bool insert(const char& t) {

		//�������Ϊ�գ������
		if (!left) {
			left = new CharBinNode(t);

			//���������Ǵ�д��ĸ�ˣ�Ҳ��������������
			if (t >= 'A'&&t <= 'Z')
				left->full = true;
		}

		//�����������û�����ظ�insert
		else if (!left->full)
			left->insert(t);

		//����Һ���Ϊ�գ������
		else if (!right) {
			right = new CharBinNode(t);

			//���������Ǵ�д��ĸ�ˣ�Ҳ�������������ˣ�����������Ҳ����������������
			if (t >= 'A' && t <= 'Z')
				full = right->full = true;
		}

		//�����������û�����ظ�insert
		else if (!right->full)
			full = right->insert(t);

		return full;
	}

	//��α������
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

			//���head������0
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