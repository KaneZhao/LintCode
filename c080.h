#ifndef C80_H
#define C80_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ��λ��
* 
* ����
* ����һ��δ������������飬�ҵ�����λ����
* ��λ���������������м�ֵ���������ĸ�����ż�������򷵻����������ĵ�N/2������
* ����
* ��������[4, 5, 1, 2, 3]�� ���� 3
* ��������[7, 9, 4, 5]������ 5
* ��ս
* ʱ�临�Ӷ�ΪO(n)
*/
class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: An integer denotes the middle number of the array
	*/
	int median(vector<int> &nums) {
		// write your code here
		if (nums.empty())
			return 0;
		int left = 0, right = nums.size() - 1;
		int middle = right / 2;
		int pos = quickSort(nums, left, right);
		//���ַ��ҵ�����λ��Ϊmiddle��Ԫ��
		while (pos != middle)
		{
			if (pos > middle)
				right = pos - 1;
			else
				left = pos + 1;
			pos = quickSort(nums, left, right);
		}
		return nums[middle];
	}
	//һ�ο�������,����nums[left]��nums�е�����λ��
	int quickSort(vector<int> &nums, int left, int right)
	{
		int temp = nums[left];
		int i = left, j = right;
		while (i < j)
		{
			while (i < j&&nums[j] >= temp)
				--j;
			while (i < j&&nums[i] <= temp)
				++i;
			if (i < j)
				swap(nums[i], nums[j]);
		}
		nums[left] = nums[i];
		nums[i] = temp;
		return i;
	}
};
#endif