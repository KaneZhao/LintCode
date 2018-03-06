#ifndef C011_H
#define C011_H
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
* �������������������
*
* ��������ֵ k1 �� k2��k1 < k2����һ������������ĸ��ڵ㡣�ҵ���������ֵ�� k1 �� k2 ��Χ�ڵĽڵ㡣����ӡ����x(k1 <= x <= k2) ���� x �Ƕ�����������еĽڵ�ֵ��������������Ľڵ�ֵ��
* ����
* ����� k1 = 10 �� k2 = 22, ��ĳ���Ӧ�÷���[12, 20, 22].
*     20
*     / \
*    8   22
*   / \
*  4  12
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
	* @param root: param root: The root of the binary search tree
	* @param k1: An integer
	* @param k2: An integer
	* @return: return: Return all keys that k1<=key<=k2 in ascending order
	*/
	vector<int> searchRange(TreeNode * root, int k1, int k2) {
		// write your code here
		vector<int> nums;
		vector<int> res;
		if (!root)
			return nums;
		inorder(root, res);
		//Ѱ������Ҫ��Ľڵ��ֵ
		for (auto c : res)
		{
			if (c >= k1&&c <= k2)
				nums.push_back(c);
		}
		return nums;
	}
	//��������õ��ڵ������ֵ
	void inorder(TreeNode *root,vector<int> &res)
	{
		if (!root)
			return;
		inorder(root->left,res);
		res.push_back(root->val);
		inorder(root->right, res);
	}
};
#endif