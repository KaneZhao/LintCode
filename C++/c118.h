#ifndef C118_H
#define C118_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	/**
	* @param S, T: Two string.
	* @return: Count the number of distinct subsequences
	*/
	int numDistinct(string &S, string &T) {
		// write your code here
		int m = S.size();
		int n = T.size();
		//dp[i][j]��ʾSǰi���ַ��г���T��ǰj���ַ��ĸ���
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		//��j=0,Ϊ��,���ֵĸ���ΪΪ1
		//��i=0,j!=0,���ֵĸ���Ϊ0
		for (int i = 0; i <= m; ++i)
			dp[i][0] = 1;
		for (int j = 1; j <= n; ++j)
			dp[0][j] = 0;
		//����S[0,i-1]�Ѿ�ƥ����j ���ַ�,�õ�ƥ�����Ϊdp[i-1][j],����dp[i][j],ƥ��ĸ���������dp[i][j - 1]
		//���S[i]==T[j]����ǰ��ĸΪ��ѡ���ȥ������ĸ��ƥ�����Ϊdp[i-1][j-1]�����Ա任�������ڱ��������ĸ�ı任�������ϲ��������ĸ�ı任������
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				dp[i][j] = dp[i - 1][j] + (S[i - 1] == T[j - 1] ? dp[i - 1][j - 1] : 0);
			}
		}
		return dp[m][n];
	}
};
#endif