#ifndef C843_H
#define C843_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 数字翻转
*
* 给你一个01构成的数组。请你找出最小翻转步数，使得数组满足以下规则：
* 1的后面可以是1或者0，但是0的后面必须是0。
* 注意事项
* 输入的数组长度n <= 100000。
* 样例
* 给出 array = [1,0,0,1,1,1] , 返回2。
* 解释：
* 把两个0翻转成1。
* 给出 array = [1,0,1,0,1,0] , 返回2。
* 解释：
* 把第二个1和第三个1都翻转成0。
*/
class Solution {
public:
	/**
	* @param nums: the array
	* @return: the minimum times to flip digit
	*/
	int flipDigit(vector<int> &nums) {
		// Write your code here
		int numOne = 0;
		int preOne = 0, res = nums.size();
		for (auto c : nums)
		{
			if (c == 1)
				numOne++;
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == 1)
				preOne++;
			res = minVal(res, numOne - preOne + i + 1 - preOne);
		}
		return res;
	}
	int minVal(int a, int b)
	{
		return a < b ? a : b;
	}
};
#endif