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
		for (int i = 0; i < E.size(); i = i + 2)//对于相连的节点建立双向映射
		{
			nums[E[i]].push_back(E[i + 1]);
			nums[E[i + 1]].push_back(E[i]);
		}
		int res = 0;
		CountPath(nums, A, 0, 1,res);
		return res;
	}
	//递归,root表示已经处理过得节点,cur表示正在处理的节点,res表示最长向同值路径的长度
	int CountPath(vector<vector<int>> nums, vector<int> A, int root, int cur,int &res)
	{
		vector<int> tmp;
		for (auto c : nums[cur])
		{
			if (c != root)
			{
				//如果其子结点存在且和当前节点值相同,其长度加1
				if (A[c - 1] == A[cur - 1])
					tmp.push_back(CountPath(nums, A, cur, c,res)+1);
				else
					CountPath(nums, A, cur, c,res);
			}
		}
		//为了防止tmp为空
		tmp.push_back(0);
		tmp.push_back(0);
		sort(tmp.begin(), tmp.end());
		//利用子节点中的最大的两个值来更新res
		res = maxVal(res, tmp[tmp.size()-1] + tmp[tmp.size() - 2]);
		return tmp.back();//如果路径还要加上父节点,则选择子节点中值最大的那个
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif