// 20ValidParentheses.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>
#include <iostream>
using namespace std;
stack<char> s1;
bool isValid(string s) 
{
	for (int i = 0; i < s.length();i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			s1.push(s[i]);
			continue;
		}
		if (s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if (s1.size() == 0)
			{
				return false;
			}
		}
		if (s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if (s[i] == ')' && '('!= s1.top())
			{
				return false;
			}
			if (s[i] == '}' && s1.top() != '{')
			{
				return false;
			}
			if (s[i] == ']' && s1.top() != '[')
			{
				return false;
			}
			s1.pop();
		}
	}
	if (s1.size() != 0)
	{
		return false;
	}
	return true;
}


int _tmain(int argc, _TCHAR* argv[])
{
	isValid(string("()"));
	return 0;
}

