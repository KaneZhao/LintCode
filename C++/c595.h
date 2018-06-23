#ifndef C595_H
#define C595_H
#include<iostream>
#include<map>
using namespace std;
/*
* 二叉树最长连续序列
*
* 描述
* 给一棵二叉树，找到最长连续路径的长度。
* 这条路径是指 任何的节点序列中的起始节点到树中的任一节点都必须遵循 父-子 联系。最长的连续路径必须是从父亲节点到孩子节点（不能逆序）。
* 样例
* 举个例子：
*   1
*    \
*     3
*    / \
*   2   4
*        \
*         5
* 最长的连续路径为 3-4-5，所以返回 3。
*/
class TreeNode{
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val){
		this->val = val;
		this->right = this->left = NULL;
	}
};
class Solution {
public:
	/**
	* @param root: the root of binary tree
	* @return: the length of the longest consecutive sequence path
	*/
	int longestConsecutive(TreeNode * root) {
		// write your code here
		if (!root)
			return 0;
		m[root] = 1;
		helper(root);
		int max = 0;
		for (auto c : m)
		{
			if (c.second > max)
				max = c.second;
		}
		return max;
	}
	//从根节点开始处理,存放根节点及其连续序列长度,分别处理左右结点
	//如果结点子树的值为结点的值+1,则其连续序列长度为结点连续序列长度+1
	void helper(TreeNode *root)
	{
		if (!root)
			return;
		if (root->left)
		{
			if (root->left->val == root->val + 1)
			{
				m[root->left] = m[root] + 1;
			}
			else
				m[root->left] = 1;
			helper(root->left);
		}
		if (root->right)
		{
			if (root->right->val == root->val + 1)
			{
				m[root->right] = m[root] + 1;
			}
			else
				m[root->right] = 1;
			helper(root->right);
		}
	}
	map<TreeNode*, int> m;//存放结点及其连续序列的长度
};
#endif