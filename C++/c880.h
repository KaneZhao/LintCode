#ifndef C880_H
#define C880_H
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
/*
* 字符串构造二叉树
*
* 描述
* 您需要从包含括号和整数的字符串中构造一个二叉树。
* 整个的输入表示一个二叉树。它包含一个整数，或零，或两对括号。该整数表示根的值，而一对括号包含一个具有相同结构的子二叉树。
* 如果父节点存在，您总是首先开始构造它的左子节点。
* 在输入字符串中只有'('，')'，'-'和'0' ~ '9'。
* 空树表示为“”而不是“()”。
* 样例
* 给定 s = "4(2(3)(1))(6(5))", 返回表示下面树的节点:
*       4
*     /   \
*    2     6
*   / \   /
*  3   1 5
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
	/**
	* @param s: a string
	* @return: a root of this tree
	*/
	TreeNode * str2tree(string &s) {
		// write your code here
		if (s.empty())
			return NULL;
		//s只包含数字,直接构造节点
		if (s.find("(") == string::npos)
		{
			TreeNode *root = new TreeNode(stoi(s));
			return root;
		}
		int beg = s.find("(");//s中第一次出现"("的位置
		int end = getPos(s, beg);//与beg的"("对应")"的位置
		TreeNode *root = new TreeNode(stoi(s.substr(0, beg)));//提取开始位置表示的数字来构建节点
		string l = s.substr(beg + 1, end - beg - 1);//左子树代表的字符串
		root->left = str2tree(l);
		//构建右子树
		if (end == s.size() - 1)
			root->right = NULL;
		else
		{
			string r = s.substr(end + 2, s.size() - end - 3);
			root->right = str2tree(r);
		}
		return root;
	}
	//找到与第一个"("对应的")"
	int getPos(string &s, int beg)
	{
		stack<int> stack;
		stack.push(s[beg]);
		int i = beg + 1;
		while (!stack.empty()&&i<s.size())
		{
			if (s[i] == '(')
				stack.push(s[i]);
			else if (s[i] == ')')
				stack.pop(); 
			++i;
		}
		return i - 1;
	}
};
#endif