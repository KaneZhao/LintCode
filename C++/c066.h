#ifndef C66_H
#define C66_H
#include<vector>
#include<iostream>
#include<stack>
using namespace std;
/*
* ��������ǰ�����
*
* ����һ�ö�������������ڵ�ֵ��ǰ�������
* 
* ����
* ����һ�ö����� {1,#,2,3},
* 1
*  \
*   2
*  /
* 3
* ���� [1,2,3].
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
	vector<int> preorderTraversal(TreeNode *root) {
		// write your code here
		preOrder(root);
		return val;		
	}
	void preOrder(TreeNode *node)
	{
		if (node != NULL)
		{
			val.push_back(node->val);
			preOrder(node->left);
			preOrder(node->right);
		}
	}
private:
	vector<int> val;
};
//�ǵݹ�
class Solution2 {
public:
	/*
	* @param root: A Tree
	* @return: Preorder in ArrayList which contains node values.
	*/
	vector<int> preorderTraversal(TreeNode * root) {
		// write your code here
		vector<int> res;
		stack<TreeNode*> stack;
		TreeNode *node = root;
		//���ʽ��node,��node��ջ,����������
		//��node������Ϊ��,��ȡջ������ջ,��ջ�������Һ�����Ϊ��ǰ���
		//��node�����Ӳ�Ϊ��,��������Ϊ��ǰ���
		//ֱ��node==NULL��ջΪ��
		while (node || !stack.empty())
		{
			while (node)
			{
				stack.push(node);
				res.push_back(node->val);
				node = node->left;
			}
			if (!stack.empty())
			{
				node = stack.top();
				stack.pop();
				node = node->right;
			}
		}
		return res;
	}
};
#endif