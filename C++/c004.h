#ifndef C004_H
#define C004_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
*丑数 II
*
* 描述
* 设计一个算法，找出只含素因子2，3，5 的第 n 小的数。
* 符合条件的数如：1, 2, 3, 4, 5, 6, 8, 9, 10, 12...
* 我们可以认为1也是一个丑数
* 样例
* 如果n = 9， 返回 10
* 挑战
* 要求时间复杂度为O(nlogn)或者O(n)
*/
class Solution {
public:
	/**
	* @param n: An integer
	* @return: the nth prime number as description.
	*/
	int nthUglyNumber(int n) {
		// write your code here
		if (n <= 0)
			return 0;
		//每个丑数都可以用2^i*3^j*5^k的形式来表示,将其排序，得到的第n个即为结果
		vector<int> nums(n, 0);
		nums[0] = 1;
		int num_2 = 0, num_3 = 0, num_5 = 0;
		for (int i = 1; i < n; ++i)
		{
			nums[i] = min(min(nums[num_2] * 2, nums[num_3] * 3), nums[num_5] * 5);
			if (nums[i] % 2 == 0)
				num_2++;
			if (nums[i] % 3 == 0)
				num_3++;
			if (nums[i] % 5 == 0)
				num_5++;
		}
		return nums[n - 1];
	}
};
#endif