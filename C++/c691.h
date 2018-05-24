#ifndef C691_H
#define C691_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 二叉搜索树交换节点
*
* 在一棵二叉搜索树中, 只有两个节点是被交换的. 找到这些节点并交换, 如果没有节点被交换就返回原来的树的根节点.
* 样例
* 给一棵BST:
*       4
*      / \
*     5   2
*    / \
*   1   3
* 返回
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
//中序遍历,得到序列,在其中找到逆序的点
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
//定义两个节点node1,node2为要交换的节点
//中序遍历,对于逆序的节点对,node1取逆序对的前一个节点,node2取逆序对的后一个节点
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