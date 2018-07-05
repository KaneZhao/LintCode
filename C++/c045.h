#ifndef C45_H
#define C45_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 最大子数组差
*
* 描述
* 给定一个整数数组，找出两个不重叠的子数组A和B，使两个子数组和的差的绝对值|SUM(A) - SUM(B)|最大。
* 返回这个最大的差值。
* 子数组最少包含一个数
* 样例
* 给出数组[1, 2, -3, 1]，返回 6
* 挑战
* 时间复杂度为O(n)，空间复杂度为O(n)
*/
class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: An integer indicate the value of maximum difference between two substrings
	*/
	int maxDiffSubArrays(vector<int> &nums) {
		// write your code here
		if (nums.empty())
			return 0;
		int len = nums.size();
		//ForMax[i]表示从nums[0]到nums[i]的子数组和的最大值
		//ForMin[i]表示从nums[0]到nums[i]的子数组和的最小值
		//RevMax[i]表示从nums[i]到nums[len-1]的子数组和的最大值
		//RevMin[i]表示从nums[i]到nums[len-1]的子数组和的最小值
		vector<int> ForMax(len), ForMin(len), RevMax(len), RevMin(len);
		ForMax[0] = nums[0];
		ForMin[0] = nums[0];
		RevMax[len - 1] = nums[len - 1];
		RevMin[len - 1] = nums[len - 1];
		int res = INT_MIN;
		int Max = nums[0], Min = nums[0];
		int curMax = nums[0], curMin = nums[0];
		for (int i = 1; i < len; ++i)
		{
			if (curMax>0)
				curMax += nums[i];
			else
				curMax = nums[i];
			if (curMax > Max)
				Max = curMax;
			ForMax[i] = Max;
			if (curMin < 0)
				curMin += nums[i];
			else
				curMin = nums[i];
			if (curMin < Min)
				Min = curMin;
			ForMin[i] = Min;
		}
		Max = nums.back(), Min = nums.back();
		curMax = Max, curMin = Min;
		for (int i = len - 2; i >= 0; --i)
		{
			if (curMax>0)
				curMax += nums[i];
			else
				curMax = nums[i];
			if (curMax > Max)
				Max = curMax;
			RevMax[i] = Max;
			if (curMin < 0)
				curMin += nums[i];
			else
				curMin = nums[i];
			if (curMin < Min)
				Min = curMin;
			RevMin[i] = Min;
		}
		//计算ForMax[i] - RevMin[i + 1]
		for (int i = 0; i < len - 1; ++i)
		{
			res = max(res, ForMax[i] - RevMin[i + 1]);
		}
		//计算RevMax[i] - ForMin[i - 1]
		for (int i = len - 1; i > 0; --i)
		{
			res = max(res, RevMax[i] - ForMin[i - 1]);
		}
		return res;
	}
};

#endif