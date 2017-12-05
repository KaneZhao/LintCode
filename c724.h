#ifndef C724_H
#define C724_H
#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>
using namespace std;
/*
* 最小划分
* 给出一个整数数组，写一个程序把这个整数数组分成S1跟S2两部分，使S1中的和跟S2中的和的绝对值最小。如果有一个一个整数数组 S 有 n 个数，如果Subset1有 m 个数，Subset2必须有 n-m 个数并且 abs(sum(Subset1) – sum(Subset2)) 应该最小
*
* 样例
* 给出nums = [1, 6, 11, 5]，返回1
*
* Subset1 = [1, 5, 6]，和是12
* Subset2 = [11]，和是11
* abs(11 - 12) = 1
*/
class Solution {
public:
	/*
	* @param : the given array
	* @return: the minimum difference between their sums
	*/
	//参考背包问题，求出数组的和sum，把问题转化成求背包的大小为sum/2，将给定的数组装入背包，求出最多可以装满的空间res，返回结果|res-(sum-res)|。
	int findMin(vector<int> &nums) {
		// write your code here
		int sum = accumulate(nums.begin(), nums.end(), 0);
		int res = backPack(sum / 2, nums);
		return abs(2 * res - sum);
	}
	//背包问题，在n个物品中挑选若干物品装入背包，最多能装多满？假设背包的大小为m，每个物品的大小为A[i]
	int backPack(int m, vector<int> A) {
		// write your code here
		if (A.empty())
			return 0;
		vector<int> dp(m + 1, 0);
		for (int i = 0; i<A.size(); ++i)
		{
			for (int j = m; j >= 1; --j)
			{
				if (j >= A[i])
					dp[j] = maxVal(dp[j - A[i]] + A[i], dp[j]);
			}
		}
		return dp[m];
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif