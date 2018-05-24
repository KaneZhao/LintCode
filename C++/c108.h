#ifndef C108_H
#define C108_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* �ָ���Ĵ� II
*
* ����һ���ַ���s����s�ָ��һЩ�Ӵ���ʹÿ���Ӵ����ǻ��ġ�
* ����s����Ҫ��ĵ����ٷָ������
* ����
* ���磬�����ַ���s = "aab"��
* ���� 1�� ��Ϊ����һ�ηָ���Խ��ַ���s�ָ��["aa","b"]�������������Ӵ�
*/
class Solution {
public:
	/**
	* @param s a string
	* @return an integer
	*/
	int minCut(string s) {
		// write your code here
		if (s.empty())
			return 0;
		int len = s.size();
		//dp[i][j]��ʾs[i,j]�Ƿ��ǻ��Ĵ�
		vector<vector<bool>> dp(len, vector<bool>(len,false));
		//sum[i]��ʾs[0,i]�����ٷָ����
		vector<int> nums(len);
		//��ʼ��sum,sum[i]=i
		for (int i = 0; i < len; ++i)
			nums[i] = i;
		//���ַ�������Ϊ1ʱ,�ǻ��Ĵ�
		for (int i = 0; i < len; ++i)
			dp[i][i] = true;
		//���ò���,���α���ÿ��λ��
		//��ǰλ�õ��ַ���ͬ�����ڲ����ַ����ǻ��Ĵ�(���ߵ�ǰλ������),��ǰλ�ñ�ʾ���ַ����ǻ��Ĵ�
		for (int path = 1; path < len; ++path)
		{
			for (int k = 0; k + path < len; ++k)
			{
				if (s[k] == s[k+path] && (dp[k + 1][k + path - 1]||path == 1))
					dp[k][k + path] = true;
			}
		}
		//��s[j,i]�ǻ��Ĵ�,���и���Ϊnums[j-1]+1
		for (int i = 1; i < len; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (dp[j][i])
				{
					if (j == 0)
						nums[i] = 0;
					else
						nums[i] = minVal(nums[i], nums[j - 1] + 1);
				}
			}
		}
		return nums[len - 1];
	}
	int minVal(int a, int b)
	{
		return a < b ? a : b;
	}
};
#endif