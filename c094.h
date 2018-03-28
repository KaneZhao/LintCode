#ifndef C94_H
#define C94_H
#include<iostream>
using namespace std;
/*
* �������е����·����
*
* ����һ�ö�������Ѱ��һ��·��ʹ��·�������·����������һ�ڵ��п�ʼ�ͽ�����·����Ϊ�����ڵ�֮������·���ϵĽڵ�Ȩֵ֮�ͣ�
* ����
* ����һ�ö�������
*   1
*  / \
* 2   3
* ���� 6
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
class Solution {
public:
	/**
	* @param root: The root of binary tree.
	* @return: An integer
	*/
	int maxPathSum(TreeNode * root) {
		// write your code here
		if (!root)
			return 0;
		if (!root->left && !root->right)
			return root->val;
		//��֤������ÿ������ֵ
		maxLen = maxVal(maxLen, root->val);
		//�ݹ�ش������ҽ��
		maxPathSum(root->left);
		maxPathSum(root->right);
		//�����ҽ���ֵ����0ʱ����root��ֵ���
		//֮���޸�root��ֵ
		int Left = 0, Right = 0;
		if (root->left&&root->left->val>0)
			Left = root->left->val;
		if (root->right&&root->right->val>0)
			Right = root->right->val;
		int res = Left + Right + root->val;
		maxLen = maxVal(res, maxLen);
		root->val = maxVal(Left, Right) + root->val;
		return maxLen;
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
	int maxLen = INT_MIN;
};
#endif