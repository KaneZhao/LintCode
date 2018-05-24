#ifndef C66_H
#define C66_H
#include<vector>
#include<iostream>
#include<stack>
using namespace std;
/*
* 二叉树的中序遍历
*
* 给出一棵二叉树，返回其节点值的中序遍历。
*
* 样例
* 给出一棵二叉树 {1,#,2,3},
* 1
*  \
*   2
*  /
* 3
* 返回 [1,3,2].
* 挑战
* 你能使用非递归实现么？
*/
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};
//递归
class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		// write your code here
		//TreeNode *node = root;
		vector<TreeNode*> tVal;
		vector<int> res;
		while (root != NULL || tVal.size() != 0)
		{
			
			
				while (root != NULL){
					tVal.push_back(root);
					root = root->left;
				}
				root = tVal.back();
				tVal.pop_back();
				res.push_back(root->val);
				root = root->right;
			
		}
		return res;
	}
};
//非递归
class Solution2 {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		// write your code here
		vector<int> res;
		stack<TreeNode*> stack;
		TreeNode *node = root;
		//访问结点node,并将结点入栈
		//若其左孩子为空,取栈顶元素并出栈,将栈顶元素的右孩子作为当前结点
		//若其左孩子不为空,将其左孩子作为当前结点
		//直至node==NULL且栈为空
		while (node || !stack.empty())
		{
			while (node)
			{
				stack.push(node);
				node = node->left;
			}
			if (!stack.empty())
			{
				node = stack.top();
				stack.pop();
				res.push_back(node->val);
				node = node->right;
			}
		}
		return res;
	}
};
#endif