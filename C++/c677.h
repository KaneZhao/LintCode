#ifndef C677_H
#define C677_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
* 大岛的数量
*
* 给一个布尔类型的二维数组, 0 表示海, 1 表示岛。如果两个1是相邻的,那么我们认为他们是同一个岛.我们只考虑 上下左右 相邻.
* 找到大小在 k 及 k 以上的岛屿的数量
* 样例
* 给一个二维数组:
* [
* [1, 1, 0, 0, 0],
* [0, 1, 0, 0, 1],
* [0, 0, 0, 1, 1],
* [0, 0, 0, 0, 0],
* [0, 0, 0, 0, 1]
* ]
给出 K = 2
返回 2
*/
class Solution {
public:
	/**
	* @param grid: a 2d boolean array
	* @param k: an integer
	* @return: the number of Islands
	*/
	int numsofIsland(vector<vector<bool>> &grid, int k) {
		// Write your code here
		if (grid.empty() || grid[0].empty())
			return 0;
		int rows = grid.size();
		int cols = grid[0].size();
		int res = 0;
		map<int, int> visited;
		vector<vector<int>> dic{ { 0, -1 }, { 0, 1 }, { 1, 0 }, { -1, 0 } };
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (grid[i][j] && visited.find(i*cols + j) == visited.end() && helper(grid, i, j, visited, dic) >= k)
					++res;
			}
		}
		return res;
	}
	int helper(vector<vector<bool>> &grid, int i, int j, map<int, int>& visited, vector<vector<int>> dic)
	{
		int rows = grid.size();
		int cols = grid[0].size();
		if (i < 0 || i >= rows || j < 0 || j >= cols)
			return 0;
		if (!grid[i][j] || visited[i*cols + j] == 1)
			return 0;
		visited[i*cols + j] = 1;
		int num = 1;
		for (auto c : dic)
		{
			int x = i + c[0];
			int y = j + c[1];
			num += helper(grid, x, y, visited, dic);
		}
		return num;
	}
};
#endif