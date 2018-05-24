#ifndef C205_H
#define C205_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ������С��
*  
* ����һ���������飨�±��� 0 �� n-1������ n ��ʾ����Ĺ�ģ�����Լ�һ����ѯ�б�ÿһ����ѯ�б����������� [start, end]�� ����ÿ����ѯ������������д��±� start �� end ֮���������Сֵ���������ڽ���б��С�
* ע������
* ��������ǰ��������������������� �߶����Ĺ��죬 �߶����Ĳ�ѯ �� �߶������޸ġ�
* ����
* �������� [1,2,7,8,5]�� ��ѯ [(1,2),(0,4),(2,4)]������ [2,1,5]
* ��ս
* ÿ�β�ѯ��O(logN)��ʱ�������
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
	//��������A�����߶���
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
	//��ѯ����[start,end]�ϵ���Сֵ
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