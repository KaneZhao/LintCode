#ifndef C95_H
#define C95_H
#include<iostream>
#include<vector>
using namespace std;
/*
* Given a binary tree, determine if it is a valid binary search tree (BST).
*
* Assume a BST is defined as follows:
*
* The left subtree of a node contains only nodes with keys less than the node's key.
* The right subtree of a node contains only nodes with keys greater than the node's key.
* Both the left and right subtrees must also be binary search trees.
* A single node tree is a BST
*/
class TreeNode{
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val){
		this->val = val;
		this->left = this->right = NULL;
	}
};
class Solution {
public:
	/**
	* @param root: The root of binary tree.
	* @return: True if the binary tree is BST, or false
	*/
	bool isValidBST(TreeNode *root) {
		// write your code here
		vector<int> res;
		inOrder(root, res);
		if (res.empty() || res.size() == 1)
			return true;
		for (int i = 0; i < res.size() - 1; ++i)
		{
			if (res[i] >= res[i + 1])
				return false;
		}
		return true;
	}
	void inOrder(TreeNode* root,vector<int> &res)
	{
		if (root == NULL)
			return;
		inOrder(root->left, res);
		res.push_back(root->val);
		inOrder(root->right, res);
	}
};
#endif