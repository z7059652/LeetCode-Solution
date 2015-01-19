// leetcodesolution.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
using namespace std;
int atoi(const char *str)
{
	if (str == NULL || strlen(str) == 0)
		return 0;
	int i = 0;
	if (strcmp("INT_MAX", str) == 0)
		return 2147483647;
	if (strcmp("INT_MIN", str) == 0)
		return -2147483647;
	int iMn = 0;
	while (i < strlen(str) && (str[i] == ' ' || str[i] == '+' || str[i] == '-' || str[i] == '0'))
	{
		if (str[i] == ' ')
		{
			i++;
			continue;
		}
		if (str[i] == '-')
		{
			iMn++;
			i += 1;
			continue;
		}
		if (str[i] == '+')
		{
			i += 1;
			continue;
		}
		if (str[i] == '0')
		{
			i += 1;
			continue;
		}
	}
	int iSum = 0;
	while (i < strlen(str))
	{
		if (str[i] != '0')
			break;
		i++;
	}
	for (; i < strlen(str); i++)
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			continue;
		iSum *= 10;
		iSum += str[i] - '0';
	}
	if (iMn % 2 == 0)
		return iSum;
	return iSum*(-1);
}
const int N = 100;
int func()
{
	int k = 0;
	for (int i = 2; i < N;i++)
	{
		int j = N / i;
		while (j--)
		{
			k++;
		}

	}
	return k;
}
int _tmain(int argc, _TCHAR* argv[])
{
	char *sp = "    +0a32";
	cout << func() << endl;
	system("pause");
	return 0;
}

