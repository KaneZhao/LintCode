#ifndef C751_H
#define C751_H
#include<iostream>
#include<vector>
using namespace std;
/*
* Լ��������
*
* ��һ�������ϣ���n�����У���Ŵ�0 ~ n �C 1 , Լ����������n�������������⣬����Armani��һ���������Ȥ��ÿ�����ж����������ﶼ��һ���۸�prices[i]�����ڳ���x,Լ���ɴӳ��б��Ϊ[x - k, x + k]������Ȼ����������x,��Լ����ÿ�����������׬������Ǯ��
* ע������
* prices.length ��ΧΪ[2, 100000], k <= 100000��
* ����
* ���� prices = [1, 3, 2, 1, 5], k = 2,���� [0, 2, 1, 0, 4]��
* ���ͣ�
* i = 0��Լ����ȥ�ĳ�����0~2��Ϊ1��2�ų��еļ۸��0�ų��еļ۸�ߣ�����׬����Ǯ���� ans[0] = 0��
* i = 1����ȥ�ĳ�����0~3�����Դ�0�Ż���3�ų��й������׬ȡ�Ĳ����󣬼�ans[1] = 2��
* i = 2����ȥ�ĳ�����0~4����Ȼ��3�ų��й������׬ȡ�Ĳ����󣬼�ans[2] = 1��
* i = 3����ȥ�ĳ�����1~4��û���������еļ۸��3�ų��м۸�ͣ�����׬����Ǯ��ans[3] = 0��
* i = 4����ȥ�ĳ�����2~4����3�ų��й������׬ȡ�Ĳ����󣬼�ans[4] = 4��
* ���� prices = [1, 1, 1, 1, 1], k = 1, ���� [0, 0, 0, 0, 0]��
* ���ͣ�
*���г��м۸�һ�������Բ���׬��Ǯ�������е�ans��Ϊ0��
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
			//�������䷶Χ
			if (start < 0)
				start = 0;
			if (end >= len)
				end = len - 1;
			res[i] = A[i]-query(root, start, end);
		}
		return res;
	}
	//��ѯ�߶���������[start,end]�ϵ���Сֵ
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
	//�����߶���,�ڵ���������ڵ���Сֵ
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