#ifndef C691_H
#define C691_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ���������������ڵ�
*
* ��һ�ö�����������, ֻ�������ڵ��Ǳ�������. �ҵ���Щ�ڵ㲢����, ���û�нڵ㱻�����ͷ���ԭ�������ĸ��ڵ�.
* ����
* ��һ��BST:
*       4
*      / \
*     5   2
*    / \
*   1   3
* ����
* 
*       4
*      / \
*     2   5
*    / \
*   1   3
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
//�������,�õ�����,�������ҵ�����ĵ�
class Solution {
public:
	/*
	* @param : the given tree
	* @return: the tree after swapping
	*/
	TreeNode * bstSwappedNode(TreeNode * root) {
		// write your code here
		vector<int> res;
		inOrder(root, res);
		if (res.empty() || res.size() == 1)
			return root;
		int len = res.size();
		int i = 0, j = len - 1;
		bool flag1 = false, flag2 = false;
		while (i<j)
		{
			if (res[j] < res[j - 1])
			{
				flag1 = true;
			}
			else
				--j;
			if (res[i]>res[i + 1])
			{
				flag2 = true;
			}
			else
				++i;
			if (flag1&&flag2)
				break;
		}
		if (!(flag1&&flag2))
			return root;
		createTree(root, res[i], res[j]);
		return root;
	}
	void createTree(TreeNode *root, int i, int j)
	{
		if (root == NULL)
			return;
		createTree(root->left, i, j);
		if (root->val == i)
			root->val = j;
		else if (root->val == j)
			root->val = i;
		createTree(root->right, i, j);
	}
	/*
	bool isBST(TreeNode* root)
	{
		vector<int> res;
		inOrder(root, res);
		if (res.empty() || res.size() == 1)
			return true;
		for (int i = 0; i < res.size()-1; ++i)
		{
			if (res[i]>=res[i + 1])
			{
				return false;
			}
		}
		return true;
	}
	*/
	void inOrder(TreeNode *root,vector<int> &res)
	{
		if (root == NULL)
			return;
		inOrder(root->left, res);
		res.push_back(root->val);
		inOrder(root->right, res);
	}
};
//���������ڵ�node1,node2ΪҪ�����Ľڵ�
//�������,��������Ľڵ��,node1ȡ����Ե�ǰһ���ڵ�,node2ȡ����Եĺ�һ���ڵ�
class Solution2 {
public:
	/**
	* @param root: the given tree
	* @return: the tree after swapping
	*/
	TreeNode * bstSwappedNode(TreeNode * root) {
		// write your code here
		if (!root)
			return root;
		node1 = node2 = pre = NULL;
		inorder(root);
		if (node1&&node2)
		    swap(node1->val, node2->val);
		return root;
	}
	void inorder(TreeNode *root)
	{
		if (!root)
			return;
		inorder(root->left);
		if (pre && pre->val > root->val)
		{
			if (!node1)
			{
				node1 = pre;
				node2 = root;
			}
			else
				node2 = root;
		}
		pre = root;
		inorder(root->right);
	}
	TreeNode *node1, *node2, *pre;
};
#endif