#ifndef C1353_H
#define C1353_H
#include<iostream>
using namespace std;
/*
* Sum Root to Leaf Numbers
*
* 描述
* Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
* An example is the root-to-leaf path 1->2->3 which represents the number 123.
* Find the total sum of all root-to-leaf numbers.
* A leaf is a node with no children.
* 样例
* Example:
*  Input: [1,2,3]
*    1
*   / \
*  2   3
* Output: 25
* Explanation:
* The root-to-leaf path 1->2 represents the number 12.
* The root-to-leaf path 1->3 represents the number 13.
* Therefore, sum = 12 + 13 = 25.
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
	* @param root: the root of the tree
	* @return: the total sum of all root-to-leaf numbers
	*/
	int sumNumbers(TreeNode * root) {
		// write your code here
		if (!root)
			return 0;
		int num = 0;
		helper(root, num);
		return sum;
	}
	//计算节点root所表示的数字
	void helper(TreeNode *root, int &num)
	{
		if (!root)
			return;
		num = num*10 + root->val;
		//当root为叶子节点,将num的值加到sum上
		if (!root->left&&!root->right)
			sum += num;
		if (root->left)
		{
			helper(root->left, num);
			num -= root->left->val;
			num /= 10;
		}
		if (root->right)
		{
			helper(root->right, num);
			num -= root->right->val;
			num /= 10;
		}
	}
	int sum = 0;
};
#endif