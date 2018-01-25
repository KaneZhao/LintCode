#ifndef C751_H
#define C751_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 约翰的生意
*
* 在一条数轴上，有n个城市，编号从0 ~ n – 1 , 约翰打算在这n个城市做点生意，他对Armani的一批货物感兴趣，每个城市对于这批货物都有一个价格prices[i]。对于城市x,约翰可从城市编号为[x - k, x + k]购买货物，然后卖到城市x,问约翰在每个城市最多能赚到多少钱？
* 注意事项
* prices.length 范围为[2, 100000], k <= 100000。
* 样例
* 给出 prices = [1, 3, 2, 1, 5], k = 2,返回 [0, 2, 1, 0, 4]。
* 解释：
* i = 0，约翰可去的城市有0~2因为1、2号城市的价格比0号城市的价格高，所以赚不了钱，即 ans[0] = 0。
* i = 1，可去的城市有0~3，可以从0号或者3号城市购买货物赚取的差价最大，即ans[1] = 2。
* i = 2，可去的城市有0~4，显然从3号城市购买货物赚取的差价最大，即ans[2] = 1。
* i = 3，可去的城市有1~4，没有其他城市的价格比3号城市价格低，所以赚不了钱，ans[3] = 0。
* i = 4，可去的城市有2~4，从3号城市购买货物赚取的差价最大，即ans[4] = 4。
* 给出 prices = [1, 1, 1, 1, 1], k = 1, 返回 [0, 0, 0, 0, 0]。
* 解释：
*所有城市价格都一样，所以不能赚到钱，即所有的ans都为0。
*/
class SegmentNode{
public:
	int start, end, min;
	SegmentNode *left, *right;
	SegmentNode(int start, int end, int min){
		this->start = start;
		this->end = end;
		this->min;
		this->left = this->right = NULL;
	}
};
class Solution {
public:
	/**
	* @param A: The prices [i]
	* @param k:
	* @return: The ans array
	*/
	vector<int> business(vector<int> &A, int k) {
		// Write your code here
		int len = A.size();
		vector<int> res(len, 0);
		SegmentNode *root = build(A, 0, len - 1);
		for (int i = 0; i<len; ++i)
		{
			int start = i - k;
			int end = i + k;
			//修正区间范围
			if (start < 0)
				start = 0;
			if (end >= len)
				end = len - 1;
			res[i] = A[i]-query(root, start, end);
		}
		return res;
	}
	//查询线段树在区间[start,end]上的最小值
	int query(SegmentNode *root, int start, int end)
	{
		if (start > end || !root)
			return 0;
		SegmentNode *node = root;
		if (start == node->start&&end == node->end)
			return node->min;
		if (start >= node->right->start)
			return query(node->right, start, end);
		else if (end <= node->left->end)
			return query(node->left, start, end);
		else
		{
			return minVal(query(node->left, start, node->left->end), query(node->right, node->right->start, end));
		}
	}
	//构建线段树,节点包含区间内的最小值
	SegmentNode *build(vector<int> &A, int start, int end)
	{
		if (start > end)
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
	int minVal(int a, int b)
	{
		return a < b ? a : b;
	}
};
#endif