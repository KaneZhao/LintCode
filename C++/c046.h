#ifndef C46_H
#define C46_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 主元素
*
* 给定一个整型数组，找出主元素，它在数组中的出现次数严格大于数组元素个数的二分之一。
* 注意事项
* You may assume that the array is non-empty and the majority number always exist in the array.
* 样例
* 给出数组[1,1,1,1,2,2,2]，返回 1
* 挑战
* 要求时间复杂度为O(n)，空间复杂度为O(1)
*/
class Solution {
public:
	int majorityNumber(vector<int> &nums) {
		// write your code here
		int size = nums.size();
		int temp = nums[0];
		int cnt = 1;
		for (int i = 1; i < size; ++i)
		{
			//当cnt为0,将temp置为当前元素
			if (cnt == 0)
				temp = nums[i];
			//若当前元素等于temp,cnt++;否则,抵消,cnt--
			if (nums[i] == temp)
				cnt++;
			else
				cnt--;
		}
		return temp;
	}
};
#endif