#ifndef C48_H
#define C48_H
#include<vector>
#include<iostream>
#include<map>
using namespace std;
/*
* 主元素 III
*
* 给定一个整型数组，找到主元素，它在数组中的出现次数严格大于数组元素个数的1/k。
* 注意事项
* 数组中只有唯一的主元素
* 样例
* 给出数组 [3,1,2,3,2,3,3,4,4,4] ，和 k = 3，返回 3
* 挑战
* 要求时间复杂度为O(n)，空间复杂度为O(k)
*/
class Solution {
public:
	int majorityNumber(vector<int> nums, int k) {
		map<int, int> m;
		int size = nums.size();
		//找到k个不同的数就抵消
		for (int i = 0; i < size; ++i)
		{
			if (m.size() < k)
			{
				m[nums[i]]++;			
			}
			else
			{
				if (m.find(nums[i]) != m.end())
					m[nums[i]]++;
				else
				{
					for (auto &c : m)
					{
						c.second--;
					}
					for (auto it = m.begin(); it != m.end();)
					{
						if (it->second <= 0)
						{
							m.erase(it++);
						}
						else
						{
							it++;
						}
					}
				}
			}
		}
		for (auto &c : m)
		{
			c.second = 0;
		}
		for (auto t : nums)
		{
			if (m.find(t) != m.end())
				m[t]++;
		}
		int res = 0;
		int cnt = INT_MIN;
		for (auto c : m)
		{
			if (cnt < c.second)
			{
				cnt = c.second;
				res = c.first;
			}
		}
		return res;
	}
};
#endif