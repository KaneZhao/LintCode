#ifndef C201_H
#define C201_H
#include<iostream>
using namespace std;
/*
* 线段树的构造
*
* 线段树是一棵二叉树，他的每个节点包含了两个额外的属性start和end用于表示该节点所代表的区间。start和end都是整数，并按照如下的方式赋值:
* 根节点的 start 和 end 由 build 方法所给出。
* 对于节点 A 的左儿子，有 start=A.left, end=(A.left + A.right) / 2。
* 对于节点 A 的右儿子，有 start=(A.left + A.right) / 2 + 1, end=A.right。
* 如果 start 等于 end, 那么该节点是叶子节点，不再有左右儿子。
* 实现一个 build 方法，接受 start 和 end 作为参数, 然后构造一个代表区间 [start, end] 的线段树，返回这棵线段树的根。
* 说明
* 线段树(又称区间树), 是一种高级数据结构，他可以支持这样的一些操作:
* 查找给定的点包含在了哪些区间内
* 查找给定的区间包含了哪些点
*/
class SegmentTreeNode{
public:
	int start, end;
	SegmentTreeNode *left, *right;
	SegmentTreeNode(int start, int end){
		this->start = start;
		this->end = end;
		this->left = this->right = NULL;
	}
};
class Solution {
public:
	/*
	* @param start: start value.
	* @param end: end value.
	* @return: The root of Segment Tree.
	*/
	SegmentTreeNode * build(int start, int end) {
		// write your code here
		if (start > end)
			return NULL;
		SegmentTreeNode *node = new SegmentTreeNode(start, end);
		if (start == end)//start=end,直接返回节点
			return node;
		node->left = build(start, (start + end) / 2);
		node->right = build((start + end) / 2 + 1, end);
		return node;
	}
};
#endif