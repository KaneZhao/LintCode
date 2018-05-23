#ifndef C80_H
#define C80_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 中位数
* 
* 描述
* 给定一个未排序的整数数组，找到其中位数。
* 中位数是排序后数组的中间值，如果数组的个数是偶数个，则返回排序后数组的第N/2个数。
* 样例
* 给出数组[4, 5, 1, 2, 3]， 返回 3
* 给出数组[7, 9, 4, 5]，返回 5
* 挑战
* 时间复杂度为O(n)
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
		//二分法找到最终位置为middle的元素
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
	//一次快速排序,返回nums[left]在nums中的最终位置
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