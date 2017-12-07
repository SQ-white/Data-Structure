#include<iostream>
using namespace std;

struct Stud
{
	long no;
	char name[10];
	int lengua;
	int math;
	int english;
	int sum;

};

void swap(Stud * x, Stud *y)
{
	Stud tmp = *x;
	*x = *y;
	*y = tmp;
};

int main()
{
	int n;
	cin >> n;
	struct Stud y[1000];
	for (int i = 0; i<n; i++)
		cin >> y[i].no >> y[i].name >> y[i].lengua >> y[i].math >> y[i].english;

	for (int k = 0; k<n; k++)
		y[k].sum = y[k].lengua + y[k].math + y[k].english;

	for (int t = 0; t < n; t++)
	{
		for (int m = 0; m < n - t; m++) {
			if (y[m + 1].sum > y[m].sum)
				swap(&y[m], &y[m + 1]);
			if (y[m + 1].sum == y[m].sum)
			{
				if (y[m + 1].lengua > y[m].lengua)
					swap(&y[m], &y[m + 1]);
				if (y[m + 1].lengua == y[m].lengua) {
					if (y[m + 1].math > y[m].math)
						swap(&y[m], &y[m + 1]);
					else if (y[m + 1].math == y[m].math)
					{
						if (y[m + 1].english > y[m].english)
							swap(&y[m], &y[m + 1]);
					}
				}


			}

		}
	}

	for (int j = 0; j <n; j++)
	{
		cout << y[j].no << " " << y[j].name << " " << y[j].sum << endl;
	}
}