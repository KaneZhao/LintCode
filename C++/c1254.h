#ifndef C1254_H
#define C1254_H
#include<iostream>
using namespace std;
/*
* Sum of Left Leaves
*
* 描述
* Find the sum of all left leaves in a given binary tree.
* 样例
*   3
*  / \
* 9  20
*   /  \
*  15   7
* There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
	* @param root: t
	* @return: the sum of all left leaves
	*/
	int sumOfLeftLeaves(TreeNode * root) {
		// Write your code here
		if (!root)
			return 0;
		//处理结点有左子树，且左子树是叶子结点的情况
		if (root->left&&!root->left->left&&!root->left->right)
		{
			sum += root->left->val;
		}
		sumOfLeftLeaves(root->left);
		sumOfLeftLeaves(root->right);
		return sum;
	}
	int sum = 0;
};
#endif