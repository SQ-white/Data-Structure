#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define stacksize 100

struct stack
{
	char strstack[stacksize];
	int top;
};

void InitStack(stack &s)
{
	s.top = -1;
}

//½øÕ»
char Push(stack &s, char a)
{
	if (s.top == stacksize - 1)
	{
		return 0;
	}
	s.top++;
	s.strstack[s.top] = a;
	return a;
}

//³öÕ»
char Pop(stack &s)
{
	if (s.top == -1)
	{
		return 0;
	}
	char a = s.strstack[s.top];
	s.top--;
	return a;
}

int Empty(stack &s, int re)
{
	if (s.top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Check(char *str)
{
	stack s;
	InitStack(s);
	int strn = strlen(str);
	for (int i = 0; i<strn; i++)
	{
		char a = str[i];
		switch (a)
		{
		case '(':
			Push(s, a);
			break;
		case ')':
			if (Pop(s) != '(')
			{
				return 0;
			}
			break;
		}
	}
	int re = 0;
	re = Empty(s, re);
	if (re == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	char str[100];
	int n, i;
	while (cin >> n)
	{
		for (i = 0; i < n; i++)
		{
			cin >> str;
			int re = Check(str);
			if (re == 1)
			{
				cout << "TRUE" << endl;
			}
			else if (re == 0)
			{
				cout << "FALSE" << endl;
			}
		}
	}
}