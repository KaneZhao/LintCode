#ifndef C201_H
#define C201_H
#include<iostream>
using namespace std;
/*
* �߶����Ĺ���
*
* �߶�����һ�ö�����������ÿ���ڵ�������������������start��end���ڱ�ʾ�ýڵ�����������䡣start��end�������������������µķ�ʽ��ֵ:
* ���ڵ�� start �� end �� build ������������
* ���ڽڵ� A ������ӣ��� start=A.left, end=(A.left + A.right) / 2��
* ���ڽڵ� A ���Ҷ��ӣ��� start=(A.left + A.right) / 2 + 1, end=A.right��
* ��� start ���� end, ��ô�ýڵ���Ҷ�ӽڵ㣬���������Ҷ��ӡ�
* ʵ��һ�� build ���������� start �� end ��Ϊ����, Ȼ����һ���������� [start, end] ���߶�������������߶����ĸ���
* ˵��
* �߶���(�ֳ�������), ��һ�ָ߼����ݽṹ��������֧��������һЩ����:
* ���Ҹ����ĵ����������Щ������
* ���Ҹ����������������Щ��
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
		if (start == end)//start=end,ֱ�ӷ��ؽڵ�
			return node;
		node->left = build(start, (start + end) / 2);
		node->right = build((start + end) / 2 + 1, end);
		return node;
	}
};
#endif