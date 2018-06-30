#ifndef C1165_H
#define C1165_H
#include<iostream>
using namespace std;
/*
* Subtree of Another Tree
*
* 描述
* Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
* 样例
* Example 1:
* Given tree s:
*     3
*    / \
*   4   5
*  / \
* 1   2
* Given tree t:
*   4
*  / \
* 1   2
* Return true, because t has the same structure and node values with a subtree of s.
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
	* @param s: the s' root
	* @param t: the t' root
	* @return: whether tree t has exactly the same structure and node values with a subtree of s
	*/
	bool isSubtree(TreeNode * s, TreeNode * t) {
		// Write your code here
		//若s和t不完全相同,继续判断s的左右子树和t,返回结果的并
		if (!s&&!t)
			return true;
		else if (!s || !t)
			return false;
		if (isEqual(s, t))
			return true;
		else
			return isSubtree(s->left, t) || isSubtree(s->right, t);
	}
	//判断root和node是否完全相同
	bool isEqual(TreeNode *root, TreeNode *node)
	{
		if (!root&&!node)
			return true;
		else if (!root || !node)
			return false;
		if (root->val == node->val)
		{
			return isEqual(root->left, node->left) && isEqual(root->right, node->right);
		}
		else
			return false;
	}
};
#endif