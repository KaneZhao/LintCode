#ifndef C41_H
#define C41_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 最大子数组
*
* 给定一个整数数组，找到一个具有最大和的子数组，返回其最大和。
* 注意事项
* 子数组最少包含一个数
* 样例
* 给出数组[−2,2,−3,4,−1,2,1,−5,3]，符合要求的子数组为[4,−1,2,1]，其最大和为6
* 挑战
* 要求时间复杂度为O(n)
*/
class Solution {
public:
	int maxSubArray(vector<int> nums) {
		int res = INT_MIN;
		int tmp = 0;
		//tmp表示当前遍历的子数组之和,res表示子数组之和的最大值
		//当tmp<0,抛弃已遍历的数组,重新开始计算
		for (auto c : nums)
		{
			if (tmp < 0)
			{
				tmp = 0;
			}
			tmp += c;
			res = maxVal(res, tmp);
		}
		return res;
	}
	int maxVal(int a, int b)
	{
		return a>b ? a : b;
	}
};
#endif