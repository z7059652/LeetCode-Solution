// 168ExcelSheetColumnTitle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
string convertToTitle(int n)
{
	string s;
	int m = 0;
	bool flag = false;
	if (n/26 == 0)
	{
		s += n % 26 + 'A' - 1;
		return s;
	}
	if (n == 26)
	{
		s += 'Z';
		return s;
	}
	while (n / 26 != 0)
	{
		flag = true;
		m = n % 26;
		if (m == 0)
		{
			s += 'Z';
		}
		else
		{
			s += m + 'A' - 1;
		}
		n = n / 26;
		if (m == 0)
		{
			n--;
		}
	}
	if (n != 0 && flag)
	{
		s += n + 'A' - 1;
	}
	string str;
	for (int i = s.length() - 1; i >= 0;i--)
	{
		str += s[i];
	}
	return str;
}
int _tmain(int argc, _TCHAR* argv[])
{
	printf("hello world\n");
	for (int i = 1; i <= 26*4;i++)
	{
		cout << i <<"   "<< convertToTitle(i) << endl;
	}
	system("pause");
	return 0;
}

