#ifndef C44_H
#define C44_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 最小子数组
*
* 给定一个整数数组，找到一个具有最小和的子数组。返回其最小和。
* 注意事项
* 子数组最少包含一个数字
* 样例
* 给出数组[1, -1, -2, 1]，返回 -3
*/
class Solution {
public:
	int minSubArray(vector<int> nums) {
		int len = nums.size();
		int sum = 0;
		int ans = INT_MAX;
		for (int i = 0; i < len; ++i)
		{
			sum += nums[i];
			if (sum < ans)
				ans = sum;
			//如果sum>0,则不取这段数组
			if (sum>0)
				sum = 0;
		}
		return ans;
	}
};

#endif