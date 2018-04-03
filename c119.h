#ifndef C119_H
#define C119_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* �༭����
*
* ������������word1��word2���������word1 ת��Ϊword2�����ٲ���������
* ���ܹ����ֲ���������
* ����һ���ַ�
* ɾ��һ���ַ�
* �滻һ���ַ�
* ����
* ���� work1="mart" �� work2="karma"
* ���� 3
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
		//dp[i][j]��ʾword1ǰi���ַ�ת����word2ǰj���ַ������ٲ�������
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		//word1��ǰi���ַ�ת����0���ַ�,ɾ������,����Ϊi
		for (int i = 0; i <= m; ++i)
			dp[i][0] = i;
		//word1��0���ַ�ת����word2��ǰj���ַ�,�������,����Ϊi
		for (int j = 1; j <= n; ++j)
			dp[0][j] = j; 
		//����ǰ��λ�õ��ַ���ͬ,��������Ϊǰһ��λ�õĲ�����dp[i-1][j-1]
		//����,Ϊdp[i-1][j-1](�滻),dp[i-1][j],dp[i][j-1](ɾ��)����Сֵ��һ
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