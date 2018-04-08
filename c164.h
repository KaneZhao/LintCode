#ifndef C164_H
#define C164_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ��ͬ�Ķ�������� II
*
* ����n������������1...nΪ�ڵ���ɵĲ�ͬ�Ķ��������
* ����
* ����n = 3����������5�ֲ�ͬ��̬�Ķ����������
* 1         3     3       2    1
*  \       /     /       / \    \
*   3     2     1       1   3    2
*  /     /       \                \
* 2     1         2                3
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
	* @paramn n: An integer
	* @return: A list of root
	*/
	vector<TreeNode *> generateTrees(int n) {
		// write your code here
		vector<TreeNode *> vTree;
		if (n < 0)
			return vTree;
		vTree = build(1, n);
		return vTree;
	}
	//����start��end���в�ͬ�Ķ�����
	vector<TreeNode*> build(int start, int end)
	{
		vector<TreeNode*> vTree;
		if (start > end)
		{
			vTree.push_back(NULL);
			return vTree;
		}
		//����i,������Ϊstart��i-1,������Ϊi+1��end
		//���ұ�������������ÿһ�����
		for (int i = start; i <= end; ++i)
		{
			vector<TreeNode*> left = build(start, i - 1);
			vector<TreeNode*> right = build(i + 1, end);
			for (int j = 0; j < left.size(); ++j)
			{
				for (int k = 0; k < right.size(); ++k)
				{
					TreeNode* node = new TreeNode(i);
					node->left = left[j];
					node->right = right[k];
					vTree.push_back(node);
				}
			}
		}
		return vTree;
	}
};
#endif