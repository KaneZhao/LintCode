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
* ע������
* All the strings in the input will only contain lowercase letters.
* The length of S will be in the range [1, 20000].
* The length of T will be in the range [1, 100].
* ����
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
		//dp[i][j]=k��ʾT[0,j]ʱS[k,i]���Ӵ���S[k,i]���
		vector<vector<int>> dp(len, vector<int>(size));
		//��S[i]==T[0],T[0]��S[i]���Ӵ�,���������Ϊ-1
		for (int i = 0; i < len; ++i)
		{
			dp[i][0] = -1;
			if (S[i] == T[0])
				dp[i][0] = i;
		}
		//��k!=-1,��ʾT[0,j-1]��S[k,i]���Ӵ�
		//i++,��T[j]=S[i],��T[0,j]��S[k,i]���Ӵ�,dp[i][j]=k
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
		//�ҳ�S���������ĳ�����̵��Ӵ�,�ұ�֤������ͬ���Ӵ�,��������±�С��
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