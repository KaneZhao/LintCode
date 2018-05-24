#ifndef C29_H
#define C29_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* �����ַ���
*
* ���������ַ���:s1��s2��s3���ж�s3�Ƿ���s1��s2���湹�ɡ�
* ����
* ���� s1 = "aabcc" s2 = "dbbca"
* �� s3 = "aadbbcbcac"������  true.
* �� s3 = "aadbbbaccc"�� ���� false.
* ��ս
* Ҫ��ʱ�临�Ӷ�ΪO(n^2)���߸���
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
		//dp[i][j]��ʾs1��ǰi���ַ���s2��ǰj���ַ�,�Ƿ���Խ��湹��s3��ǰi+j���ַ�
		vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
		//��j = 0,ֻ����s1��s3
		for (int i = 1; i <= len1; ++i)
		{
			if (s1[i - 1] == s3[i - 1])
				dp[i][0] = true;
		}
		//��i = 0,ֻ����s2��s3
		for (int j = 1; j <= len2; ++j)
		{
			if (s2[j - 1] == s3[j - 1])
				dp[0][j] = true;
		}
		//����dp[i][j]ֻ��Ҫ����dp[i][j-1]��dp[i-1][j]
		//��dp[i][j-1]Ϊtrue,s1��ǰi���ַ���s2��ǰj-1���ַ����湹��s3��ǰi+j-1���ַ�
		//��ʱ�Ƚ�s2�ĵ�j���ַ���s3�ĵ�i+j���ַ�
		//��dp[i-1][j]Ϊtrue,s1��ǰi-1���ַ���s2��ǰj���ַ����湹��s3��ǰi+j-1���ַ�
		//��ʱ�Ƚ�s1�ĵ�i���ַ���s3�ĵ�i+j���ַ�
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