#ifndef C77_H
#define C77_H
#include<iostream>
#include<string>
#include<queue>
using namespace std;
/*
* 最长公共子序列
*
* 给出两个字符串，找到最长公共子序列(LCS)，返回LCS的长度。
* 说明
* 最长公共子序列的定义：
* 最长公共子序列问题是在一组序列（通常2个）中找到最长公共子序列（注意：不同于子串，LCS不需要是连续的子串）。该问题是典型的计算机科学问题，是文件差异比较程序的基础，在生物信息学中也有所应用。
* https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
* 样例
* 给出"ABCD" 和 "EDCA"，这个LCS是 "A" (或 D或C)，返回1
* 给出 "ABCD" 和 "EACB"，这个LCS是"AC"返回 2
*/
class Solution {
public:
	int longestCommonSubsequence(string A, string B) {
		// write your code here
		if (A.empty() || B.empty())
			return 0;
		int len_a = A.size(), len_b = B.size();
		//maxLen[i][j]表示A的前i个字符和B的前j个字符中,最长公共子序列的长度
		vector<vector<int>> maxLen(len_a + 1, vector<int>(len_b + 1));
		for (int i = 0; i <= len_a; ++i)
			maxLen[i][0] = 0;
		for (int j = 1; j <= len_b; ++j)
			maxLen[0][j] = 0;
		//若A[i-1]==B[j-1],公共子序列的长度加一
		//否则,maxLen[i][j]置为maxLen[i][j-1]与maxLen[i-1][j]的较大值
		for (int i = 1; i <= len_a; ++i)
		{
			for (int j = 1; j <= len_b; ++j)
			{
				if (A[i - 1] == B[j - 1])
					maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
				else
					maxLen[i][j] = maxVal(maxLen[i][j - 1], maxLen[i - 1][j]);
			}
		}
		return maxLen[len_a][len_b];
	}
	int maxVal(int a, int b)
	{
		return a > b ? a:b;
	}
};

#endif