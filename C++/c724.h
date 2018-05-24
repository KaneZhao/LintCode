#ifndef C724_H
#define C724_H
#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>
using namespace std;
/*
* ��С����
* ����һ���������飬дһ������������������ֳ�S1��S2�����֣�ʹS1�еĺ͸�S2�еĺ͵ľ���ֵ��С�������һ��һ���������� S �� n ���������Subset1�� m ������Subset2������ n-m �������� abs(sum(Subset1) �C sum(Subset2)) Ӧ����С
*
* ����
* ����nums = [1, 6, 11, 5]������1
*
* Subset1 = [1, 5, 6]������12
* Subset2 = [11]������11
* abs(11 - 12) = 1
*/
class Solution {
public:
	/*
	* @param : the given array
	* @return: the minimum difference between their sums
	*/
	//�ο��������⣬�������ĺ�sum��������ת�����󱳰��Ĵ�СΪsum/2��������������װ�뱳�������������װ���Ŀռ�res�����ؽ��|res-(sum-res)|��
	int findMin(vector<int> &nums) {
		// write your code here
		int sum = accumulate(nums.begin(), nums.end(), 0);
		int res = backPack(sum / 2, nums);
		return abs(2 * res - sum);
	}
	//�������⣬��n����Ʒ����ѡ������Ʒװ�뱳���������װ���������豳���Ĵ�СΪm��ÿ����Ʒ�Ĵ�СΪA[i]
	int backPack(int m, vector<int> A) {
		// write your code here
		if (A.empty())
			return 0;
		vector<int> dp(m + 1, 0);
		for (int i = 0; i<A.size(); ++i)
		{
			for (int j = m; j >= 1; --j)
			{
				if (j >= A[i])
					dp[j] = maxVal(dp[j - A[i]] + A[i], dp[j]);
			}
		}
		return dp[m];
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif