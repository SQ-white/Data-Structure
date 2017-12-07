#include <iostream> 
#include<assert.h>
#include <vector> 
#include <string> 
#include <sstream> 
using namespace std;

void QSwap(int* x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int PartSort1(vector<int>&a, int left, int right)
{
	int key = a[right];
	int keyidx = right;
	while (left <right)
	{
		while (left < right && a[left] <= key)
			++left;
		while (left < right && a[right] >= key)
			--right;
		if (a[left] != a[right])
			QSwap(&a[left], &a[right]);
	}
	QSwap(&a[left], &a[keyidx]);
	return right;
}




void QuickSort1(vector<int>&a, int left, int right)
{
	if (left < right)
	{
		int div = PartSort1(a, left, right);
		cout << div << endl;
	}
}
int main()
{

	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (int i = 0; i<n; i++) {
		vector<int> v;
		getline(cin, s);
		stringstream in(s);
		int tmp;
		while (in >> tmp)
			v.push_back(tmp);
		QuickSort1(v, 0, v.size() - 1);
	}
}