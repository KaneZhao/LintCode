#ifndef C70_H
#define C70_H
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
/*
* �������Ĳ�α��� II
*
* ����һ�ö�������������ڵ�ֵ�ӵ����ϵĲ�������������Ҷ�ڵ����ڲ㵽���ڵ����ڵĲ������Ȼ�����������ұ�����
* ����
* ����һ�ö����� {3,9,20,#,#,15,7},
*   3
*   / \
*  9  20
*     /  \
*    15   7
* ���մ������ϵĲ�α���Ϊ��
* [
* [15,7],
* [9,20],
* [3]
* ]
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
	* @param root: A tree
	* @return: buttom-up level order a list of lists of integer
	*/
	vector<vector<int>> levelOrderBottom(TreeNode * root) {
		// write your code here
		vector<vector<int>> res;
		if (!root)
			return res;
		queue<TreeNode*> que;
		que.push(root);
		//�����ڲ�α���
		while (!que.empty())
		{
			int size = que.size();
			vector<int> vec;
			for (int i = 0; i < size; ++i)
			{
				TreeNode *node = que.front();
				que.pop();
				vec.push_back(node->val);
				if (node->left)
					que.push(node->left);
				if (node->right)
					que.push(node->right);
			}
			res.push_back(vec);
		}
		//��ת��������
		reverse(res.begin(), res.end());
		return res;
	}
};
#endif