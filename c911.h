#ifndef C911_H
#define C911_H
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
* 最大子数组之和为k
*
* 给一个数组nums和目标值k，找到数组中最长的子数组，使其中的元素和为k。如果没有，则返回0。
* 注意事项
* 数组之和保证在32位有符号整型数的范围内
* 样例
* 给出数组 nums = [1, -1, 5, -2, 3]，k = 3，返回4
* 解析：
* 子数组[1, -1, 5, -2]的和为3，且长度最大
* 给出数组nums = [-2, -1, 2, 1]， k = 1，返回2
* 解析：
* 子数组[-1, 2]的和为1，且长度最大
* 挑战
* 能否用O(n)的时间复杂度完成？
*/
class Solution {
public:
	/**
	* @param nums: an array
	* @param k: a target value
	* @return: the maximum length of a subarray that sums to k
	*/
	int maxSubArrayLen(vector<int> &nums, int k) {
		// Write your code here
		if (nums.empty())
			return 0;
		int res = 0;
		unordered_map<int, int> m;//存放nums中元素的值和位置
		int len = nums.size();
		//nums[i]表示从nums[0]到nums[i]的和
		for (int i = 1; i < len; ++i)
			nums[i] += nums[i - 1];
		for (int i = 0; i < len; ++i)
		{
			//重复元素,存放较小位置
			if (m.find(nums[i]) == m.end())
				m[nums[i]] = i;
		}
		//若nums[i]等于k,子数组为nums[0]到nums[i],长度为i + 1
		for (int i = len - 1; i >= 0; --i)
		{
			if (nums[i] == k)
			{
				res = i + 1;
				break;
			}
		}
		//在m中寻找nums[i]-k,如果存在,且m[nums[i]-k]的值小于等于i
		//说明在nums[0]到nums[i]中,存在子数组的和位k,子数组长度为i - m[nums[i] - k
		for (int i = 0; i < len; ++i)
		{
			if (m.find(nums[i] - k) != m.end() && m[nums[i] - k] <= i)
			{
				res = maxVal(res, i - m[nums[i] - k]);
			}
		}
		return res;
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif