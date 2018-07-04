#ifndef C31_H
#define C31_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ���黮��
* 
* ����
* ����һ���������� nums ��һ������ k���������飨���ƶ����� nums �е�Ԫ�أ���ʹ�ã�
* ����С��k��Ԫ���Ƶ����
* ���д��ڵ���k��Ԫ���Ƶ��ұ�
* �������黮�ֵ�λ�ã��������е�һ��λ�� i������ nums[i] ���ڵ��� k��
* ��Ӧ�������Ļ������� nums����������ֻ�Ǽ���� k С����������������� nums �е�����Ԫ�ض��� k С���򷵻� nums.length��
* ����
* �������� nums = [3,2,2,1] �� k = 2������ 1.
* ��ս
* ʹ�� O(n) ��ʱ�临�Ӷ��������Ͻ��л��֡�
*/
class Solution {
public:
	/**
	* @param nums: The integer array you should partition
	* @param k: An integer
	* @return: The index after partition
	*/
	int partitionArray(vector<int> &nums, int k) {
		// write your code here
		if (nums.empty())
			return 0;
		int left = 0, right = nums.size() - 1;
		//����ָ��
		while (left < right)
		{
			if (nums[left] >= k)
			{
				if (nums[right] < k)
				{
					swap(nums[left], nums[right]);
					left++;
					right--;
				}
				else
				{
					right--;
				}
			}
			else
			{
				if (nums[right] >= k)
				{
					left++;
					right--;
				}
				else
				{
					left++;
				}
			}
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] >= k)
				return i;
		}
		return nums.size(); 
	}
};
#endif