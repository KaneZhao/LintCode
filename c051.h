#ifndef C51_H
#define C51_H
#include<vector>
#include<iostream>
using namespace std;
/*
* ��һ������
*
* ����һ��������������ʾ���У��ҳ�����һ�����С�
* �����п��ܰ����ظ�������
* ����
* ��������[1,3,2,3]������һ��������[1,2,3,3]
* ��������[1,2,3,4]������һ��������[4,3,2,1]
*/
class Solution {
public:
	vector<int> previousPermuation(vector<int> &nums) {
		// write your code here
		if (nums.empty() || nums.size() == 1)
			return nums;
		int len = nums.size();
		int pos = -1;
		for (int i = len - 2; i >= 0; --i)
		{
			if (nums[i] > nums[i + 1])
			{
				pos = i;
				break;
			}
		}
		if (pos == -1)
		{
			reverse(nums.begin(), nums.end());
		}
		else
		{
			for (int i = len - 1; i >= 0; --i)
			{
				if (nums[i] < nums[pos])
				{
					swap(nums[i], nums[pos]);
					reverse(nums.begin() + pos + 1, nums.end());
					break;
				}
			}
		}
		return nums;
	}
};
#endif