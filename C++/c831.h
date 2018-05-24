#ifndef C831_H
#define C831_H
#include<iostream>
#include<cmath>
#include<set>
#include<vector>
using namespace std;
/*
* 三数之和 II
*
* 输入n，求所有符合x^2+y^2+z^2 = n的 x, y, z 的方案数。(x, y, z为非负整数)
* 注意事项
* n <= 1000000
* x,y,z满足(x<=y<=z)，只要选择出来的三个数相同就算同一种方案。
* 样例
* 给出 n = 0，返回 1。
* 解释：
* 当 x = 0 , y = 0, z = 0时等式成立。
* 给出 n = 1，返回 1。
* 解释：
* 当其中一个为1，剩下两个为0，一共有1种方案。
*/
class Solution {
public:
	/**
	* @param n: an integer
	* @return: the number of solutions
	*/
	int threeSum2(int n) {
		// Write your code here
		vector<int> nums;
		set<vector<int>> set;
		//找到0-n之前的完全平方数，存入数组nums
		for (int i = 0; i <= sqrt(n); ++i)
			nums.push_back(i*i);
		int size = nums.size();
		//求三数之和
		for (int i = 0; i < size; ++i)
		{
			for (int j = size - 1; j >= i; --j)
			{
				for (int k = i; k <= j; ++k)
				{
					if (nums[i] + nums[k] + nums[j] == n)
						set.insert({ nums[i], nums[k], nums[j] });
				}
			}
		}
		return set.size();
	}
};
#endif