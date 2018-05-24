#ifndef C57_H
#define C57_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
/*
* 三数之和
*
* 给出一个有n个整数的数组S，在S中找到三个整数a, b, c，找到所有使得a + b + c = 0的三元组。
* 注意事项
* 在三元组(a, b, c)，要求a <= b <= c。
* 结果不能包含重复的三元组。
* 样例
* 如S = {-1 0 1 2 -1 -4}, 你需要返回的三元组集合的是：
* (-1, 0, 1)
* (-1, -1, 2)
*/
class Solution {
public:
	/**
	* @param numbers: Give an array numbers of n integer
	* @return: Find all unique triplets in the array which gives the sum of zero.
	*/
	vector<vector<int>> threeSum(vector<int> &numbers) {
		// write your code here
		vector<vector<int>> res;
		set<vector<int>> set;
		sort(numbers.begin(), numbers.end());
		for (int i = 0; i < numbers.size() - 2; ++i)
		{
			for (int j = numbers.size() - 1; j>i + 1; --j)
			{
				for (int k = i + 1; k < j; ++k)
				{
					//存入set中防止重复
					if (numbers[i] + numbers[k] + numbers[j] == 0)
						set.insert({ numbers[i], numbers[k], numbers[j] });
				}
			}
		}
		for (auto it = set.begin(); it != set.end(); ++it)
			res.push_back(*it);
		return res;
	}
};
#endif