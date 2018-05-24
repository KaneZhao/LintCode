#ifndef C71_H
#define C71_H
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
/*
* 二叉树的锯齿形层次遍历
*
* 给出一棵二叉树，返回其节点值的锯齿形层次遍历（先从左往右，下一层再从右往左，层与层之间交替进行）
* 样例
* 给出一棵二叉树 {3,9,20,#,#,15,7},
*    3
*   / \
*  9  20
*    /  \
*   15   7
* 返回其锯齿形的层次遍历为：
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