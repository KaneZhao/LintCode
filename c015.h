#ifndef C15_H
#define C15_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 全排列
*
* 给定一个数字列表，返回其所有可能的排列。
* 注意事项
* 你可以假设没有重复数字。
* 样例
* 给出一个列表[1,2,3]，其全排列为：
* [
* [1,2,3],
* [1,3,2],
* [2,1,3],
* [2,3,1],
* [3,1,2],
* [3,2,1]
* ]
*/
class Solution {
public:
	/*
	* @param nums: A list of integers.
	* @return: A list of permutations.
	*/
	vector<vector<int>> permute(vector<int> &nums) {
		// write your code here
		vector<vector<int>> res;
		if (nums.empty())
			return{ {} };
		//先将nums置为值最小的排列
		sort(nums.begin(), nums.end());
		res.push_back(nums);
		int pos = 0;
		//在nums不是递减序列时
		//从后先前寻找第一个大于nums[pos]的位置temp,交换nums[pos]和nums[temp]
		//之后将nums[pos+1]及以后的序列逆序
		while (hasNext(nums, pos))
		{
			int val = nums[pos];
			int temp = 0;
			for (int i = nums.size() - 1; i >= 0; --i)
			{
				if (nums[i] > val)
				{
					temp = i;
					break;
				}
			}
			swap(nums[pos], nums[temp]);
			reverse(nums.begin() + pos + 1, nums.end());
			res.push_back(nums);
		}
		return res;
	}
	//判断排列是否是递减
	//如果是递减序列,此排列没有下一个比它大的排列,返回false
	//否则,从后向前寻找第一个nums[i-1]<nums[i]的位置,并将位置i - 1赋值给pos
	bool hasNext(vector<int> &nums,int &pos)
	{
		int i = nums.size() - 1;
		while (i > 0)
		{
			if (nums[i] > nums[i - 1])
			{
				pos = i - 1;
				return true;
			}
			--i;
		}
		return false;
	}
};
class Solution2 {
public:
	/*
	* @param nums: A list of integers.
	* @return: A list of permutations.
	*/
	vector<vector<int>> permute(vector<int> &nums) {
		// write your code here
		if (nums.empty())
			return{ {} };
		helper(nums, 0);
		return res;
	}
	void helper(vector<int> &nums, int start)
	{
		if (start == nums.size())
		{
			res.push_back(nums);
		}
		for (int i = start; i < nums.size(); ++i)
		{
			swap(nums[start], nums[i]);
			helper(nums, start + 1);
			swap(nums[start], nums[i]);
		}
	}
	vector<vector<int>> res;
};
#endif
