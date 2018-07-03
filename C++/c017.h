#ifndef C17_H
#define C17_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 子集
*
* 描述
* 给定一个含不同整数的集合，返回其所有的子集
* 子集中的元素排列必须是非降序的，解集必须不包含重复的子集
* 样例
* 如果 S = [1,2,3]，有如下的解：
* [
* [3],
* [1],
* [2],
* [1,2,3],
* [1,3],
* [2,3],
* [1,2],
* []
* ]
*/
bool cmp(const int a, const int b)
{
	return a > b;
}
class Solution {
public:
	/**
	* @param nums: A set of numbers
	* @return: A list of lists
	*/
	vector<vector<int>> subsets(vector<int> &nums) {
		// write your code here
		if (nums.empty())
			return{ {} };
		//构建降序数组
		sort(nums.begin(), nums.end(), cmp);
		//从数组尾部开始添加数据
		//新的res是原res再加上每个res元素加上nums的尾部
		while (!nums.empty())
		{
			if (res.empty())
			{
				res.push_back({ nums.back() });
				res.push_back({});
			}
			else
			{
				int len = res.size();
				for (int i = 0; i < len; ++i)
				{
					vector<int> temp = res[i];
					temp.push_back(nums.back());
					res.push_back(temp);
				}
			}
			nums.pop_back();
		}
		return res;
	}
	vector<vector<int>> res;
};
#endif