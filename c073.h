#ifndef C73_H
#define C73_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ǰ�������������������������
*
* ����ǰ�������������������������.
* ע������
* ����Լ������в�������ͬ��ֵ�Ľڵ�
* ����
* �������������[1,2,3]��ǰ�������[2,1,3]. �������µ���:
*   2
*  / \
* 1   3
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
	/**
	*@param preorder : A list of integers that preorder traversal of a tree
	*@param inorder : A list of integers that inorder traversal of a tree
	*@return : Root of a tree
	*/
public:
	typedef vector<int>::iterator iter;
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		// write your code here
		if (preorder.empty())
			return NULL;
		TreeNode *node = helper(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
		return node;
	}
	//�ݹ鹹�������
	//preorder��һ��Ԫ��rootval��Ϊ���ڵ�,��inorder��Ѱ��rootval�õ�rootIter,rootIter���Ԫ��λ�ڸ��ڵ�
	//��������,�ұ�Ԫ��λ�ڸ��ڵ��������
	TreeNode *helper(iter pstart, iter pend, iter istart, iter iend)
	{
		if (pstart >= pend)
			return NULL;
		int rootVal = *pstart;
		iter rootIter = find(istart, iend, rootVal);
		TreeNode *res = new TreeNode(rootVal);
		res->left = helper(pstart + 1, pstart + (rootIter - istart) + 1, istart, rootIter);
		res->right = helper(pstart + (rootIter - istart) + 1, pend, rootIter + 1, iend);
		return res;
	}
};
#endif