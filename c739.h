#ifndef C739_H
#define C739_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* Compute 24 Game
* You have 4 cards each containing a number from 1 to 9. You need to compute whether they could operated through *, /, +, -, (, ) to get the value of 24.
* The division operator / represents real division, not integer division. so 4 / (1 - 2/3) = 12.
* Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
* You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.
* 样例
* Given nums = [4, 1, 8, 7], return true // 8 * （7 - 4） * 1 = 24
* Given nums = [1, 1, 1, 2], return false
* Given nums = [3, 3, 8, 8], return true // 8 / ( 3 - 8 / 3) = 24
*/
class Solution {
public:
	/**
	* @param nums: 4 cards
	* @return: whether they could get the value of 24
	*/
	bool compute24(vector<double> &nums) {
		// write your code here
		sort(nums.begin(), nums.end());//排序获得值最小的排列
		do{
			if (isValid(nums))
				return true;
		} while (next_permutation(nums.begin(), nums.end()));//从小到大对数组进行全排列
		return false;
	}
	//考虑各种情况,重载函数求得结果
	bool isValid(vector<double> &nums)
	{
		double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
		if (isValid(a + b, c, d) || isValid(a - b, c, d) || isValid(a*b, c, d) || isValid(a / b, c, d))
			return true;
		if (isValid(a, b + c, d) || isValid(a, b - c, d) || isValid(a, b*c, d) || isValid(a, b / c, d))
			return true;
		if (isValid(a, b, c + d) || isValid(a, b, c - d) || isValid(a, b, c*d) || isValid(a, b, c / d))
			return true;
		return false;
	}
	bool isValid(double a, double b, double c)
	{
		if (isValid(a + b, c) || isValid(a - b, c) || isValid(a*b, c) || b&&isValid(a / b, c))
			return true;
		if (isValid(a, b + c) || isValid(a, b - c) || isValid(a, b*c) || c&&isValid(a, b / c))
			return true;
		return false;
	}
	bool isValid(double a, double b)
	{
		if (abs(a + b - 24.0) < 0.0001 || abs(a - b - 24.0) < 0.0001 || abs(a*b - 24.0) < 0.0001 || b&&abs(a / b - 24.0) < 0.0001)
			return true;
		return false;
	}
	
};
#endif