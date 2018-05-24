#ifndef C70_H
#define C70_H
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
/*
* 二叉树的层次遍历 II
*
* 给出一棵二叉树，返回其节点值从底向上的层次序遍历（按从叶节点所在层到根节点所在的层遍历，然后逐层从左往右遍历）
* 样例
* 给出一棵二叉树 {3,9,20,#,#,15,7},
*   3
*   / \
*  9  20
*     /  \
*    15   7
* 按照从下往上的层次遍历为：
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
		//类似于层次遍历
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
		//反转容器内容
		reverse(res.begin(), res.end());
		return res;
	}
};
#endif