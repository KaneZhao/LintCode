#ifndef C448_H
#define C448_H
#include<iostream>
using namespace std;
/*
* 二叉查找树的中序后继
*
* 描述
* 给定一个二叉查找树(什么是二叉查找树)，以及一个节点，求该节点在中序遍历的后继，如果没有返回null
* 保证p是给定二叉树中的一个节点。(您可以直接通过内存地址找到p)
* 样例
* 给出 tree = [2,1] node = 1:
*   2
*  /
* 1
* 返回 node 2.
* 给出 tree = [2,1,3] node = 2:
*   2
*  / \
* 1   3
* 返回 node 3.
* 挑战
* O(h)，其中h是BST的高度。
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
	* @param root: The root of the BST.
	* @param p: You need find the successor node of p.
	* @return: Successor of p.
	*/
	TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
		// write your code here
		if (!root || !p)
			return NULL;
		//若p右子树不为空,如果其右子树存在左子树,则其后继为右子树深度最深的左子树
		//如果右子树不存在左子树,直接返回p的右子树
		if (p->right)
		{
			if (p->right->left)
			{
				TreeNode *temp = p->right->left;
				while (temp->left)
				{
					temp = temp->left;
				}
				return temp;
			}
			else
				return p->right;
		}
		else
		{
			if (p->val > root->val)
				return NULL;
			findNext(root, p);
			return temp;
		}
	}
	//在p没有右子树的情况下找到root中第一个值大于p的节点
	void findNext(TreeNode *root, TreeNode* p)
	{
		if (root->val > p->val)
		{
			temp = root;
			findNext(root->left, p);
		}
		else if (root->val < p->val)
		{
			findNext(root->right, p);
		}
		else
			return;
	}
	TreeNode *temp = NULL;
};
#endif