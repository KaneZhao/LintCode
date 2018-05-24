#ifndef C202_H
#define C202_H
#include<iostream>
#include<vector>
using namespace std;
class SegmentTreeNode{
public:
	int start, end, max;
	SegmentTreeNode *left, *right;
	SegmentTreeNode(int start, int end, int max){
		this->start = start;
		this->end = end;
		this->max = max;
		this->left = this->right = NULL;
	}
};
class Solution {
public:
	/*
	* @param root: The root of segment tree.
	* @param start: start value.
	* @param end: end value.
	* @return: The maximum number in the interval [start, end]
	*/
	int query(SegmentTreeNode * root, int start, int end) {
		// write your code here
		if (start > end || start<root->start || end>root->end)
			return 0;
		SegmentTreeNode *node = root;
		if (start == node->start&&end == node->end)//���start,end�ֱ���ڴ�ʱ�ڵ��start��node,�򷵻ؽڵ��maxֵ
			return node->max;
		if (end <= (node->start + node->end) / 2)//endС�ڽڵ���������endֵ,���ڽڵ�����������в�ѯ
			return query(node->left, start, end);
		else if (start >= (node->start + node->end) / 2 + 1)//start���ڽڵ���������startֵ,���ڽڵ�����������в�ѯ
			return query(node->right, start, end);
		else
			return maxVal(query(node->left, start, node->left->end), query(node->right, node->right->start, end));
		//[start,end]��Խ��������,��ȡ����������������ֵ
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif