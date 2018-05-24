#ifndef C707_H
#define C707_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
	/*
	* @param edges: a directed graph where each edge is represented by a tuple
	* @return: the number of edges
	*/
	int balanceGraph(vector<vector<int>> &edges) {
		// Write your code here
		if (edges.empty())
			return 0;
		map<int, int> m;
		for (auto c : edges)
		{
			m[c[0]] -= c[2];
			m[c[1]] += c[2];
		}
		vector<int> res;
		for (auto t : m)
		{
			if (t.second != 0)
				res.push_back(t.second);
		}
		return helper(res, 0, 0);
	}
	int helper(vector<int> &res, int start, int cnt)
	{
		int num = INT_MAX;
		int len = res.size();
		while (start < len&&res[start] == 0)
			start++;
		for (int i = start + 1; i < len; ++i)
		{
			if ((res[start]>0 && res[i] < 0) || (res[start]<0 && res[i]>0))
			{
				res[i] += res[start];
				num = minVal(num, helper(res, start + 1, cnt + 1));
				res[i] -= res[start];
			}
		}
		return num == INT_MAX ? cnt : num;
	}
	int minVal(int a, int b)
	{
		return a < b ? a : b;
	}
};
#endif