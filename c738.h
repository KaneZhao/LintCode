#ifndef C738_H
#define C738_H
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>  
#include <functional>  
using namespace std;
class Solution {
public:
	/**
	* @param str: a string S
	* @return: the number of different non-empty palindromic subsequences in S
	*/
	int countPalindSubseq(string &str) {
		// write your code here
		int len = str.size();
		vector<vector<int>> dic(4, vector<int>());
		vector<vector<int>> nums(len + 1, vector<int>(len + 1, 0));
		for (int i = 0; i < len; ++i)
			dic[str[i] - 'a'].push_back(i);
		return helper(str,dic,nums,0,len);
	}
	int helper(string str, vector<vector<int>> dic, vector<vector<int>> &nums, int start, int end)
	{
		if (start >= end)
			return 0;
		if (nums[start][end]>0)
			return nums[start][end];
		long long res = 0;
		for (int i = 0; i < 4; ++i)
		{
			if (dic[i].empty())
				continue;
			auto it_start = lower_bound(dic[i].begin(), dic[i].end(), start);
			auto it_end = lower_bound(dic[i].begin(), dic[i].end(), end) - 1;
			if (it_start == dic[i].end() || *it_start >= end)
				continue;
			res++;
			if (it_start != it_end)
				++res;
			res += helper(str, dic, nums, *it_start + 1, *it_end);
		}
		nums[start][end] = res % (int)(1e9 + 7);
		return nums[start][end];
	}
};
#endif