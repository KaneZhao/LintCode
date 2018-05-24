#ifndef C058_H
#define C058_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
/*
* 四数之和
*
* 给一个包含n个数的整数数组S，在S中找到所有使得和为给定整数target的四元组(a, b, c, d)。
* 注意事项
* 四元组(a, b, c, d)中，需要满足a <= b <= c <= d
* 答案中不可以包含重复的四元组。
* 样例
* 例如，对于给定的整数数组S=[1, 0, -1, 0, -2, 2] 和 target=0. 满足要求的四元组集合为：
* (-1, 0, 0, 1)
* (-2, -1, 1, 2)
* (-2, 0, 0, 2)
*/
class Solution {
public:
	/**
	* @param numbers: Give an array
	* @param target: An integer
	* @return: Find all unique quadruplets in the array which gives the sum of zero
	*/
	vector<vector<int>> fourSum(vector<int> &numbers, int target) {
		// write your code here
		vector<vector<int>> res;
		set<vector<int>> set;
		if (numbers.empty() || numbers.size() < 4)
			return res;
		int size = numbers.size();
		sort(numbers.begin(), numbers.end());
		for (int i = 0; i < size - 3; ++i)
		{
			for (int j = i + 1; j < size -2; ++j)
			{
				int k = j + 1, l = size - 1;
				while (k < l)
				{
					int sum = numbers[i] + numbers[k] + numbers[l] + numbers[j];
					if (sum == target)
					{
						set.insert({ numbers[i], numbers[j], numbers[k], numbers[l] });
						++k;
						--l;
					}
					else if (sum>target)
						--l;
					else
						++k;
				}
				
			}
		}
		for (auto it = set.begin(); it != set.end(); ++it)
			res.push_back(*it);
		return res;
	}
};
#endif