#ifndef C47_H
#define C47_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 主元素 II
*
* 给定一个整型数组，找到主元素，它在数组中的出现次数严格大于数组元素个数的三分之一。
* 注意事项
* 数组中只有唯一的主元素
* 样例
* 给出数组[1,2,1,2,1,3,3] 返回 1
* 挑战
* 要求时间复杂度为O(n)，空间复杂度为O(1)。
*/
class Solution {
public:
	int majorityNumber(vector<int> nums) {
		if (nums.empty())
			return -1;
		int size = nums.size();
		if (size <= 2)
			return nums[0];
		int temp1 = INT_MIN, temp2 = INT_MIN;
		int cnt1 = 0, cnt2 = 0;
		//如果找到三个不一样的数,就抵消
		for (int i = 0; i < size; ++i)
		{
			if (cnt1 == 0&&nums[i]!=temp2)
			{
				temp1 = nums[i];
				cnt1++;
				continue;
			}
			if (cnt2 == 0&&nums[i]!=temp1)
			{
				temp2 = nums[i];
				cnt2++;
				continue;
			}
			if (nums[i] != temp1&&nums[i] != temp2)
			{
				cnt1--;
				cnt2--;
			}
			else
			{
				if (nums[i] == temp1)
					cnt1++;
				else
					cnt2++; 
			}
		}
		//从temp1和temp2中选择出现次数较多的那个
		cnt1 = 0, cnt2 = 0;
		for (auto c : nums)
		{
			if (c == temp1)
				cnt1++;
			else if (c == temp2)
				cnt2++;
		}
		return cnt1 > cnt2 ? temp1 : temp2;
	}
};
#endif