#ifndef C011_H
#define C011_H
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
* 二叉查找树中搜索区间
*
* 给定两个值 k1 和 k2（k1 < k2）和一个二叉查找树的根节点。找到树中所有值在 k1 到 k2 范围内的节点。即打印所有x(k1 <= x <= k2) 其中 x 是二叉查找树的中的节点值。返回所有升序的节点值。
* 样例
* 如果有 k1 = 10 和 k2 = 22, 你的程序应该返回[12, 20, 22].
*     20
*     / \
*    8   22
*   / \
*  4  12
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
	* @param root: param root: The root of the binary search tree
	* @param k1: An integer
	* @param k2: An integer
	* @return: return: Return all keys that k1<=key<=k2 in ascending order
	*/
	vector<int> searchRange(TreeNode * root, int k1, int k2) {
		// write your code here
		vector<int> nums;
		vector<int> res;
		if (!root)
			return nums;
		inorder(root, res);
		//寻找满足要求的节点的值
		for (auto c : res)
		{
			if (c >= k1&&c <= k2)
				nums.push_back(c);
		}
		return nums;
	}
	//中序遍历得到节点递增的值
	void inorder(TreeNode *root,vector<int> &res)
	{
		if (!root)
			return;
		inorder(root->left,res);
		res.push_back(root->val);
		inorder(root->right, res);
	}
};
#endif