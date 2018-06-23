#ifndef C595_H
#define C595_H
#include<iostream>
#include<map>
using namespace std;
/*
* ���������������
*
* ����
* ��һ�ö��������ҵ������·���ĳ��ȡ�
* ����·����ָ �κεĽڵ������е���ʼ�ڵ㵽���е���һ�ڵ㶼������ѭ ��-�� ��ϵ���������·�������ǴӸ��׽ڵ㵽���ӽڵ㣨�������򣩡�
* ����
* �ٸ����ӣ�
*   1
*    \
*     3
*    / \
*   2   4
*        \
*         5
* �������·��Ϊ 3-4-5�����Է��� 3��
*/
class TreeNode{
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val){
		this->val = val;
		this->right = this->left = NULL;
	}
};
class Solution {
public:
	/**
	* @param root: the root of binary tree
	* @return: the length of the longest consecutive sequence path
	*/
	int longestConsecutive(TreeNode * root) {
		// write your code here
		if (!root)
			return 0;
		m[root] = 1;
		helper(root);
		int max = 0;
		for (auto c : m)
		{
			if (c.second > max)
				max = c.second;
		}
		return max;
	}
	//�Ӹ��ڵ㿪ʼ����,��Ÿ��ڵ㼰���������г���,�ֱ������ҽ��
	//������������ֵΪ����ֵ+1,�����������г���Ϊ����������г���+1
	void helper(TreeNode *root)
	{
		if (!root)
			return;
		if (root->left)
		{
			if (root->left->val == root->val + 1)
			{
				m[root->left] = m[root] + 1;
			}
			else
				m[root->left] = 1;
			helper(root->left);
		}
		if (root->right)
		{
			if (root->right->val == root->val + 1)
			{
				m[root->right] = m[root] + 1;
			}
			else
				m[root->right] = 1;
			helper(root->right);
		}
	}
	map<TreeNode*, int> m;//��Ž�㼰���������еĳ���
};
#endif