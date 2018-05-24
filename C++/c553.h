#ifndef C553_H
#define C553_H
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
* 炸弹袭击
*
* 描述
* 给一个二维矩阵, 每一个格子都可能是一堵墙 W, 一个敌人 E 或者空 0 (数字 '0'), 返回你可以用一个炸弹杀死的最大敌人数. 炸弹会杀死所有在同一行和同一列没有墙阻隔的敌人, 因为墙比较坚固难以摧毁.
* 你只能在空的地方放置炸弹.
* 样例
* 给一个矩阵:
* 0 E 0 0
* E 0 W E
* 0 E 0 0
* 返回 3.(在（1, 1）处放炸弹可以杀死 3 个敌人)
*/
class Solution {
public:
	/**
	* @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
	* @return: an integer, the maximum enemies you can kill using one bomb
	*/
	int maxKilledEnemies(vector<vector<char>> &grid) {
		// write your code here
		if (grid.empty() || grid[0].empty())
			return 0;
		int rows = grid.size();
		int cols = grid[0].size();
		//up[i][j],down[i][j],left[i][j],right[i][j]分别表示grid[i-1][j-1]上下左右四个方向上可以杀死的敌人数
		vector<vector<int>> 
			left(rows + 2, vector<int>(cols + 2, 0)),
			right(rows + 2, vector<int>(cols + 2, 0)),
			up(rows + 2, vector<int>(cols + 2, 0)),
			down(rows + 2, vector<int>(cols + 2, 0));
		//left[i][j]表示在grid[i-1][j-1]放置炸弹,向左可以杀死的最大敌人数
		//假设E也可以放置炸弹,当前元素为E,可以杀死的敌人数加一
		//当前元素为W,不能放置炸弹,可以杀死的人数为0
		//当前元素为0,可以杀死的人数不变
		for (int i = 1; i <= rows; ++i)
		{
			for (int j = 1; j <= cols; ++j)
			{
				if (grid[i - 1][j - 1] == 'E')
					left[i][j] = left[i][j - 1] + 1;
				else if (grid[i - 1][j - 1] == 'W')
					left[i][j] = 0;
				else
					left[i][j] = left[i][j - 1];
			}
		}
		//right[i][j]表示在grid[i - 1][j - 1]放置炸弹, 向右可以杀死的最大敌人数
		for (int i = 1; i <= rows; ++i)
		{
			for (int j = cols; j >= 1; --j)
			{
				if (grid[i - 1][j - 1] == 'E')
					right[i][j] = right[i][j + 1] + 1;
				else if (grid[i - 1][j - 1] == 'W')
					right[i][j] = 0;
				else
					right[i][j] = right[i][j + 1];
			}
		}
		//up[i][j]表示在grid[i-1][j-1]放置炸弹,向上可以杀死的最大敌人数
		for (int j = 1; j <= cols; ++j)
		{
			for (int i = 1; i <= rows; ++i)
			{
				if (grid[i - 1][j - 1] == 'E')
					up[i][j] = up[i-1][j] + 1;
				else if (grid[i - 1][j - 1] == 'W')
					up[i][j] = 0;
				else
					up[i][j] = up[i - 1][j];
			}
		}
		//down[i][j]表示在grid[i-1][j-1]放置炸弹,向下可以杀死的最大敌人数
		for (int j = 1; j <= cols; ++j)
		{
			for (int i = rows; i >= 1; --i)
			{
				if (grid[i - 1][j - 1] == 'E')
					down[i][j] = down[i + 1][j] + 1;
				else if (grid[i - 1][j - 1] == 'W')
					down[i][j] = 0;
				else
					down[i][j] = down[i + 1][j];
			}
		}
		int res = 0;
		//仅在grid[i-1][j-1]为0时计算其上下左右可以杀死敌人的总数
		for (int i = 1; i <= rows; ++i)
		{
			for (int j = 1; j <= cols; ++j)
			{
				if (grid[i - 1][j - 1] == '0')
				{
					res = max(res, left[i][j] + right[i][j] + up[i][j] + down[i][j]);
				}
			}
		}
		return res;
	}
};
#endif