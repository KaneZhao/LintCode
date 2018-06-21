#ifndef C1360_H
#define C1360_H
#include<iostream>
using namespace std;
/*
* Symmetric Tree
*
* ����
* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
* Bonus points if you could solve it both recursively and iteratively.
* ����
* For example, this binary tree {1,2,2,3,4,4,3} is symmetric:
*     1
*    / \
*   2   2
*  / \ / \
* 3  4 4  3
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
	* @param root: root of the given tree
	* @return: whether it is a mirror of itself
	*/
	bool isSymmetric(TreeNode * root) {
		// Write your code here
		return helper(root, root);
	}
	//�������Ŷ�����,һ���ȷ����������ٷ���������
	//��һ���ȷ����������ٷ���������,���ʵ��Ľڵ�ֵ����ͬ����˵���Գ�
	bool helper(TreeNode *root1, TreeNode *root2)
	{
		if (!root1&&!root2)
			return true;
		if (!root1 || !root2)
			return false;
		if (root1->val != root2->val)
			return false;
		return helper(root1->left, root2->right) && helper(root1->right, root2->left);
	}
};
#endif
