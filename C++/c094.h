#ifndef C94_H
#define C94_H
#include<iostream>
using namespace std;
/*
* 二叉树中的最大路径和
*
* 给出一棵二叉树，寻找一条路径使其路径和最大，路径可以在任一节点中开始和结束（路径和为两个节点之间所在路径上的节点权值之和）
* 样例
* 给出一棵二叉树：
*   1
*  / \
* 2   3
* 返回 6
*/
class TreeNode{
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val)
	{
		this->val = val;
		this->left = this->right = NULL;
	}
};
class Solution {
public:
	/**
	* @param root: The root of binary tree.
	* @return: An integer
	*/
	int maxPathSum(TreeNode * root) {
		// write your code here
		if (!root)
			return 0;
		if (!root->left && !root->right)
			return root->val;
		//保证遍历到每个结点的值
		maxLen = maxVal(maxLen, root->val);
		//递归地处理左右结点
		maxPathSum(root->left);
		maxPathSum(root->right);
		//当左右结点的值大于0时才与root的值相加
		//之后修改root的值
		int Left = 0, Right = 0;
		if (root->left&&root->left->val>0)
			Left = root->left->val;
		if (root->right&&root->right->val>0)
			Right = root->right->val;
		int res = Left + Right + root->val;
		maxLen = maxVal(res, maxLen);
		root->val = maxVal(Left, Right) + root->val;
		return maxLen;
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
	int maxLen = INT_MIN;
};
#endif