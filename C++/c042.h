#ifndef C42_H
#define C42_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 最大子数组 II
*
* 给定一个整数数组，找出两个 不重叠 子数组使得它们的和最大。
* 每个子数组的数字在数组中的位置应该是连续的。
* 返回最大的和。
* 注意事项
* 子数组最少包含一个数
* 样例
* 给出数组 [1, 3, -1, 2, -1, 2]
* 这两个子数组分别为 [1, 3] 和 [2, -1, 2] 或者 [1, 3, -1, 2] 和 [2]，它们的最大和都是 7
* 挑战
* 要求时间复杂度为 O(n)
*/
class Solution {
public:
	int maxTwoSubArrays(vector<int> nums) {
		int res1 =INT_MIN, res2 = INT_MIN;
		int Max = INT_MIN;
		int tmp1 = 0, tmp2 = 0;
		int len = nums.size();
		vector<int> left(len, 0);
		vector<int> right(len, 0);
		//left[i]表示nums[0]到nums[i]表示的数组,其子数组和的最大值
		for (int i = 0; i<len; ++i)
		{
			if (tmp1<0)
				tmp1 = 0;
			tmp1 += nums[i];
			res1 = maxVal(res1, tmp1);
			left[i] = res1;
		}
		//right[j]表示nums[j]到nums[len-1]表示的数组,其子数组和的最大值
		for (int j = len - 1; j >= 0; --j)
		{
			if (tmp2<0)
				tmp2 = 0;
			tmp2 += nums[j];
			res2 = maxVal(res2, tmp2);
			right[j] = res2;
		}
		//求两个子数组和的最大值
		for (int k = 0; k<len - 1; ++k)
		{
			Max = maxVal(Max, left[k] + right[k + 1]);
		}
		return Max;
	}
	int maxVal(int a, int b)
	{
		return a>b ? a : b;
	}
};
#endif