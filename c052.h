#ifndef C052_H
#define C052_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* ��һ������
*
* ����
* ����һ��������������ʾ���У��ҳ���֮���һ�����С�
* �����п��ܰ����ظ�������
* ����
* ��������[1,3,2,3]������һ��������[1,3,3,2]
* ��������[4,3,2,1]������һ��������[1,2,3,4]
*/
class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: A list of integers
	*/
	vector<int> nextPermutation(vector<int> &nums) {
		// write your code here
		if (nums.empty() || nums.size() == 1)
			return nums;
		int pos = -1;
		int len = nums.size();
		for (int i = len - 2; i >= 0; --i)
		{
			if (nums[i] < nums[i + 1])
			{
				pos = i;
				break;
			}
		}
		if (pos == -1)
		{
			reverse(nums.begin(), nums.end());
			return nums;
		}
		for (int i = len - 1; i >= 0; --i)
		{
			if (nums[i]>nums[pos])
			{
				swap(nums[i], nums[pos]);
				break;
			}
		}
		reverse(nums.begin() + pos + 1, nums.end());
		return nums;
	}
};
#endif