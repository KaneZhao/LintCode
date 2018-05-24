#ifndef C190_H
#define C190_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 下一个排列
*
* 描述
* 给定一个若干整数的排列，给出按正数大小进行字典序从小到大排序后的下一个排列。
* 如果没有下一个排列，则输出字典序最小的序列。
* 样例
* 左边是原始排列，右边是对应的下一个排列。
* 1,2,3 → 1,3,2
* 3,2,1 → 1,2,3
* 1,1,5 → 1,5,1
* 挑战
* 不允许使用额外的空间。
*/
class Solution {
public:
	/**
	* @param nums: a vector of integers
	* @return: return nothing (void), do not return anything, modify nums in-place instead
	*/
	void nextPermutation(vector<int> &nums) {
		// write your code here
		if (nums.empty() || nums.size() == 1)
			return;
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
			return;
		}
		for (int i = len - 1; i >= 0; --i)
		{
			if (nums[i] > nums[pos])
			{
				swap(nums[i], nums[pos]);
				break;
			}
		}
		reverse(nums.begin() + pos + 1, nums.end());
	}
};
#endif