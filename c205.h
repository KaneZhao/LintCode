#ifndef C205_H
#define C205_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 区间最小数
*  
* 给定一个整数数组（下标由 0 到 n-1，其中 n 表示数组的规模），以及一个查询列表。每一个查询列表有两个整数 [start, end]。 对于每个查询，计算出数组中从下标 start 到 end 之间的数的最小值，并返回在结果列表中。
* 注意事项
* 在做此题前，建议先完成以下三道题 线段树的构造， 线段树的查询 及 线段树的修改。
* 样例
* 对于数组 [1,2,7,8,5]， 查询 [(1,2),(0,4),(2,4)]，返回 [2,1,5]
* 挑战
* 每次查询在O(logN)的时间内完成
*/
class Interval{
public:
	int start, end;
	Interval(int start, int end)
	{
		this->start = start;
		this->end = end;
	}
};
class SegmentNode{
public:
	int start, end, min;
	SegmentNode *left, *right; 
	SegmentNode(int start, int end, int min){
		this->start = start;
		this->end = end;
		this->min = min;
		this->left = this->right = NULL;
	}
};
class Solution {
public:
	/*
	* @param A: An integer array
	* @param queries: An query list
	* @return: The result list
	*/
	vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
		// write your code here
		vector<int> res;
		if (A.empty() || queries.empty())
			return res;
		int len = A.size();
		SegmentNode *root = build(A, 0, len - 1);
		for (auto c : queries)
		{
			res.push_back(query(root, c.start, c.end));
		}
		return res;
	}
	//根据数组A构建线段树
	SegmentNode *build(vector<int> &A, int start, int end)
	{
		if (A.empty() || start > end)
			return NULL;
		SegmentNode *node = new SegmentNode(start, end, INT_MAX);
		if (start == end)
			node->min = A[start];
		else
		{
			node->left = build(A, start, (start + end) / 2);
			node->right = build(A, (start + end) / 2 + 1, end);
			node->min = minVal(node->left->min, node->right->min);
		}
		return node;
	}
	//查询区间[start,end]上的最小值
	int query(SegmentNode *root, int start,int end)
	{
		if (start > end || !root)
			return 0;
		SegmentNode *node = root;
		if (start == node->start&&end==node->end)
			return node->min;
		if (start >= node->right->start)
			return query(root->right, start, end);
		else if (end <= node->left->end)
			return query(root->left, start, end);
		else
		{
			return minVal(query(root->left, start, root->left->end), query(root->right, root->right->start, end));
		}
	}
	int minVal(int a, int b)
	{
		return a < b ? a : b;
	}
};
#endif