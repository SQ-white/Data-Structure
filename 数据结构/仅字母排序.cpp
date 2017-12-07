#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;

int main()
{
	char a[60];
	int i, j, n, temp;
	cin.getline(a, 60);
	n = strlen(a);
	for (i = 0; i < n; i++) {
		if (a[i]<'A' || a[i]>'Z')
			continue;
		for (j = i + 1; j < n; j++) {
			if (a[j] >= 'A' && a[j] <= 'Z') {
				if (a[i] > a[j])
				{
					temp = a[j];
					a[j] = a[i];
					a[i] = temp;
				}
			}
		}
	}

	for (i = 0; i < n; i++)
		cout << a[i];

	return 0;

}