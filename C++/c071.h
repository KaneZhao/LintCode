#ifndef C71_H
#define C71_H
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
/*
* �������ľ���β�α���
*
* ����һ�ö�������������ڵ�ֵ�ľ���β�α������ȴ������ң���һ���ٴ������󣬲����֮�佻����У�
* ����
* ����һ�ö����� {3,9,20,#,#,15,7},
*    3
*   / \
*  9  20
*    /  \
*   15   7
* ���������εĲ�α���Ϊ��
* [
* [3],
* [20,9],
* [15,7]
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
	vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
		// write your code here
		vector<vector<int>> res;
		if (!root)
			return res;
		queue<TreeNode*> que;
		que.push(root);
		int flag = 0;
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
			if (flag % 2)
				reverse(vec.begin(), vec.end());
			flag++;
			res.push_back(vec);
		}
		return res;
	}
};
#endif