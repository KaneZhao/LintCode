#ifndef C68_H
#define C68_H
#include<vector>
#include<iostream>
#include<stack>
using namespace std;
/*
* �������ĺ������
*
* ����һ�ö�������������ڵ�ֵ�ĺ��������
*
* ����
* ����һ�ö����� {1,#,2,3},
* 1
*  \
*   2
*  /
* 3
* ���� [3,2,1].
* ��ս
* ����ʹ�÷ǵݹ�ʵ��ô��
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
	vector<int> postorderTraversal(TreeNode *root) {
		// write your code here
		vector<int> res;
		if (!root)
			return res;
		stack<TreeNode*> stack;
		TreeNode *cur;
		TreeNode *pre = NULL;
		stack.push(root);
		while (!stack.empty())
		{
			cur = stack.top();
			if ((cur->left == NULL&&cur->right == NULL) || (pre != NULL && (pre == cur->left || pre == cur->right)))
			{
				res.push_back(cur->val);
				stack.pop();
				pre = cur;
			}
			else
			{
				if (cur->right != NULL)
					stack.push(cur->right);
				if (cur->left != NULL)
					stack.push(cur->left);
			}
		}
		return res;
	}
};
#endif