#ifndef C726_H
#define C726_H
#include<iostream>
using namespace std;
/*
*验证满二叉树
*
*如果一棵二叉树所有节点都有零个或两个子节点, 那么这棵树为满二叉树. 反过来说, 满二叉树中不存在只有一个子节点的节点
*样例：
*给出树 {1,2,3}, 返回 true
*给出树 {1,2,3,4}, 返回 false
*给出树 {1,2,3,4,5}, 返回 true
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
	/*
	* @param : the given tree
	* @return: Whether it is a full tree
	*/
	bool isFullTree(TreeNode * root) {
		// write your code here
		if (root == NULL)
			return true;
		if ((root->left == NULL&&root->right != NULL) || (root->left != NULL&&root->right == NULL))
			return false;
		return isFullTree(root->left) && isFullTree(root->right);
	}
};
#endif