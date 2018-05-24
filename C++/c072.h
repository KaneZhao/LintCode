#ifndef C72_H
#define C72_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ��������ͺ�����������������
*
* ������������ͺ�����������������
* ע������
* ����Լ������в�������ͬ��ֵ�Ľڵ�
* ����
* ����������������� [1,2,3] �ͺ�������� [1,3,2]
* �������µ�����
*   2
*  /  \
* 1    3
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
	* @param inorder: A list of integers that inorder traversal of a tree
	* @param postorder: A list of integers that postorder traversal of a tree
	* @return: Root of a tree
	*/
	typedef vector<int>::iterator iter;
	TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
		// write your code here
		if (inorder.empty())
			return NULL;
		TreeNode *node = helper(postorder.begin(), postorder.end(), inorder.begin(), inorder.end());
		return node;
	}
	//�ݹ�ع��������
	//postorder�����һ��Ԫ����Ϊ���ڵ�rootVal,��inorder��Ѱ��rootVal,������������Ϊ�µ�
	//inorder,���ɴ˻���µ�postorder
	TreeNode *helper(iter pstart, iter pend, iter istart, iter iend)
	{
		if (pend == pstart)
			return NULL;
		int rootVal = *(pend - 1);
		iter rootIter = find(istart, iend, rootVal);
		TreeNode *res = new TreeNode(rootVal);
		res->left = helper(pstart, pstart + (rootIter - istart), istart, rootIter);
		res->right = helper(pstart + (rootIter - istart) ,pend -1, rootIter + 1, iend);
		return res;
	}
};
#endif