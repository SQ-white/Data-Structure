#include<iostream>
#include <cstddef>

using namespace std;

struct node {
	int payload;
	node* next;
	node(int payload) { this->payload = payload; next = NULL; }
};


//遍历链表
void bianli(node* head) {
	node* iterator = head;
	while (iterator) {
		cout << iterator->payload << " ";
		iterator = iterator->next;
	}
	cout << " " << endl;
}

class linkedlist {
	node* head, *tail;
public:
	linkedlist() :head(NULL), tail(NULL) {};

	//插入链表
	void push_back(int value) {
		if (empty()) {
			head = tail = new node(value);
		}
		else {
			tail->next = new node(value);
			tail = tail->next;
		}
	}

	int front() {
		if (empty()) {
			throw "NULL";
		}
		return head->payload;
	}

	void pop_front() {
		if (empty()) {
			throw "NULL";
		}
		node* first_node = head;
		head = head->next;
		delete first_node;
	}

	bool empty() {
		return head == NULL;
	}

	//输出链表
	void output() {
		node* iterator = head;
		while (iterator) {
			if (iterator->next == 0)
			{
				cout << iterator->payload;
			}
			else
			{
				cout << iterator->payload << " ";
			}
			iterator = iterator->next;
		}
		cout << endl;
	}

};

//合并链表
linkedlist merge(linkedlist a, linkedlist b) {
	linkedlist result;
	while (!a.empty() || !b.empty()) {
		if (a.empty()) {
			result.push_back(b.front());
			b.pop_front();
		}
		else if (b.empty()) {
			result.push_back(a.front());
			a.pop_front();
		}
		else if (a.front() > b.front()) {
			result.push_back(b.front());
			b.pop_front();
		}
		else {
			result.push_back(a.front());
			a.pop_front();
		}
	}
	return result;
}

int main() {
	int n1, n2, i;
	int t[100];
	int p[100];
	while (cin >> n1 >> n2)
	{
		if (n1 == 0 && n2 == 0)
			cout << "NULL";
		linkedlist a, b;
		for (i = 0; i<n1; i++)
		{
			cin >> t[i];
			a.push_back(t[i]);
		}
		for (i = 0; i<n2; i++)
		{
			cin >> p[i];
			b.push_back(p[i]);
		}

		linkedlist result = merge(a, b);
		result.output();
		cin.clear();
	}
	return 0;
}