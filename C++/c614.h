#ifndef C614_H
#define C614_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
/*
* ������������������� II
*
* ����
* ����һ�ö��������ҵ����������·���ĳ��ȡ�
* ·�������յ����Ϊ������������ڵ㡣
* ����
*      1
*     / \
*    2   0
*   /
*  3
* ���� 4 // 0-1-2-3
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
	* @param root: the root of binary tree
	* @return: the length of the longest consecutive sequence path
	*/
	int longestConsecutive2(TreeNode * root) {
		// write your code here
		if (!root)
			return 0;
		helper(root);
		return maxLength;
	}
	//���ؽڵ��<�����,�����>
	pair<int,int> helper(TreeNode *root)
	{
		if (!root)
			return make_pair(0, 0);
		//up��ʾ�����ĳ���,down��ʾ�����ĳ���
		int up = 1, down = 1;
		pair<int, int> left = helper(root->left);
		pair<int, int> right = helper(root->right);
		//��������Ϊ��,��root�ڵ��ֵ��������ֵ+1,upֵΪ��������г��ȼ�һ
		//��root�ڵ��ֵ��������ֵ-1,downֵΪ��ݼ����г��ȼ�һ
		if (root->left)
		{
			if (root->left->val == root->val + 1)
				up = max(up, left.first + 1);
			if (root->left->val == root->val - 1)
				down = max(down, left.second + 1);
		}
		//��������Ϊ��,��root�ڵ��ֵ��������ֵ+1,upֵΪ��������г��ȼ�һ
		//��root�ڵ��ֵ��������ֵ-1,downֵΪ��������г��ȼ�һ
		if (root->right)
		{
			if (root->right->val == root->val + 1)
				up = max(up, right.first + 1);
			if (root->right->val == root->val - 1)
				down = max(down, right.second + 1);
		}
		maxLength = max(maxLength, up + down - 1);
		return make_pair(up, down);
	}
	int maxLength = 1;//���������·���ĳ���
};
#endif