#ifndef C73_H
#define C73_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 前序遍历和中序遍历树构造二叉树
*
* 根据前序遍历和中序遍历树构造二叉树.
* 注意事项
* 你可以假设树中不存在相同数值的节点
* 样例
* 给出中序遍历：[1,2,3]和前序遍历：[2,1,3]. 返回如下的树:
*   2
*  / \
* 1   3
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
	/**
	*@param preorder : A list of integers that preorder traversal of a tree
	*@param inorder : A list of integers that inorder traversal of a tree
	*@return : Root of a tree
	*/
public:
	typedef vector<int>::iterator iter;
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		// write your code here
		if (preorder.empty())
			return NULL;
		TreeNode *node = helper(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
		return node;
	}
	//递归构造二叉树
	//preorder第一个元素rootval作为根节点,在inorder中寻找rootval得到rootIter,rootIter左边元素位于根节点
	//的左子树,右边元素位于根节点的右子树
	TreeNode *helper(iter pstart, iter pend, iter istart, iter iend)
	{
		if (pstart >= pend)
			return NULL;
		int rootVal = *pstart;
		iter rootIter = find(istart, iend, rootVal);
		TreeNode *res = new TreeNode(rootVal);
		res->left = helper(pstart + 1, pstart + (rootIter - istart) + 1, istart, rootIter);
		res->right = helper(pstart + (rootIter - istart) + 1, pend, rootIter + 1, iend);
		return res;
	}
};
#endif