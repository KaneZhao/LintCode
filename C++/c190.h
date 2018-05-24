#ifndef C190_H
#define C190_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* ��һ������
*
* ����
* ����һ���������������У�������������С�����ֵ����С������������һ�����С�
* ���û����һ�����У�������ֵ�����С�����С�
* ����
* �����ԭʼ���У��ұ��Ƕ�Ӧ����һ�����С�
* 1,2,3 �� 1,3,2
* 3,2,1 �� 1,2,3
* 1,1,5 �� 1,5,1
* ��ս
* ������ʹ�ö���Ŀռ䡣
*/
class Solution {
public:
	/**
	* @param nums: a vector of integers
	* @return: return nothing (void), do not return anything, modify nums in-place instead
	*/
	void nextPermutation(vector<int> &nums) {
		// write your code here
		if (nums.empty() || nums.size() == 1)
			return;
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
			return;
		}
		for (int i = len - 1; i >= 0; --i)
		{
			if (nums[i] > nums[pos])
			{
				swap(nums[i], nums[pos]);
				break;
			}
		}
		reverse(nums.begin() + pos + 1, nums.end());
	}
};
#endif