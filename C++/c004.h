#ifndef C004_H
#define C004_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
*���� II
*
* ����
* ���һ���㷨���ҳ�ֻ��������2��3��5 �ĵ� n С������
* �������������磺1, 2, 3, 4, 5, 6, 8, 9, 10, 12...
* ���ǿ�����Ϊ1Ҳ��һ������
* ����
* ���n = 9�� ���� 10
* ��ս
* Ҫ��ʱ�临�Ӷ�ΪO(nlogn)����O(n)
*/
class Solution {
public:
	/**
	* @param n: An integer
	* @return: the nth prime number as description.
	*/
	int nthUglyNumber(int n) {
		// write your code here
		if (n <= 0)
			return 0;
		//ÿ��������������2^i*3^j*5^k����ʽ����ʾ,�������򣬵õ��ĵ�n����Ϊ���
		vector<int> nums(n, 0);
		nums[0] = 1;
		int num_2 = 0, num_3 = 0, num_5 = 0;
		for (int i = 1; i < n; ++i)
		{
			nums[i] = min(min(nums[num_2] * 2, nums[num_3] * 3), nums[num_5] * 5);
			if (nums[i] % 2 == 0)
				num_2++;
			if (nums[i] % 3 == 0)
				num_3++;
			if (nums[i] % 5 == 0)
				num_5++;
		}
		return nums[n - 1];
	}
};
#endif