#ifndef C782_H
#define C782_H
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
* ����
*
* ����
* �� n ���Ǹ������������������ͣ���С��ͣ������ͣ���С������ĸ���֮�͡�
* �����Ϊ�� n �����У���ȡ���ɸ��������ܲ�ȡ�������л��������������
* ��С���Ϊ�� n �����У���ȡ���ɸ��������ܲ�ȡ�������л��������С������
* ������Ϊ�� n �����У���ȡ���ɸ��������ܲ�ȡ�����������������������
* ��С���Ϊ�� n �����У���ȡ���ɸ��������ܲ�ȡ�����������������С������
* 1 <= n <= 1000000��0 <= nums[i] <= 2^32 - 1��
*/
class Solution {
public:
	/**
	* @param n:
	* @param nums:
	* @return: return the sum of maximum OR sum, minimum OR sum, maximum AND sum, minimum AND sum.
	*/
	long long getSum(int n, vector<int> &nums) {
		// write your code here
		if (n == 1)
			return nums[0] * 4;
		int Max = nums[0], Min = nums[0];// ������Ϊ����Ԫ�ص����ֵ,��С���Ϊ����Ԫ�ص���Сֵ
		long long res = 0;
		vector<int> MinAnd(32,1),MaxOr(32,0);//����MinAnd��MaxOr�ֱ��ʾ��С����Լ������
		//����Ԫ��nums[j],��MinAnd��,�����iλΪ0,��MinAnd[i]=0;��MaxOr��,�����iλΪ1,��MaxOr[i]=1
		for (int j = 0; j < nums.size();++j)
		{
			int temp = nums[j];
			for (int i = 31; i >= 0; --i)
			{
				if (temp == 0)
				{
					MinAnd[i] = 0;
				}
				else
				{
					if (temp % 2 == 1)
						MaxOr[i] = 1;
					else
						MinAnd[i] = 0;
				}
				temp /= 2;
			}
			if (Max < nums[j])
				Max = nums[j];
			if (Min > nums[j])
				Min = nums[j];
		}
		int MinAndVal = 0, MaxOrVal = 0;
		for (int i = 0; i < 32; ++i)
		{
			MinAndVal += MinAnd[i] * pow(2, 31 - i);
			MaxOrVal += MaxOr[i] * pow(2, 31 - i);
		}
		res = Max + Min + MinAndVal + MaxOrVal;
		return res;
	}
};
#endif