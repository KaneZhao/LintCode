#ifndef C717_H
#define C717_H
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
	/*
	* @param : as indicated in the description
	* @param : as indicated in the description
	* @return: Return the number of edges on the longest path with same value.
	*/
	int LongestPathWithSameValue(vector<int> &A, vector<int> &E) {
		// write your code here
		if (A.size() == 1)
			return 0;
		vector<vector<int>> nums(A.size()+1);
		for (int i = 0; i < E.size(); i = i + 2)//���������Ľڵ㽨��˫��ӳ��
		{
			nums[E[i]].push_back(E[i + 1]);
			nums[E[i + 1]].push_back(E[i]);
		}
		int res = 0;
		CountPath(nums, A, 0, 1,res);
		return res;
	}
	//�ݹ�,root��ʾ�Ѿ�������ýڵ�,cur��ʾ���ڴ���Ľڵ�,res��ʾ���ֵͬ·���ĳ���
	int CountPath(vector<vector<int>> nums, vector<int> A, int root, int cur,int &res)
	{
		vector<int> tmp;
		for (auto c : nums[cur])
		{
			if (c != root)
			{
				//������ӽ������Һ͵�ǰ�ڵ�ֵ��ͬ,�䳤�ȼ�1
				if (A[c - 1] == A[cur - 1])
					tmp.push_back(CountPath(nums, A, cur, c,res)+1);
				else
					CountPath(nums, A, cur, c,res);
			}
		}
		//Ϊ�˷�ֹtmpΪ��
		tmp.push_back(0);
		tmp.push_back(0);
		sort(tmp.begin(), tmp.end());
		//�����ӽڵ��е���������ֵ������res
		res = maxVal(res, tmp[tmp.size()-1] + tmp[tmp.size() - 2]);
		return tmp.back();//���·����Ҫ���ϸ��ڵ�,��ѡ���ӽڵ���ֵ�����Ǹ�
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif