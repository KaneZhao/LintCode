#ifndef C782_H
#define C782_H
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
* 与或和
*
* 描述
* 给 n 个非负整数，请你求出最大或和，最小或和，最大与和，最小与和这四个数之和。
* 最大或和为在 n 个数中，任取若干个数（不能不取），进行或运算后最大的数。
* 最小或和为在 n 个数中，任取若干个数（不能不取），进行或运算后最小的数。
* 最大与和为在 n 个数中，任取若干个数（不能不取），进行与运算后最大的数。
* 最小与和为在 n 个数中，任取若干个数（不能不取），进行与运算后最小的数。
* 1 <= n <= 1000000，0 <= nums[i] <= 2^32 - 1。
*/
class Solution {
public:
	/**
	* @param n:
	* @param nums:
	* @return: return the sum of maximum OR sum, minimum OR sum, maximum AND sum, minimum AND sum.
	*/
	long long getSum(int n, vector<int> &nums) {
		// write your code here
		if (n == 1)
			return nums[0] * 4;
		int Max = nums[0], Min = nums[0];// 最大与和为数组元素的最大值,最小或和为数组元素的最小值
		long long res = 0;
		vector<int> MinAnd(32,1),MaxOr(32,0);//构建MinAnd和MaxOr分别表示最小与和以及最大或和
		//对于元素nums[j],在MinAnd中,若其第i位为0,则MinAnd[i]=0;在MaxOr中,若其第i位为1,则MaxOr[i]=1
		for (int j = 0; j < nums.size();++j)
		{
			int temp = nums[j];
			for (int i = 31; i >= 0; --i)
			{
				if (temp == 0)
				{
					MinAnd[i] = 0;
				}
				else
				{
					if (temp % 2 == 1)
						MaxOr[i] = 1;
					else
						MinAnd[i] = 0;
				}
				temp /= 2;
			}
			if (Max < nums[j])
				Max = nums[j];
			if (Min > nums[j])
				Min = nums[j];
		}
		int MinAndVal = 0, MaxOrVal = 0;
		for (int i = 0; i < 32; ++i)
		{
			MinAndVal += MinAnd[i] * pow(2, 31 - i);
			MaxOrVal += MaxOr[i] * pow(2, 31 - i);
		}
		res = Max + Min + MinAndVal + MaxOrVal;
		return res;
	}
};
#endif