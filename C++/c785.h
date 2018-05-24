#ifndef C785_H
#define C785_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 最大权值和路径
*
* 有一个机器人位于一个 m × n 个网格的右上角。
* 机器人每一时刻只能向下或者向左移动一步。机器人试图达到网格的左下角。每个网格上有一个数字权值，机器人希望它走到左下角的路径权值和最大。
* 问这个最大路径权值和是多少？
* 注意事项
* 输入一个n x m 的矩阵，保证 n <= 200,m <= 200。
* 题目数据保证 0 <= i <= n-1 , 0 <= j <= m-1, nums[i][j] <= 100000。
* 样例
* 给出
* [
* [1,2,3,4],
* [3,5,6,7],
* [9,10,1,2],
* [4,4,5,5]
* ]
* ，返回45。
* 解释：
* 从右上角出发，沿着[4,7,6,5,10,9,4]走到左下角。权值和为45。
*/
class Solution {
public:
	/**
	* @param nums:
	* @param k:
	* @return: nothing
	*/
	int MaxWeight(vector<vector<int>> &nums, int k) {
		// 
		if (nums.empty() || nums[0].empty())
			return 0;
		int row = nums.size(), col = nums[0].size();
		for (int i = col - 2; i >= 0; --i)
			nums[0][i] += nums[0][i + 1];
		for (int i = 1; i < row; ++i)
			nums[i][col - 1] += nums[i - 1][col - 1];
		for (int i = 1; i < row; ++i)
		{
			for (int j = col - 2; j >= 0; --j)
			{
				nums[i][j] += maxVal(nums[i - 1][j], nums[i][j + 1]);
			}
		}
		return nums[row - 1][0];
	}
	int maxVal(int a, int b)
	{
		return a>b ? a : b;
	}
};
#endif