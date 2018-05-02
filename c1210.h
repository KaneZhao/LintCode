#ifndef C1210_H
#define C1210_H
#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
* Increasing Subsequences
*
* Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .
* 注意事项
* 1.The length of the given array will not exceed 15.
* 2.The range of integer in the given array is [-100,100].
* 3.The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
* 样例
* Input: [4, 6, 7, 7]
* Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
*/
class Solution {
public:
	/**
	* @param nums: an integer array
	* @return: all the different possible increasing subsequences of the given array
	*/
	vector<vector<int>> findSubsequences(vector<int> &nums) {
		// Write your code here
		vector<vector<int>> res;
		if (nums.empty() || nums.size() == 1)
			return res;
		int len = nums.size();
		vector<set<vector<int>>> v(len);//v[i]存放以nums[i]结尾的所有递增子数组
		for (int i = 1; i < len; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				//对于i,从j=i-1开始向前寻找nums[j]<=nums[i]
				//如果nums[j]小于nums[i],可以将{nums[j],nums[i]}添加到v[i]
				//并将v[j]中的子数组都添加nums[j],之后添加到v[i]中
				//若nums[j]等于nums[i],不再向前寻找避免重复
				if (nums[j] <= nums[i])
				{
				    v[i].insert({ nums[j], nums[i] });
					for (auto c : v[j])
					{
						vector<int> temp = c;
						temp.push_back(nums[i]);
						v[i].insert(temp);
					}
					if (nums[j] == nums[i])
					{
						break;
					}
				}
			}
		}
		for (auto c : v)
		{
			for (auto t : c)
			{
				res.push_back(t);
			}
		}
		return res;
	}
};
#endif