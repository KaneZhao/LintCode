#ifndef C433_H
#define C433_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
* 岛屿的个数
*
* 给一个01矩阵，求不同的岛屿的个数。
* 0代表海，1代表岛，如果两个1相邻，那么这两个1属于同一个岛。我们只考虑上下左右为相邻。
* 样例
* 在矩阵：
* [
* [1, 1, 0, 0, 0],
* [0, 1, 0, 0, 1],
* [0, 0, 0, 1, 1],
* [0, 0, 0, 0, 0],
* [0, 0, 0, 0, 1]
* ]
* 中有 3 个岛.
*/
class Solution {
public:
	/*
	* @param grid: a boolean 2D matrix
	* @return: an integer
	*/
	int numIslands(vector<vector<bool>> &grid) {
		// write your code here
		if (grid.empty())
			return 0;
		int row = grid.size();
		int col = grid[0].size();
		int num = 0;
		map<int, int> visited;
		vector<vector<int>> dic{ { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };//方便计算位置
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (grid[i][j] == 1 && visited.find(i*col + j) == visited.end())//当目前是岛屿，且不与已知的岛屿相连
				{
					num++;
					visit(grid, i, j, visited,dic);
				}
			}
		}
		return num;
	}
	void visit(vector<vector<bool>> &grid, int i, int j,map<int,int> &visited,vector<vector<int>> dic)
	{
		int row = grid.size();
		int col = grid[0].size();
		if (i < 0 || j < 0 || i >= row || j >= col)//防止数组越界
			return;
		if (visited[i*col + j] == 1||grid[i][j]==0)//对于已经访问过的岛屿和非岛屿，直接返回
			return;
		visited[i*col + j] = 1;
		for (auto c : dic)  //计算当前岛屿上下左右四个位置的岛屿
		{
			int x = i + c[0];
			int y = j + c[1];
			visit(grid, x, y, visited,dic);//递归
		}
	}
};
#endif