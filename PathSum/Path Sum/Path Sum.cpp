// Path Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x,TreeNode* left,TreeNode* right) : val(x), left(left), right(right) {}
};

bool dfs(TreeNode* root,int sum,int target)
{
	if (root == NULL)
	{
		return false;
	}
	if (sum + root->val == target && root->right == NULL && root->left == NULL)
	{
		cout << "TRUE" << endl;
		return true;
	}
	sum += root->val;
	if (dfs(root->left, sum,target))
		return true;
	else
	{
		if (dfs(root->right, sum, target))
			return true;
		sum -= root->val;
		return false;
	}

}
bool hasPathSum(TreeNode *root, int sum) {
	if (root == NULL)
		return false;
//	int sum;
	dfs(root,0,sum);
}
int _tmain(int argc, _TCHAR* argv[])
{
	//struct TreeNode A(7);
	//struct TreeNode B(2);
	//struct TreeNode C(11,&A,&B);
	//struct TreeNode D(1);
	//struct TreeNode E(4,NULL,&D);
	//struct TreeNode F(13);
//	struct TreeNode G(8,&F,&E);
	struct TreeNode H(-3);
	struct TreeNode I(-2,NULL,&H);
	hasPathSum(&I,-5);
	system("pause");
	return 0;
}

