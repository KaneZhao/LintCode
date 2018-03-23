#ifndef C943_H
#define C943_H
#include<iostream>
#include<vector>
using namespace std;
/*
* Range Sum Query - Immutable
*
* Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
* 注意事项
* You may assume that the array does not change.
* There are many calls to sumRange function.
* 样例
* Given nums = [-2, 0, 3, -5, 2, -1]
* sumRange(0, 2) -> 1
* sumRange(2, 5) -> -1
* sumRange(0, 5) -> -3
*/
class NumArray {
public:
	NumArray(vector<int> nums) {
		//res[i]存放从nums[0]到nums[i]的和
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i == 0)
				res.push_back(nums[i]);
			else
				res.push_back(nums[i] + res[i - 1]);
		}
	}

	int sumRange(int i, int j) {
		if (i < 0 || j >= res.size())
			return 0;
		if (i == 0)
			return res[j];
		else
			return res[j] - res[i - 1];
	}
	vector<int> res;
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* int param_1 = obj.sumRange(i,j);
*/
#endif