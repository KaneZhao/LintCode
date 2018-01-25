#ifndef C203_H
#define C203_H
#include<iostream>
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
	* @param index: index.
	* @param value: value
	* @return:
	*/
	void modify(SegmentTreeNode * root, int index, int value) {
		// write your code here
		if (!root)
			return;
		SegmentTreeNode *node = root;
		//寻找叶节点,若其与index相等,改变节点的值
		if (node->start == node->end)
		{
			if (node->start==index)
			    node->max = value;
		}
		else
		{
			//自下而上改变节点的值
			modify(node->left, index, value);
			modify(node->right, index, value);
			node->max = maxVal(node->left->max, node->right->max);
		}
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif