#ifndef C824_H
#define C824_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 落单的数 IV
*
* 给定数组，除了一个数出现一次外，所有数都出现两次，并且所有出现两次的数都挨着。请找出找出那个出现一次的数。
* 注意事项
* 1 <= nums.length < 10^4
* 为了约束程序的时间复杂度，你的程序将会运行 10^5 次
* 样例
* 给出 nums = [3,3,2,2,4,5,5], 返回 4。
* 解释：
* 4 只出现了一次。
* 给出 nums = [2,1,1,3,3], 返回 2。
* 解释：
* 2 只出现了一次。
*/
class Solution {
public:
	/**
	* @param nums: The number array
	* @return: Return the single number
	*/
	int getSingleNumber(vector<int> &nums) {
		// Write your code here
		int left = 0, right = nums.size() - 1;
		while (left<right)
		{
			int middle = (left + right) / 2;
			if (nums[middle] == nums[middle - 1])
			{
				//若中间位置的数和它后面的数相等,根据奇偶性进行判断
				//中间位置前有偶数个数,则目标数字出现在中间位置右边,否则出现在左边
				if ((middle - left) % 2 == 0)
				{
					right = middle - 2;
				}
				else
				{
					left = middle + 1;
				}
			}
			else if (nums[middle] == nums[middle + 1])
			{
				//若中间位置的数和它前面的数相等,根据奇偶性进行判断
				//中间位置前有偶数个数,则目标数字出现在中间位置左边,否则出现在右边
				if ((middle - left) % 2 == 0)
				{
					left = middle + 2;
				}
				else
				{
					right = middle - 1;
				}
			}
			else
			{
				//直接找到目标数字
				return nums[middle];
			}
		}
		return nums[left];
	}
};
#endif