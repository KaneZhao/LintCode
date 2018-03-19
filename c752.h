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
		//dp[i][j]��ʾ��������iʱʣ����Ϊj�ķ�ʽ��
		vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
		//��ʼ��,������0�����Ϊm
		dp[0][m] = 1;
		//��������i,i-1��i-limit����ֱ�ӵ���
		//dp[i][k]��ʾʣ����Ϊk�ķ�ʽ��,���ڻ���Ϊcost[i],
		//����ǰһ��������������Ӧ�ķ�ʽ��Ϊdp[pos][k+cost[i]](i-limit <= pos <= i-1)
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
		//��ʣ��Ǯ���ĸ��ַ�ʽ����ӵõ����
		long long res = 0;
		for (int i = 0; i <= m; ++i)
			res += dp[n][i];
		return res;
	}
};
#endif