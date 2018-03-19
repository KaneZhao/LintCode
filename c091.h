#ifndef C91_H
#define C91_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 最小调整代价
*
* 给一个整数数组，调整每个数的大小，使得相邻的两个数的差不大于一个给定的整数target，调整每个数的代价为调整前后的差的绝对值，求调整代价之和最小是多少。
* 注意事项
* 你可以假设数组中每个整数都是正整数，且小于等于100。
* 样例
* 对于数组[1, 4, 2, 3]和target=1，最小的调整方案是调整为[2, 3, 2, 3]，调整代价之和是2。返回2。
*/
class Solution {
public:
	/**
	* @param A: An integer array.
	* @param target: An integer.
	*/
	int MinAdjustmentCost(vector<int> A, int target) {
		// write your code here
		if (A.empty() || A.size() < 2)
			return 0;
		int len = A.size();
		vector<vector<int>> dp(len, vector<int>(101, INT_MAX));//dp[i][j]存放A[i]变到j的最小调整代价
		for (int i = 0; i < 101; ++i)
			dp[0][i] = abs(i - A[0]);
		for (int i = 1; i < len; ++i)
		{
			for (int j = 0; j < 101; ++j)
			{
				//保证数字范围在0~100
				int upper = min(j + target, 100);
				int lower = max(j - target, 0);
				//将A[i]变到j,此时A[i-1]的取值为k,dp[i][j]为A[i-1]到k和A[i]到j的绝对值之和
				//dp[i][j]=min{dp[i-1][k]+abs(j-A[i])}
				for (int k = lower; k <= upper; ++k)
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(j - A[i]));
			}
		}
		int res = INT_MAX;
		for (int i = 0; i < 101; ++i)
			res = min(res, dp[len - 1][i]);
		return res;
	}
};
#endif