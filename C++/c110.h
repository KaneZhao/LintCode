#ifndef C110_H
#define C110_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 最小路径和
* 给定一个只含非负整数的m*n网格，找到一条从左上角到右下角的可以使数字和最小的路径。
* 注意事项
* 你在同一时间只能向下或者向右移动一步
*/
class Solution {
public:
	/**
	* @param grid: a list of lists of integers.
	* @return: An integer, minimizes the sum of all numbers along its path
	*/
	int minPathSum(vector<vector<int> > &grid) {
		// write your code here
		if (grid.empty()||grid[0].empty())
			return 0;
		int row = grid.size();
		int col = grid[0].size();
		for (int i = 1; i < row; ++i)
			grid[i][0] += grid[i - 1][0];
		for (int j = 1; j < col; ++j)
			grid[0][j] += grid[0][j - 1];
		for (int i = 1; i < row; ++i)
		{
			for (int j = 1; j < col; ++j)
			{
				grid[i][j] += minVal(grid[i - 1][j], grid[i][j - 1]);
			}
		}
		return grid[row - 1][col - 1];
	}
	int minVal(int a, int b)
	{
		return a < b ? a : b;
	}
};

#endif