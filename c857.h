#ifndef C857_H
#define C857_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* Minimum Window Subsequence
*
* Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.
* If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.
* 注意事项
* All the strings in the input will only contain lowercase letters.
* The length of S will be in the range [1, 20000].
* The length of T will be in the range [1, 100].
* 样例
* Given S = "abcdebdde", T = "bde"
* Return "bcde"
* Explanation:
* "bcde" is the answer because it occurs before "bdde" which has the same length.
* "deb" is not a smaller window because the elements of T in the window must occur in order.
*/
class Solution {
public:
	/**
	* @param S: a string
	* @param T: a string
	* @return: the minimum substring of S
	*/
	string minWindow(string &S, string &T) {
		// Write your code here
		int len = S.size();
		int size = T.size();
		string res;
		int length = INT_MAX;
		//dp[i][j]=k表示T[0,j]时S[k,i]的子串且S[k,i]最短
		vector<vector<int>> dp(len, vector<int>(size));
		//当S[i]==T[0],T[0]是S[i]的子串,其它情况置为-1
		for (int i = 0; i < len; ++i)
		{
			dp[i][0] = -1;
			if (S[i] == T[0])
				dp[i][0] = i;
		}
		//当k!=-1,表示T[0,j-1]是S[k,i]的子串
		//i++,若T[j]=S[i],则T[0,j]是S[k,i]的子串,dp[i][j]=k
		for (int j = 1; j < size; ++j)
		{
			int k = -1;
			for (int i = 0; i < len; ++i)
			{
				dp[i][j] = -1;
				if (k != -1 && S[i] == T[j])
					dp[i][j] = k;
				if (dp[i][j - 1] != -1)
					k = dp[i][j - 1];
			}
		}
		//找出S满足条件的长度最短的子串,且保证长度相同的子串,优先输出下标小的
		int start = -1;
		for (int i = 0; i<len; ++i)
		{
			if (dp[i][size - 1] != -1)
			{ 
				if (i - dp[i][size - 1] + 1 < length)
				{
					length = i - dp[i][size - 1] + 1;
					start = dp[i][size - 1];
				}
				else if (i - dp[i][size - 1] + 1 == length)
					start = minVal(start, dp[i][size - 1]);
			}
		}
		return length==INT_MAX?"":S.substr(start,length);
	}
	int minVal(int a, int b)
	{
		return a < b ? a : b;
	}
};
#endif