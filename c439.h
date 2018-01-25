#ifndef C439_H
#define C439_H
#include<iostream>
#include<vector>
using namespace std;
class SegmentTreeNode{
public:
	int start, end, max;
	SegmentTreeNode *left, *right;
	SegmentTreeNode(int start, int end, int max)
	{
		this->start = start;
		this->end = end;
		this->max = max;
		this->left = this->right = NULL;
	}
};
class Solution {
public:
	/*
	* @param A: a list of integer
	* @return: The root of Segment Tree
	*/
	SegmentTreeNode * build(vector<int> &A) {
		// write your code here
		if (A.empty())
			return NULL;
		int len = A.size();
		SegmentTreeNode *node = helper(A, 0, len - 1);
		return node;
	}
	//����start��end����ڵ�
	SegmentTreeNode *helper(vector<int> &A, int start, int end)
	{
		SegmentTreeNode *node = new SegmentTreeNode(start, end, 0);
		if (start == end)//��staer=end,����Ҷ�ڵ�
		{
			node->max = A[start];
			return node;
		}
		node->left = helper(A, start, (start + end) / 2);
		node->right = helper(A, (start + end) / 2 + 1, end);
		node->max = maxVal(node->left->max, node->right->max);//�ڵ��maxֵȡ��������maxֵ�нϴ���Ǹ�
		return node;
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif