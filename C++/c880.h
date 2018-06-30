#ifndef C880_H
#define C880_H
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
/*
* �ַ������������
*
* ����
* ����Ҫ�Ӱ������ź��������ַ����й���һ����������
* �����������ʾһ����������������һ�����������㣬���������š���������ʾ����ֵ����һ�����Ű���һ��������ͬ�ṹ���Ӷ�������
* ������ڵ���ڣ����������ȿ�ʼ�����������ӽڵ㡣
* �������ַ�����ֻ��'('��')'��'-'��'0' ~ '9'��
* ������ʾΪ���������ǡ�()����
* ����
* ���� s = "4(2(3)(1))(6(5))", ���ر�ʾ�������Ľڵ�:
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
		//sֻ��������,ֱ�ӹ���ڵ�
		if (s.find("(") == string::npos)
		{
			TreeNode *root = new TreeNode(stoi(s));
			return root;
		}
		int beg = s.find("(");//s�е�һ�γ���"("��λ��
		int end = getPos(s, beg);//��beg��"("��Ӧ")"��λ��
		TreeNode *root = new TreeNode(stoi(s.substr(0, beg)));//��ȡ��ʼλ�ñ�ʾ�������������ڵ�
		string l = s.substr(beg + 1, end - beg - 1);//������������ַ���
		root->left = str2tree(l);
		//����������
		if (end == s.size() - 1)
			root->right = NULL;
		else
		{
			string r = s.substr(end + 2, s.size() - end - 3);
			root->right = str2tree(r);
		}
		return root;
	}
	//�ҵ����һ��"("��Ӧ��")"
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