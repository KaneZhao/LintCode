#ifndef C689_H
#define C689_H
#include<iostream>
#include<vector>
using namespace std;
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
	/*
	* @param : the root of tree
	* @param : the target sum
	* @return: two number from tree witch sum is n
	*/
	vector<int> twoSum(TreeNode * root, int n) {
		// write your code here
		vector<int> res;
		if (root == NULL)
			return res;
		TreeNode *p = root;
		createVec(root, p, n, res);
		return res;
	}
	//p为root中的任意一个节点,找到满足条件的节点则返回,否则继续遍历
	void createVec(TreeNode *root, TreeNode *p, int n,vector<int> &res)
	{
		if (p == NULL)
			return;
		if (isValid(root, n - p->val))
		{
			res.push_back(p->val);
			res.push_back(n - p->val);
			return;
		}
		else
		{
			createVec(root, p->left, n, res);
			createVec(root, p->right, n, res);
		}
	}
	//判断以root为根的树中,是否存在值为n的节点
	bool isValid(TreeNode *root, int n)
	{
		if (root == NULL)
			return false;
		if (n > root->val)
		{
			if (root->right == NULL)
				return false;
			else
				return isValid(root->right, n);
		}
		else if (n == root->val)
			return true;
		else
		{
			if (root->left == NULL)
				return false;
			else
				return isValid(root->left, n);
		}
	}
};
#endif