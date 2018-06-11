#ifndef C1444_H
#define C1444_H
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
* 染色问题
*
* 描述
* 有一个圆形，分成n个扇形，用m种颜色给每个扇形染色，相邻扇形颜色不能相同。求方案总数。
* 不考虑对称性。
* 由于这个数可能很大，因此只需返回方案数模1e9 + 7。
* 1≤n≤10^5,1≤m≤10^5
​​* 样例
* 给定n = 2，m = 3，返回6。
* 解释：
* 一个圆划分为 2 个扇形，用 3 种颜色上色方案有“黑红，黑白，白红，白黑，红白，红黑”6 种。
* 给定 n = 3，m = 2，返回 0。
* 解释：
* 一个圆划分为 3 个扇形，用 2 种颜色上色，无论怎么上色，都没法保证相邻的颜色不同。
*/
class Solution {
public:
	/**
	* @param n: the number of sectors
	* @param m: the number of colors
	* @return: The total number of plans.
	*/
	int getCount(int n, int m) {
		// Write your code here
		
		/*
		//动态规划求解
		long long  dp[100001];
		long long num = 1e9 + 7;
		dp[1] = m;
		dp[2] = (long long)m*(m - 1) % num;
		dp[3] = (long long)m*(m - 1)*(m - 2) % num;
		for (int i = 4; i <= n; ++i)
			dp[i] = (dp[i - 1] * (m - 2) + dp[i - 2] * (m - 1))%num;
		return dp[n];*/

		//直接求解得到结果
		long long num = 1e9 + 7;
		long long res = myPow(m - 1, n) % num + pow(-1, n - 2)*(m - 1);
		return res;
	}
	//二分法求指数
	long long myPow(int m, int n)
	{
		if (n == 0)
			return 1;
		if (n == 1)
			return m;
		long long num = 1e9 + 7;
		long long res = myPow(m, n >> 1);
		res = res * res % num;
		if (n & 1 == 1)
			res = res * m % num;
		return res;
	}
};
#endif