#ifndef C1368_H
#define C1368_H
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
/*
* 相同数字
*
* 给一个数组，如果数组中存在相同数字，且相同数字的距离小于给定值k，输出YES，否则输出NO。
* 注意事项
* 输入的数组长度为n，保证n <= 100000。
* 数组元素的值为x，0 <= x <= 1e9。
* 输入的k满足 1 <= k < n。
* 样例
* 给出 array = [1,2,3,1,5,9,3], k = 4, 返回 "YES"。
* 解释：
* index为3的1和index为0的1距离为3，满足题意输出YES。
* 给出 array =[1,2,3,5,7,1,5,1,3], k = 4, 返回 "YES"。
* 解释：
* index为7的1和index为5的1距离为2，满足题意。
*/
class Solution {
public:
	/**
	* @param nums: the arrays
	* @param k: the distance of the same number
	* @return: the ans of this question
	*/
	string sameNumber(vector<int> &nums, int k) {
		// Write your code here
		if (nums.empty())
			return "NO";
		map<int, int> m;//存放数字及其位置
		for (int i = 0; i < nums.size(); ++i)
		{
			//如果之前出现过nums[i],若此位置和之前的位置距离小于给定值k,返回YES
			//否则,将m[nums[i]]设置为当前位置
			if (m.find(nums[i]) != m.end())
			{
				if (i - m[nums[i]] < k)
					return "YES";
				else
					m[nums[i]] = i;
			}
			else
				m[nums[i]] = i;
		}
		return "NO";
	}
};
#endif