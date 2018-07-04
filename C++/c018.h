#ifndef C18_H
#define C18_H
#include<vector>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(const int a, const int b)
{
	return a > b;
}
class Solution {
public:
	/**
	* @param nums: A s of numbers.
	* @return: A list of lists. All valid subss.
	*/
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		// write your code here
		if (nums.empty())
			return{ {} };
		//对nums排序使其单调不增
		sort(nums.begin(), nums.end(), cmp);
		//处理nums的末尾元素,当s和res为空时,添加{},{nums.back()}
		//当s不为空,遍历res,将nums.back()添加到元素并将元素添加到res
		while (!nums.empty())
		{
			if (s.empty())
			{
				s.insert({});
				s.insert({ nums.back() });
				res.push_back({});
				res.push_back({ nums.back() });
			}
			else
			{
				int len = res.size();
				for (int i = 0; i < len; ++i)
				{
					vector<int> temp = res[i];
					temp.push_back(nums.back());
					if (s.find(temp) == s.end())
					{
						res.push_back(temp); 
						s.insert(temp);
					}
				}
			}
			nums.pop_back();
		}
		return res;
	}
	set<vector<int>> s;//存放已经出现的结果
	vector<vector<int>> res;//存放最终结果
};


#endif