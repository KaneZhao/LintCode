#ifndef C752_H
#define C752_H
#include<iostream>
#include<vector>
#include<map>
using namespace std; 
class Solution {
public:
	/**
	* @param n: the max identifier of planet.
	* @param m: gold coins that Sven has.
	* @param limit: the max difference.
	* @param cost: the number of gold coins that reaching the planet j through the portal costs.
	* @return: return the number of ways he can reach the planet n through the portal.
	*/
	long long getNumberOfWays(int n, int m, int limit, vector<int> &cost) {
		// Write your code here
		//dp[i][j]表示到达星球i时剩余金币为j的方式数
		vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
		//初始化,在星球0金币数为m
		dp[0][m] = 1;
		//对于星球i,i-1到i-limit可以直接到达
		//dp[i][k]表示剩余金币为k的方式数,由于花销为cost[i],
		//则在前一个到达的星球其对应的方式数为dp[pos][k+cost[i]](i-limit <= pos <= i-1)
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= limit&&j<=i; ++j)
			{
				for (int k = 0; k + cost[i] <= m; ++k)
				{
					dp[i][k] += dp[i - j][k + cost[i]];
				}
			}
		}
		//将剩余钱数的各种方式数相加得到结果
		long long res = 0;
		for (int i = 0; i <= m; ++i)
			res += dp[n][i];
		return res;
	}
};
#endif