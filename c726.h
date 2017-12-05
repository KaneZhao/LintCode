#ifndef C726_H
#define C726_H
#include<iostream>
using namespace std;
/*
*��֤��������
*
*���һ�ö��������нڵ㶼������������ӽڵ�, ��ô�����Ϊ��������. ������˵, ���������в�����ֻ��һ���ӽڵ�Ľڵ�
*������
*������ {1,2,3}, ���� true
*������ {1,2,3,4}, ���� false
*������ {1,2,3,4,5}, ���� true
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
	* @param : the given tree
	* @return: Whether it is a full tree
	*/
	bool isFullTree(TreeNode * root) {
		// write your code here
		if (root == NULL)
			return true;
		if ((root->left == NULL&&root->right != NULL) || (root->left != NULL&&root->right == NULL))
			return false;
		return isFullTree(root->left) && isFullTree(root->right);
	}
};
#endif