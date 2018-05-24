#ifndef C59_H
#define C59_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 最接近的三数之和
*
* 描述
* 给一个包含 n 个整数的数组 S, 找到和与给定整数 target 最接近的三元组，返回这三个数的和。
* 只需要返回三元组之和，无需返回三元组本身
* 样例
* 例如 S = [-1, 2, 1, -4] and target = 1. 和最接近 1 的三元组是 -1 + 2 + 1 = 2.
* 挑战
* O(n^2) 时间, O(1) 额外空间。
*/
class Solution {
public:
	int threeSumClosest(vector<int> nums, int target) {
		// write your code here
		if (nums.empty()|| nums.size()<3)
			return 0;
		int len = nums.size();
		int res = nums[0]+nums[1]+nums[len-1];
		//只寻找三元组不必考虑顺序
		sort(nums.begin(), nums.end());
		//当sum大于target,k向前移动,sum值变小
		//当sum小于target,j向后移动,sum值变大
		for (int i = 0; i < len - 2; ++i)
		{
			int j = i + 1;
			int k = len - 1;
			while (j < k)
			{
				int sum = nums[i] + nums[j] + nums[k];
				res = absVal(res - target)<absVal(sum - target) ? res : sum;
				if (sum>target)
					--k;
				else if (sum == target)
					return target;
				else
					++j;
			}
		}
		return res;
	}
	int absVal(int a)
	{
		if (a >= 0)
			return a;
		else
			return -a;
	}
};
#endif