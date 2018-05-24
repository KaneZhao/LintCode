#ifndef C51_H
#define C51_H
#include<vector>
#include<iostream>
using namespace std;
/*
* 上一个排列
*
* 给定一个整数数组来表示排列，找出其上一个排列。
* 排列中可能包含重复的整数
* 样例
* 给出排列[1,3,2,3]，其上一个排列是[1,2,3,3]
* 给出排列[1,2,3,4]，其上一个排列是[4,3,2,1]
*/
class Solution {
public:
	vector<int> previousPermuation(vector<int> &nums) {
		// write your code here
		if (nums.empty() || nums.size() == 1)
			return nums;
		int len = nums.size();
		int pos = -1;
		for (int i = len - 2; i >= 0; --i)
		{
			if (nums[i] > nums[i + 1])
			{
				pos = i;
				break;
			}
		}
		if (pos == -1)
		{
			reverse(nums.begin(), nums.end());
		}
		else
		{
			for (int i = len - 1; i >= 0; --i)
			{
				if (nums[i] < nums[pos])
				{
					swap(nums[i], nums[pos]);
					reverse(nums.begin() + pos + 1, nums.end());
					break;
				}
			}
		}
		return nums;
	}
};
#endif