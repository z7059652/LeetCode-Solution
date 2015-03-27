// Largest Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <valarray>
using namespace std;
bool MySort(const string v1,const string v2)
{
	return v1.compare(v2);
}
string largestNumber(vector<int> &num)
{
	if (num.size() == 0)
	{
		return NULL;
	}
	int iMaxlen = 0;
	char temp[30];
	memset(temp, 0, sizeof(temp));
	map<string, int> m1;
	map<string, int> mOld;
	vector<string> vs;
//	list<string> lOld;
	for (int i = 0; i < num.size(); i++)
	{
//		_itoa(num[i], temp, 10);
		sprintf(temp,"%d",num[i]);
		iMaxlen = iMaxlen > strlen(temp) ? iMaxlen : strlen(temp);
		vs.push_back(string(temp, strlen(temp)));
//		lOld.push_back(string(temp, strlen(temp)));
//		mOld.insert()
	}
//	lOld.sort();
	vector<string> ss(vs);
	list<string> res;
	iMaxlen *= 2;
	for (int i = 0; i < vs.size();i++)
	{
		while (vs[i].size() < iMaxlen)
		{
			vs[i] += vs[i];
		}
		res.push_back(string(vs[i].begin(),vs[i].begin()+iMaxlen));
		m1.insert(pair<string,int>(string(vs[i].begin(), vs[i].begin() + iMaxlen),i));
	}
	/*qsort(res.begin(), res.back(), MySort);*/
	res.sort();
	string tempres;
	for (list<string>::reverse_iterator it = res.rbegin(); it != res.rend();it++)
	{
		cout << *it << endl;
		tempres += ss[m1[*it]];
	}
	cout << iMaxlen << endl;
	return tempres;
}

///////////////////////////////////////////////////////////////
void Swap(int i, int j, vector<int> &a)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
int ncount;
list<string> res;
void lfs(int i, int n, vector<int> &num)
{
	if (i < 0)
	{
		ncount++;
		string s;
		for (int j = 0; j < num.size(); j++)
		{
			char temp[30];
			sprintf(temp, "%d", num[j]);
			s += string(temp, strlen(temp));
		}
		res.push_back(s);
		return;
	}
	for (int j = i; j <= n; j++)
	{
		Swap(i, j, num);
		lfs(i - 1, n, num);
		Swap(j, i, num);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//atoi();
	int i = 12345678;
	char str[12];
	string s;
//	_itoa(i, str, 10);
//	sprintf(str,"%d",);
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
// 	num.push_back(8);
// 	num.push_back(9);
// 	num.push_back(123);
// 	num.push_back(1230);

	//	string s(str,strlen(str));
//	s += s;
//	cout << s.size() << endl;
//	cout << largestNumber(num) << endl;
	int n = num.size();
	lfs(2, 2,num);
	res.sort();
	res.reverse();
	cout << ncount << endl;
	cout << *res.begin() << endl;
	system("pause");
	return 0;
}

