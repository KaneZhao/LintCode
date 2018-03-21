#ifndef C897_H
#define C897_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
* 海岛城市
*
* Given a matrix of size n x m, the elements in the matrix are 0、1、2. 0 for the sea, 1 for the island, and 2 for the city on the island(You can assume that 2 is built on 1, ie 2 also represents the island).
* If two 1 are adjacent, then these two 1 belong to the same island. Find the number of islands with at least one city.
* 注意事项
* 我们只考虑上下左右为相邻。
* n <= 100，m <= 100。
* 你可以假设矩阵的四个边都被海包围。
*/
class Solution {
public:
	/**
	* @param grid: an integer matrix
	* @return: an integer
	*/
	int numIslandCities(vector<vector<int>> &grid) {
		// Write your code here
		if (grid.empty() || grid[0].empty())
			return 0;
		int rows = grid.size();
		int cols = grid[0].size();
		int res = 0;
		map<int, int> visited;
		vector<vector<int>> dic{ { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				//当grid[i][j]=2时开始计数
				if (grid[i][j] == 2 && visited.find(i*cols + j) == visited.end())
				{
					res++;
					visit(grid, i, j, visited, dic);
				}
			}
		}
		return res;
	}
	//递归求解
	void visit(vector<vector<int>> &grid, int i, int j, map<int, int> &visited, vector<vector<int>> dic)
	{
		int rows = grid.size();
		int cols = grid[0].size();
		if (i < 0 || i >= rows || j < 0 || j >= cols)
			return;
		if (visited[i*cols + j] == 1 || grid[i][j] == 0)
			return;
		visited[i*cols + j] = 1;
		for (auto c : dic)
		{
			int x = i + c[0];
			int y = j + c[1];
			visit(grid, x, y, visited, dic);
		}
	}
};
#endif