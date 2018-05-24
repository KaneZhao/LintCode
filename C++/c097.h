#ifndef C97_H
#define C97_H
#include<iostream>
using namespace std;
/*
* ��������������
*
* ����һ�����������ҳ��������ȡ�
* �����������Ϊ���ڵ㵽��ԶҶ�ӽڵ�ľ��롣
* ����
* ����һ�����µĶ�����:
*   1
*  / \
* 2   3
*     / \
*    4   5
* �����������������Ϊ3.
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