#ifndef C97_H
#define C97_H
#include<iostream>
using namespace std;
/*
* 二叉树的最大深度
*
* 给定一个二叉树，找出其最大深度。
* 二叉树的深度为根节点到最远叶子节点的距离。
* 样例
* 给出一棵如下的二叉树:
*   1
*  / \
* 2   3
*     / \
*    4   5
* 这个二叉树的最大深度为3.
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
	* @return: An integer
	*/
	int maxDepth(TreeNode *root) {
		// write your code here
		if (root == NULL)
			return 0;
		if (root->left == NULL&&root->right == NULL)
			return 1;
		int depth = maxVal(maxDepth(root->left), maxDepth(root->right)) + 1;
		return depth;
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif