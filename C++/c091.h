#ifndef C91_H
#define C91_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* ��С��������
*
* ��һ���������飬����ÿ�����Ĵ�С��ʹ�����ڵ��������Ĳ����һ������������target������ÿ�����Ĵ���Ϊ����ǰ��Ĳ�ľ���ֵ�����������֮����С�Ƕ��١�
* ע������
* ����Լ���������ÿ��������������������С�ڵ���100��
* ����
* ��������[1, 4, 2, 3]��target=1����С�ĵ��������ǵ���Ϊ[2, 3, 2, 3]����������֮����2������2��
*/
class Solution {
public:
	/**
	* @param A: An integer array.
	* @param target: An integer.
	*/
	int MinAdjustmentCost(vector<int> A, int target) {
		// write your code here
		if (A.empty() || A.size() < 2)
			return 0;
		int len = A.size();
		vector<vector<int>> dp(len, vector<int>(101, INT_MAX));//dp[i][j]���A[i]�䵽j����С��������
		for (int i = 0; i < 101; ++i)
			dp[0][i] = abs(i - A[0]);
		for (int i = 1; i < len; ++i)
		{
			for (int j = 0; j < 101; ++j)
			{
				//��֤���ַ�Χ��0~100
				int upper = min(j + target, 100);
				int lower = max(j - target, 0);
				//��A[i]�䵽j,��ʱA[i-1]��ȡֵΪk,dp[i][j]ΪA[i-1]��k��A[i]��j�ľ���ֵ֮��
				//dp[i][j]=min{dp[i-1][k]+abs(j-A[i])}
				for (int k = lower; k <= upper; ++k)
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(j - A[i]));
			}
		}
		int res = INT_MAX;
		for (int i = 0; i < 101; ++i)
			res = min(res, dp[len - 1][i]);
		return res;
	}
};
#endif