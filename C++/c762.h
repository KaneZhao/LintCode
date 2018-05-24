#ifndef C762_H
#define C762_H
#include<iostream>
#include<vector>
using namespace std;
/*
* Longest Common Subsequence II
*
* Given two sequence P and Q of numbers. The task is to find Longest Common Subsequence of two sequence if we are allowed to change at most k element in first sequence to any value.
* ����
* Given P = [8 ,3], Q = [1, 3], K = 1
* Return 2
* Given P = [1, 2, 3, 4, 5], Q = [5, 3, 1, 4, 2], K = 1
* Return 3
*/
class Solution {
public:
	/**
	* @param P: an integer array P
	* @param Q: an integer array Q
	* @param k: the number of allowed changes
	* @return: the length of lca with at most k changes allowed.
	*/
	int longestCommonSubsequence2(vector<int> &P, vector<int> &Q, int k) {
		// Write your code here
		if (P.empty() || Q.empty() || k < 0)
			return 0;
		int lenp = P.size(), lenq = Q.size();
		//dp[i][j][t]��ʾP��ǰi���ַ���Q��ǰj���ַ���,�ڱ任��k��Ԫ�ص������,����������еĳ���
		vector<vector<vector<int>>> dp(lenp + 1, vector<vector<int>>(lenq + 1, vector<int>(k + 1)));
		//��i = 0��j = 0ʱ,dp[i][j][t] = 0
		for (int i = 0; i <= lenp; ++i)
		{
			for (int t = 0; t <= k; ++t)
				dp[i][0][t] = 0;
		}
		for (int j = 0; j <= lenq; ++j)
		{
			for (int t = 0; t <= k; ++t)
				dp[0][j][t] = 0;
		}
		//����k=0�����,�����ڹ���������
		for (int i = 1; i <= lenp; ++i)
		{
			for (int j = 1; j <= lenq; ++j)
			{
				if (P[i - 1] == Q[j - 1])
					dp[i][j][0] = dp[i - 1][j - 1][0] + 1;
				else
					dp[i][j][0] = maxVal(dp[i - 1][j][0], dp[i][j - 1][0]);
			}
		}
		//��P[i-1]=Q[j-1],�����ٱ任Ԫ��,dp[i][j][t]��dp[i-1][j][t],dp[i][j-1][t],dp[i-1][j-1][t]+1�����ֵ
		//����,������Ҫ�任Ԫ��,dp[i][j][t]��dp[i-1][j][t],dp[i][j-1][t],dp[i-1][j-1][t-1]+1�����ֵ
		for (int i = 1; i <= lenp; ++i)
		{
			for (int j = 1; j <= lenq; ++j)
			{
				for (int t = 1; t <= k; ++t)
				{
					if (P[i - 1] == Q[j - 1])
						dp[i][j][t] = maxVal(dp[i - 1][j][t], maxVal(dp[i][j - 1][t], dp[i - 1][j - 1][t] + 1));
					else
						dp[i][j][t] = maxVal(dp[i - 1][j][t], maxVal(dp[i][j - 1][t], dp[i - 1][j - 1][t - 1] + 1));
				}
			}
		}
		return dp[lenp][lenq][k];
	}
	int maxVal(int a, int b)
	{
		return a>b ? a : b;
	}
};
#endif