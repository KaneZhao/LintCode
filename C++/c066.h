#ifndef C66_H
#define C66_H
#include<vector>
#include<iostream>
#include<stack>
using namespace std;
/*
* 二叉树的前序遍历
*
* 给出一棵二叉树，返回其节点值的前序遍历。
* 
* 样例
* 给出一棵二叉树 {1,#,2,3},
* 1
*  \
*   2
*  /
* 3
* 返回 [1,2,3].
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
	vector<int> preorderTraversal(TreeNode *root) {
		// write your code here
		preOrder(root);
		return val;		
	}
	void preOrder(TreeNode *node)
	{
		if (node != NULL)
		{
			val.push_back(node->val);
			preOrder(node->left);
			preOrder(node->right);
		}
	}
private:
	vector<int> val;
};
//非递归
class Solution2 {
public:
	/*
	* @param root: A Tree
	* @return: Preorder in ArrayList which contains node values.
	*/
	vector<int> preorderTraversal(TreeNode * root) {
		// write your code here
		vector<int> res;
		stack<TreeNode*> stack;
		TreeNode *node = root;
		//访问结点node,将node入栈,并存入数组
		//若node的左孩子为空,则取栈顶并出栈,将栈顶结点的右孩子设为当前结点
		//若node的左孩子不为空,则将左孩子作为当前结点
		//直至node==NULL且栈为空
		while (node || !stack.empty())
		{
			while (node)
			{
				stack.push(node);
				res.push_back(node->val);
				node = node->left;
			}
			if (!stack.empty())
			{
				node = stack.top();
				stack.pop();
				node = node->right;
			}
		}
		return res;
	}
};
#endif