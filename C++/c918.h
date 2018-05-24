#ifndef C918_H
#define C918_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 三数之和
*
* 描述
* 给定一个n个整数的数组和一个目标整数target，找到下标为i、j、k的数组元素0 <= i < j < k < n，满足条件nums[i] + nums[j] + nums[k] < target.
* 样例
* 给定 nums = [-2,0,1,3], target = 2, 返回 2.
* 解释:
* 因为有两种三个元素之和，它们的和小于2:
* [-2, 0, 1]
* [-2, 0, 3]
* 挑战
* Could you solve it in O(n2) runtime?
*/
class Solution {
public:
	/**
	* @param nums:  an array of n integers
	* @param target: a target
	* @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
	*/
	int threeSumSmaller(vector<int> &nums, int target) {
		// Write your code here
		if (nums.empty()||nums.size()<3)
			return 0;
		int len = nums.size();
		sort(nums.begin(), nums.end());
		int cnt = 0;
		for (int i = 0; i < len - 2; ++i)
		{
			int j = i + 1;
			int k = len - 1;
			while (j<k)
			{
				if (nums[i] + nums[j] + nums[k] < target)
				{
					cnt += k - j;
					++j;
				}
				else
					--k;
			}
		}
		return cnt;
	}
};
#endif