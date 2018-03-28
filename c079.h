#ifndef C79_H
#define C79_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* ������Ӵ�
*
* ���������ַ������ҵ�������Ӵ����������䳤�ȡ�
* ע������
* �Ӵ����ַ�Ӧ�������ĳ�����ԭ�ַ����У�����������������ͬ��
* ����
* ����A=��ABCD����B=��CBCE�������� 2
* ��ս
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
		//dp[i][j]��ʾ��A[i],B[j]Ϊ�����ַ����ַ���,��������Ӵ��ĳ���
		//��A[i]!=B[j],��dp[i][j]Ϊ0,����Ϊdp[i-1][j-1]+1
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
		//Ѱ����󳤶�
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