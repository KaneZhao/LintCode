#ifndef C843_H
#define C843_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ���ַ�ת
*
* ����һ��01���ɵ����顣�����ҳ���С��ת������ʹ�������������¹���
* 1�ĺ��������1����0������0�ĺ��������0��
* ע������
* ��������鳤��n <= 100000��
* ����
* ���� array = [1,0,0,1,1,1] , ����2��
* ���ͣ�
* ������0��ת��1��
* ���� array = [1,0,1,0,1,0] , ����2��
* ���ͣ�
* �ѵڶ���1�͵�����1����ת��0��
*/
class Solution {
public:
	/**
	* @param nums: the array
	* @return: the minimum times to flip digit
	*/
	int flipDigit(vector<int> &nums) {
		// Write your code here
		int numOne = 0;
		int preOne = 0, res = nums.size();
		for (auto c : nums)
		{
			if (c == 1)
				numOne++;
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == 1)
				preOne++;
			res = minVal(res, numOne - preOne + i + 1 - preOne);
		}
		return res;
	}
	int minVal(int a, int b)
	{
		return a < b ? a : b;
	}
};
#endif