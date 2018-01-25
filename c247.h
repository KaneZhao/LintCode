#ifndef C247_H
#define C247_H
#include<iostream>
using namespace std;
/*
* �߶�����ѯ II
* 
* ����һ�����飬���ǿ��Զ��佨��һ�� �߶���, ÿ�����洢һ�������ֵ count ��������������ָ�������������ڵ�Ԫ�ظ���. (�����в���һ��ÿ��λ���϶���Ԫ��)
* ʵ��һ�� query �ķ������÷��������������� root, start �� end, �ֱ�����߶����ĸ��ڵ����Ҫ��ѯ�����䣬�ҵ�������������[start, end]�ڵ�Ԫ�ظ�����
* ע������
* It is much easier to understand this problem if you finished Segment Tree Buildand Segment Tree Query first.
* ������ʵ���������Ƿ�����������⣿ Yes
* ����
* �������� [0, �գ�2, 3], ��Ӧ���߶���Ϊ��
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
		//����ѯ��Χ������ǰ�ڵ㷶Χʱ,�淶�䷶Χ
		if (start < root->start)
			return query(root, root->start, end);
		if (end>root->end)
			return query(root, start, root->end);
		SegmentTreeNode *node = root;
		//����ѯ��ΧС�ڵ�ǰ�ڵ㷶Χ,�ҵ�ǰ�ڵ�countΪ0,ֱ�ӷ���0
		if (start >= node->start&&end <= node->end&&node->count == 0)
			return 0;
		//����ѯ��Χ���ڵ�ǰ�ڵ㷶Χ,���ص�ǰ�ڵ��countֵ
		if (start == node->start&&end == node->end)
			return node->count;
		//���ݲ�ѯ��Χ�ı������ڵ�
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