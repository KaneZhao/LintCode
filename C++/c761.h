#ifndef C761_H
#define C761_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* Smallest Subset
*
* Given an array of non-negative integers. Our task is to find minimum number of elements such that their sum should be greater than the sum of rest of the elements of the array.
* ����
* Given nums = [3, 1, 7, 1], return 1
* Given nums = [2, 1, 2], return 2
*/
class Solution {
public:
	/**
	* @param nums: an array of non-negative integers
	* @return: minimum number of elements
	*/
	int minElements(vector<int> &nums) {
		// write your code here
		if (nums.empty())
			return 0;
		int sum = 0;
		int cnt = 0;
		sort(nums.begin(),nums.end());//��������
		for (auto c : nums)//����nums����Ԫ�صĺ�
			sum += c;
		sum = sum / 2 + 1;//ȡԪ��֮�͵�һ��
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			sum -= nums[i];
			cnt++;
			if (sum <= 0)//����ʱȡ���������Ѿ�����Ԫ��֮�͵�һ��,����cnt
			{
				return cnt;
			}
		}
	}
};
#endif