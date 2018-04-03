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
		//dp[i][j]表示S前i个字符中出现T的前j个字符的个数
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		//当j=0,为空,出现的个数为为1
		//当i=0,j!=0,出现的个数为0
		for (int i = 0; i <= m; ++i)
			dp[i][0] = 1;
		for (int j = 1; j <= n; ++j)
			dp[0][j] = 0;
		//假设S[0,i-1]已经匹配了j 个字符,得到匹配个数为dp[i-1][j],对于dp[i][j],匹配的个数至少是dp[i][j - 1]
		//如果S[i]==T[j]，则当前字母为可选择项，去掉此字母的匹配个数为dp[i-1][j-1]，所以变换方法等于保留这个字母的变换方法加上不用这个字母的变换方法。
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