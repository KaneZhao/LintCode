#ifndef C119_H
#define C119_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* 编辑距离
*
* 给出两个单词word1和word2，计算出将word1 转换为word2的最少操作次数。
* 你总共三种操作方法：
* 插入一个字符
* 删除一个字符
* 替换一个字符
* 样例
* 给出 work1="mart" 和 work2="karma"
* 返回 3
*/
class Solution {
public:
	/**
	* @param word1 & word2: Two string.
	* @return: The minimum number of steps.
	*/
	int minDistance(string word1, string word2) {
		// write your code here
		int m = word1.size();
		int n = word2.size();
		//dp[i][j]表示word1前i个字符转换到word2前j个字符的最少操作次数
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		//word1的前i个字符转换成0个字符,删除操作,次数为i
		for (int i = 0; i <= m; ++i)
			dp[i][0] = i;
		//word1由0个字符转换到word2的前j个字符,插入操作,次数为i
		for (int j = 1; j <= n; ++j)
			dp[0][j] = j; 
		//若当前的位置的字符相同,操作次数为前一个位置的操作数dp[i-1][j-1]
		//否则,为dp[i-1][j-1](替换),dp[i-1][j],dp[i][j-1](删除)的最小值加一
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = minVal(dp[i - 1][j - 1], minVal(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
		}
		return dp[m][n];
	}
	int minVal(int a, int b)
	{
		return a < b ? a : b;
	}
};
#endif