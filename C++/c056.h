#ifndef C56_H
#define C56_H
#include<vector>
#include<iostream>
#include<map>
using namespace std;
/*
* 两数之和
*
* 给一个整数数组，找到两个数使得他们的和等于一个给定的数 target。
* 你需要实现的函数twoSum需要返回这两个数的下标, 并且第一个下标小于第二个下标。注意这里下标的范围是 0 到 n-1。
* 注意事项
* 你可以假设只有一组答案。
* 样例
* 给出 numbers = [2, 7, 11, 15], target = 9, 返回 [0, 1].
*/
class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target) {
		// write your code here
		vector<int> res{-1,-1};
		map<int, int> map;//存放元素和下标
		//遍历数组,若Map中存在于元素之和为target的数,将其存入res中
		//若没有,则将元素和下标存入map
		for (int i = 0; i < nums.size(); ++i)
		{
			if (map.find(target - nums[i]) != map.end())
			{
				res[0] = map[target - nums[i]];
				res[1] = i;
				break;
			}
			map[nums[i]] = i;
		}
		return res;
	}
};
#endif