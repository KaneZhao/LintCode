#ifndef C005_H
#define C005_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 第k大元素
*
* 在数组中找到第k大的元素
* 你可以交换数组中的元素的位置
* 样例
* 给出数组 [9,3,2,4,8]，第三大的元素是 4
* 给出数组 [1,2,3,4,5]，第一大的元素是 5，第二大的元素是 4，第三大的元素是 3，以此类推
* 挑战
* 要求时间复杂度为O(n)，空间复杂度为O(1)
*/
class Solution {
public:
	/*
	* @param n: An integer
	* @param nums: An array
	* @return: the Kth largest element
	*/
	int kthLargestElement(int n, vector<int> &nums) {
		// write your code here
		if (nums.empty() || n <= 0)
			return 0;
		int min = INT_MAX;
		for (auto c : nums)
		{
			if (c < min)
				min = c;
		}
		//当n>=len时,第n大的元素为nums的最小元素
		int len = nums.size();
		if (n >= len)
			return min;
		int left = 0, right = nums.size() - 1;
		int pos = quickSort(nums, left, right);
		//第n大元素也就是nums排序后的第len-n+1个元素
		//利用二分法求第k+1个元素
		int k = len - n;
		while (pos != k)
		{
			if (pos > k)
			{
				right = pos - 1;
				pos = quickSort(nums, left, right);
			}
			else
			{
				left = pos + 1;
				pos = quickSort(nums, left, right);
			}
		}
		return nums[k];
	}
	//对于数组区间[left,right]进行快排,并返回nums[left]排序后的位置
	int quickSort(vector<int> &nums, int left, int right)
	{
		int temp = nums[left];
		int i = left, j = right;
		while (i < j)
		{
			while ( i < j && nums[j]>= temp)
				--j;
			while ( i < j && nums[i] <= temp)
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