#ifndef C29_H
#define C29_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* 交叉字符串
*
* 给出三个字符串:s1、s2、s3，判断s3是否由s1和s2交叉构成。
* 样例
* 比如 s1 = "aabcc" s2 = "dbbca"
* 当 s3 = "aadbbcbcac"，返回  true.
* 当 s3 = "aadbbbaccc"， 返回 false.
* 挑战
* 要求时间复杂度为O(n^2)或者更好
*/
class Solution {
public:	
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.empty())
			return s2 == s3;
		if (s2.empty())
			return s1 == s3;
		if (s3.empty())
			return false;
		int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
		if (len1 + len2 != len3)
			return false;
		//dp[i][j]表示s1的前i个字符与s2的前j个字符,是否可以交叉构成s3的前i+j个字符
		vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
		//当j = 0,只考虑s1和s3
		for (int i = 1; i <= len1; ++i)
		{
			if (s1[i - 1] == s3[i - 1])
				dp[i][0] = true;
		}
		//当i = 0,只考虑s2和s3
		for (int j = 1; j <= len2; ++j)
		{
			if (s2[j - 1] == s3[j - 1])
				dp[0][j] = true;
		}
		//对于dp[i][j]只需要考虑dp[i][j-1]和dp[i-1][j]
		//当dp[i][j-1]为true,s1的前i个字符与s2的前j-1个字符交叉构成s3的前i+j-1个字符
		//此时比较s2的第j个字符和s3的第i+j个字符
		//当dp[i-1][j]为true,s1的前i-1个字符与s2的前j个字符交叉构成s3的前i+j-1个字符
		//此时比较s1的第i个字符和s3的第i+j个字符
		for (int i = 1; i <= len1; ++i)
		{
			for (int j = 1; j <= len2; ++j)
			{
				if (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
				{
						dp[i][j] = true;
				}
				if (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
				{
					dp[i][j] = true;
				}
			}
		}
		return dp[len1][len2];
	}
};
#endif