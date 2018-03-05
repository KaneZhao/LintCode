#ifndef C_CTREE_H
#define C_CTREE_H
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<sstream>
using namespace std;
/*
* �����������л��ͷ����л�
*
* ���һ���㷨������д���������л��ͷ����л�������������д��һ���ļ�����Ϊ�����л�������ȡ�ļ����ؽ�ͬ���Ķ���������Ϊ�������л�����
* ��η����л������л���������û�����Ƶģ���ֻ��Ҫȷ�����Խ����������л�Ϊһ���ַ��������ҿ��Խ��ַ��������л�Ϊԭ�������ṹ��
* ע������
* There is no limit of how you deserialize or serialize a binary tree, LintCode will take your output of serialize as the input of deserialize, it won't check the result of serialize.
* ����
* ����һ���������������� ������{3,9,20,#,#,15,7}����ʾ���µ����ṹ��
*    3
*   / \
*  9  20
*    /  \
*   15   7
* ���ǵ������ǽ���BFS�����õ��ġ�������Խ��wrong answerʱ���������Ϊ���������Ĵ��롣
* ����Բ��������ķ����������л��ͷ����л���
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
		//�൱�ڲ�α���������
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
	//���ַ����е�������ȡ��vector��
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