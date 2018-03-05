#ifndef C69_H
#define C69_H
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
* 二叉树的层次遍历
*
* 给出一棵二叉树，返回其节点值的层次遍历（逐层从左往右访问）
* 样例
* 给一棵二叉树 {3,9,20,#,#,15,7} ：
*     3
*    / \
*   9  20
*     /  \
*    15   7
* 返回他的分层遍历结果：
* [
* [3],
* [9,20],
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
	/*
	* @param root: A Tree
	* @return: Level order a list of lists of integer
	*/
	vector<vector<int>> levelOrder(TreeNode * root) {
		// write your code here
		vector<vector<int>> res;
		if (!root)
			return res;
		queue<TreeNode*> que;
		que.push(root);
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
		return res;
	}
};
#endif