#ifndef C247_H
#define C247_H
#include<iostream>
using namespace std;
/*
* 线段树查询 II
* 
* 对于一个数组，我们可以对其建立一棵 线段树, 每个结点存储一个额外的值 count 来代表这个结点所指代的数组区间内的元素个数. (数组中并不一定每个位置上都有元素)
* 实现一个 query 的方法，该方法接受三个参数 root, start 和 end, 分别代表线段树的根节点和需要查询的区间，找到数组中在区间[start, end]内的元素个数。
* 注意事项
* It is much easier to understand this problem if you finished Segment Tree Buildand Segment Tree Query first.
* 您在真实的面试中是否遇到过这个题？ Yes
* 样例
* 对于数组 [0, 空，2, 3], 对应的线段树为：
*                  [0, 3, count=3]
*                 /             \
*      [0,1,count=1]             [2,3,count=2]
*      /         \               /            \
* [0,0,count=1] [1,1,count=0] [2,2,count=1], [3,3,count=1]
* query(1, 1), return 0
* query(1, 2), return 1
* query(2, 3), return 2
* query(0, 2), return 2
*/
class SegmentTreeNode{
public:
	int start, end, count;
	SegmentTreeNode *left, *right;
	SegmentTreeNode(int start, int end, int count){
		this->start = start;
		this->end = end;
		this->count = count;
		this->left = this->right = NULL;
	}
};
class Solution {
public:
	/*
	* @param root: The root of segment tree.
	* @param start: start value.
	* @param end: end value.
	* @return: The count number in the interval [start, end]
	*/
	int query(SegmentTreeNode *root, int start, int end) {
		// write your code here
		if (start > end || !root)
			return 0;
		//当查询范围超出当前节点范围时,规范其范围
		if (start < root->start)
			return query(root, root->start, end);
		if (end>root->end)
			return query(root, start, root->end);
		SegmentTreeNode *node = root;
		//若查询范围小于当前节点范围,且当前节点count为0,直接返回0
		if (start >= node->start&&end <= node->end&&node->count == 0)
			return 0;
		//若查询范围等于当前节点范围,返回当前节点的count值
		if (start == node->start&&end == node->end)
			return node->count;
		//根据查询范围改变搜索节点
		if (start >= node->right->start)
			return query(node->right, start, end);
		else if (end <= node->left->end)
			return query(node->left, start, end);
		else
		{
			int l = query(node->left, start, node->left->end);
			int r = query(node->right, node->right->start, end);
			return l + r;
		}
	}
};
#endif