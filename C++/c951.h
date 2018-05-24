#ifndef C951_H
#define C951_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 重排
*
* 给一列数组要求重排，必须所有偶数位上的数都小于所有奇数位上的数。同时，偶数位上的数也按照升序排序，奇数位上的也按照升序排序。
* 注意事项
* 数组长度为n，n <= 100000。
* 数组下标从0开始。
* 样例
* 给出array = [-1,0,1,-1,5,10], 返回 [-1,1,-1,5,0,10]。
* 解释：
* [[-1,1,-1,5,0,10]满足条件。
* 给出array = [2,0,1,-1,5,10], 返回 [-1,2,0,5,1,10]。
* 解释：
* [-1,2,0,5,1,10]满足条件。
*/
class Solution {
public:
	/**
	* @param nums: the num arrays
	* @return: the num arrays after rearranging
	*/
	vector<int> rearrange(vector<int> &nums) {
		// Write your code here 
		if (nums.empty())
			return nums;
		sort(nums.begin(), nums.end());
		//将较小数放置与偶数位置,较大数放置于奇数位置
		int i = 1, j = nums.size() % 2 == 0 ? nums.size() - 2 : nums.size() - 1;
		while (i<j)
		{
			swap(nums[i], nums[j]);
			i += 2;
			j -= 2;
		}
		//对数组的奇数位置和偶数位置分别进行排序
		quickSort(nums, 0, nums.size() % 2 == 0 ? nums.size() - 2 : nums.size() - 1);
		quickSort(nums, 1, nums.size() % 2 == 0 ? nums.size() - 1 : nums.size() - 2);
		return nums;
	}
	//对数组中隔一个元素进行快排
	void quickSort(vector<int> &nums, int left, int right)
	{
		if (left > right)
			return;
		int i = left, j = right, temp = nums[left];
		while (i < j)
		{
			while (i < j&&nums[j] >= temp)
				j -= 2;
			while (i < j&&nums[i] <= temp)
				i += 2;
			if (i < j)
			{
				nums[i] ^= nums[j];
				nums[j] ^= nums[i];
				nums[i] ^= nums[j];
			}
		}
		nums[left] = nums[i];
		nums[i] = temp;
		quickSort(nums, left, i - 2);
		quickSort(nums, i + 2, right);
	}
};
#endif