#ifndef C79_H
#define C79_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* 最长公共子串
*
* 给出两个字符串，找到最长公共子串，并返回其长度。
* 注意事项
* 子串的字符应该连续的出现在原字符串中，这与子序列有所不同。
* 样例
* 给出A=“ABCD”，B=“CBCE”，返回 2
* 挑战
* O(n x m) time and memory.
*/
class Solution {
public:
	int longestCommonSubstring(string &A, string &B) {
		// write your code here
		if (A.empty() || B.empty())
			return 0;
		int lenA = A.size(), lenB = B.size();
		int res = INT_MIN;
		//dp[i][j]表示以A[i],B[j]为结束字符的字符串,其最长公共子串的长度
		//若A[i]!=B[j],则dp[i][j]为0,否则为dp[i-1][j-1]+1
		vector<vector<int>> dp(lenA, vector<int>(lenB, 0));
		for (int i = 0; i < lenA; ++i)
		{
			for (int j = 0; j < lenB; ++j)
			{
				if (A[i] == B[j])
				{
					if (i < 1 || j < 1)
						dp[i][j] = 1;
					else
						dp[i][j] = dp[i - 1][j - 1] + 1;
				}
			}
		}
		//寻找最大长度
		for (auto c : dp)
		{
			for (auto t : c)
			{
				if (res < t)
					res = t;
			}
		}
		return res;
	}
};
#endif