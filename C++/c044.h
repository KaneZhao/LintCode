#ifndef C44_H
#define C44_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ��С������
*
* ����һ���������飬�ҵ�һ��������С�͵������顣��������С�͡�
* ע������
* ���������ٰ���һ������
* ����
* ��������[1, -1, -2, 1]������ -3
*/
class Solution {
public:
	int minSubArray(vector<int> nums) {
		int len = nums.size();
		int sum = 0;
		int ans = INT_MAX;
		for (int i = 0; i < len; ++i)
		{
			sum += nums[i];
			if (sum < ans)
				ans = sum;
			//���sum>0,��ȡ�������
			if (sum>0)
				sum = 0;
		}
		return ans;
	}
};

#endif