#ifndef C76_H
#define C76_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 最长上升子序列
* 
* 给定一个整数序列，找到最长上升子序列（LIS），返回LIS的长度。
* 说明
* 最长上升子序列的定义：
* 最长上升子序列问题是在一个无序的给定序列中找到一个尽可能长的由低到高排列的子序列，这种子序列不一定是连续的或者唯一的。
* https://en.wikipedia.org/wiki/Longest_increasing_subsequence
* 样例
* 给出 [5,4,1,2,3]，LIS 是 [1,2,3]，返回 3
* 给出 [4,2,4,5,3,7]，LIS 是 [2,4,5,7]，返回 4
* 挑战
* 要求时间复杂度为O(n^2) 或者 O(nlogn)
*/
class Solution{
public:	
	int longestIncreasingSubsequence(vector<int> nums) {
		// write your code here
		if (nums.empty())
			return 0;
		int len = nums.size();
		vector<int> res(len, 0);//res[i]存放以nums[i]为尾部的最长子序列的长度
		res[0] = 1;
		for (int i = 1; i < len; ++i)
		{
			int tmp = 1;
			for (int j = i - 1; j >= 0; --j) //从后向前寻找比nums[i]小的元素,其长度的最大值
			{
				if (nums[i]>nums[j])
				{
					tmp = maxVal(tmp, res[j] + 1);
				}
			}
			res[i] = tmp;
		}
		int max = 1;
		for (auto c : res) //找出最大长度
		{
			if (c > max)
				max = c;
		}
		return max;
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};

#endif