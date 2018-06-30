#ifndef C1172_H
#define C1172_H
#include<iostream>
#include<cmath>
using namespace std;
/*
* Binary Tree Tilt
*
* 描述
* Given a binary tree, return the tilt of the whole tree.
* The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
* The tilt of the whole tree is defined as the sum of all nodes' tilt.
* 1.The sum of node values in any subtree won't exceed the range of 32-bit integer.
* 2.All the tilt values won't exceed the range of 32-bit integer.
* 样例
* Input:
*     1
*   /   \
*  2     3
* Output: 1
* Explanation:
* Tilt of node 2 : 0
* Tilt of node 3 : 0
* Tilt of node 1 : |2-3| = 1
* Tilt of binary tree : 0 + 0 + 1 = 1
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
	* @param root: the root
	* @return: the tilt of the whole tree
	*/
	int findTilt(TreeNode * root) {
		// Write your code here
		if (!root)
			return 0;
		nodeSum(root);
		return tilt;
	}
	//将结点的值置为左右子树值的和
	int nodeSum(TreeNode *root)
	{
		if (!root)
			return 0;
		if (!root->left&&!root->right)
			return root->val;
		root->val += nodeSum(root->left);
		root->val += nodeSum(root->right);
		int l = 0, r = 0;
		if (root->left)
			l = root->left->val;
		if (root->right)
			r = root->right->val;
		tilt += abs(l - r);//计算结点的tilt值
		return root->val;
	}
	int tilt = 0;//记录所有结点tilt值得和
};
#endif