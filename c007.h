#ifndef C_CTREE_H
#define C_CTREE_H
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<sstream>
using namespace std;
/*
* 二叉树的序列化和反序列化
*
* 设计一个算法，并编写代码来序列化和反序列化二叉树。将树写入一个文件被称为“序列化”，读取文件后重建同样的二叉树被称为“反序列化”。
* 如何反序列化或序列化二叉树是没有限制的，你只需要确保可以将二叉树序列化为一个字符串，并且可以将字符串反序列化为原来的树结构。
* 注意事项
* There is no limit of how you deserialize or serialize a binary tree, LintCode will take your output of serialize as the input of deserialize, it won't check the result of serialize.
* 样例
* 给出一个测试数据样例， 二叉树{3,9,20,#,#,15,7}，表示如下的树结构：
*    3
*   / \
*  9  20
*    /  \
*   15   7
* 我们的数据是进行BFS遍历得到的。当你测试结果wrong answer时，你可以作为输入调试你的代码。
* 你可以采用其他的方法进行序列化和反序列化。
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
class Solution {
public:
	/**
	* This method will be invoked first, you should design your own algorithm
	* to serialize a binary tree which denote by a root node to a string which
	* can be easily deserialized by your own "deserialize" method later.
	*/
	string serialize(TreeNode * root) {
		// write your code here
		if (root == NULL)
			return "{}";
		string str;
		vector<string> vec;
		queue<TreeNode*> que;
		que.push(root);
		//相当于层次遍历二叉树
		while (!que.empty())
		{
			TreeNode *temp = que.front();
			que.pop();
			if (temp != NULL)
			{
				vec.push_back(to_string(temp->val));
				que.push(temp->left);
				que.push(temp->right);
			}
			else
				vec.push_back("#");
		}
		while (!vec.empty() && vec[vec.size() - 1] == "#")
			vec.pop_back();
		for (auto c : vec)
			str += (c + ",");
		str.pop_back();
		str = "{" + str + "}";
		return str;
	}

	/**
	* This method will be invoked second, the argument data is what exactly
	* you serialized at method "serialize", that means the data is not given by
	* system, it's given by your own serialize method. So the format of data is
	* designed by yourself, and deserialize it here as you serialize it in
	* "serialize" method.
	*/
	TreeNode * deserialize(string &data) {
		// write your code here
		if (data == "{}")
			return NULL;
		vector<string> vec = Split(data);
		TreeNode *root = new TreeNode(atoi(vec[0].c_str()));
		queue<TreeNode*> que;
		que.push(root);
		bool isLchild = true;
		for (int i = 1; i < vec.size(); ++i)
		{
			if (vec[i] != "#")
			{
				TreeNode *node = new TreeNode(atoi(vec[i].c_str()));
				if (isLchild)
					que.front()->left = node;
				else
					que.front()->right = node;
				que.push(node);
			}
			if (!isLchild)
				que.pop();
			isLchild = !isLchild;
		}
		return root;
	}
	//将字符串中的数据提取到vector中
	vector<string> Split(string &data)
	{
		vector<string> res;
		string str;
		for (int i = 1; i < data.size() - 1; ++i)
		{
			if (data[i] != ',')
				str += data[i];
			else
			{
				res.push_back(str);
				str.clear();
			}
			if (i == data.size() - 2)
				res.push_back(str);
		}
		return res;
	}
};
#endif