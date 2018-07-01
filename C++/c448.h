#ifndef C448_H
#define C448_H
#include<iostream>
using namespace std;
/*
* �����������������
*
* ����
* ����һ�����������(ʲô�Ƕ��������)���Լ�һ���ڵ㣬��ýڵ�����������ĺ�̣����û�з���null
* ��֤p�Ǹ����������е�һ���ڵ㡣(������ֱ��ͨ���ڴ��ַ�ҵ�p)
* ����
* ���� tree = [2,1] node = 1:
*   2
*  /
* 1
* ���� node 2.
* ���� tree = [2,1,3] node = 2:
*   2
*  / \
* 1   3
* ���� node 3.
* ��ս
* O(h)������h��BST�ĸ߶ȡ�
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
	* @param root: The root of the BST.
	* @param p: You need find the successor node of p.
	* @return: Successor of p.
	*/
	TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
		// write your code here
		if (!root || !p)
			return NULL;
		//��p��������Ϊ��,���������������������,������Ϊ��������������������
		//���������������������,ֱ�ӷ���p��������
		if (p->right)
		{
			if (p->right->left)
			{
				TreeNode *temp = p->right->left;
				while (temp->left)
				{
					temp = temp->left;
				}
				return temp;
			}
			else
				return p->right;
		}
		else
		{
			if (p->val > root->val)
				return NULL;
			findNext(root, p);
			return temp;
		}
	}
	//��pû����������������ҵ�root�е�һ��ֵ����p�Ľڵ�
	void findNext(TreeNode *root, TreeNode* p)
	{
		if (root->val > p->val)
		{
			temp = root;
			findNext(root->left, p);
		}
		else if (root->val < p->val)
		{
			findNext(root->right, p);
		}
		else
			return;
	}
	TreeNode *temp = NULL;
};
#endif