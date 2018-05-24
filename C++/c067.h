#ifndef C66_H
#define C66_H
#include<vector>
#include<iostream>
#include<stack>
using namespace std;
/*
* ���������������
*
* ����һ�ö�������������ڵ�ֵ�����������
*
* ����
* ����һ�ö����� {1,#,2,3},
* 1
*  \
*   2
*  /
* 3
* ���� [1,3,2].
* ��ս
* ����ʹ�÷ǵݹ�ʵ��ô��
*/
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};
//�ݹ�
class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		// write your code here
		//TreeNode *node = root;
		vector<TreeNode*> tVal;
		vector<int> res;
		while (root != NULL || tVal.size() != 0)
		{
			
			
				while (root != NULL){
					tVal.push_back(root);
					root = root->left;
				}
				root = tVal.back();
				tVal.pop_back();
				res.push_back(root->val);
				root = root->right;
			
		}
		return res;
	}
};
//�ǵݹ�
class Solution2 {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		// write your code here
		vector<int> res;
		stack<TreeNode*> stack;
		TreeNode *node = root;
		//���ʽ��node,���������ջ
		//��������Ϊ��,ȡջ��Ԫ�ز���ջ,��ջ��Ԫ�ص��Һ�����Ϊ��ǰ���
		//�������Ӳ�Ϊ��,����������Ϊ��ǰ���
		//ֱ��node==NULL��ջΪ��
		while (node || !stack.empty())
		{
			while (node)
			{
				stack.push(node);
				node = node->left;
			}
			if (!stack.empty())
			{
				node = stack.top();
				stack.pop();
				res.push_back(node->val);
				node = node->right;
			}
		}
		return res;
	}
};
#endif