#ifndef C164_H
#define C164_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 不同的二叉查找树 II
*
* 给出n，生成所有由1...n为节点组成的不同的二叉查找树
* 样例
* 给出n = 3，生成所有5种不同形态的二叉查找树：
* 1         3     3       2    1
*  \       /     /       / \    \
*   3     2     1       1   3    2
*  /     /       \                \
* 2     1         2                3
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
	/**
	* @paramn n: An integer
	* @return: A list of root
	*/
	vector<TreeNode *> generateTrees(int n) {
		// write your code here
		vector<TreeNode *> vTree;
		if (n < 0)
			return vTree;
		vTree = build(1, n);
		return vTree;
	}
	//构建start到end所有不同的二叉树
	vector<TreeNode*> build(int start, int end)
	{
		vector<TreeNode*> vTree;
		if (start > end)
		{
			vTree.push_back(NULL);
			return vTree;
		}
		//对于i,左子树为start到i-1,右子树为i+1到end
		//并且遍历左右子树的每一种情况
		for (int i = start; i <= end; ++i)
		{
			vector<TreeNode*> left = build(start, i - 1);
			vector<TreeNode*> right = build(i + 1, end);
			for (int j = 0; j < left.size(); ++j)
			{
				for (int k = 0; k < right.size(); ++k)
				{
					TreeNode* node = new TreeNode(i);
					node->left = left[j];
					node->right = right[k];
					vTree.push_back(node);
				}
			}
		}
		return vTree;
	}
};
#endif