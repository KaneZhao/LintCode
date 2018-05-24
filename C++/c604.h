#ifndef C604_H
#define C604_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 滑动窗口内数的和
*
* 给你一个大小为n的整型数组和一个大小为k的滑动窗口，将滑动窗口从头移到尾，输出从开始到结束每一个时刻滑动窗口内的数的和。
* 样例
* 对于数组 [1,2,7,8,5] ，滑动窗口大小k= 3 。
* 1 + 2 + 7 = 10
* 2 + 7 + 8 = 17
* 7 + 8 + 5 = 20
* 返回 [10,17,20]
*/
class Solution {
public:
	/**
	* @param nums: a list of integers.
	* @param k: length of window.
	* @return: the sum of the element inside the window at each moving.
	*/
	vector<int> winSum(vector<int> &nums, int k) {
		// write your code here
		vector<int> res;
		//若nums为空或k<=0,返回空
		if (nums.empty() || k <= 0)
			return res;
		int sum = 0;
		for (int i = 0; i < k; ++i)
			sum += nums[i];
		res.push_back(sum);
		//由于滑动窗口,sum减去nums[j-1]加上nums[j+k-1]就是现在窗口内的元素之和
		for (int j = 1; j + k - 1 < nums.size(); ++j)
		{
			sum -= nums[j - 1];
			sum += nums[j + k - 1];
			res.push_back(sum);
		}
		return res;
	}
};
#endif