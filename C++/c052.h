#ifndef C052_H
#define C052_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 下一个排列
*
* 描述
* 给定一个整数数组来表示排列，找出其之后的一个排列。
* 排列中可能包含重复的整数
* 样例
* 给出排列[1,3,2,3]，其下一个排列是[1,3,3,2]
* 给出排列[4,3,2,1]，其下一个排列是[1,2,3,4]
*/
class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: A list of integers
	*/
	vector<int> nextPermutation(vector<int> &nums) {
		// write your code here
		if (nums.empty() || nums.size() == 1)
			return nums;
		int pos = -1;
		int len = nums.size();
		for (int i = len - 2; i >= 0; --i)
		{
			if (nums[i] < nums[i + 1])
			{
				pos = i;
				break;
			}
		}
		if (pos == -1)
		{
			reverse(nums.begin(), nums.end());
			return nums;
		}
		for (int i = len - 1; i >= 0; --i)
		{
			if (nums[i]>nums[pos])
			{
				swap(nums[i], nums[pos]);
				break;
			}
		}
		reverse(nums.begin() + pos + 1, nums.end());
		return nums;
	}
};
#endif