#ifndef C860_H
#define C860_H
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
/*
* Number of Distinct Islands
*
* Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
* Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.
* Notice that:
* 11
* 1
* and
* 1
* 11
* are considered different island shapes, because we do not consider reflection / rotation.
* 注意事项
* The length of each dimension in the given grid does not exceed 50.
* 样例
* Given grid =
* [
* [1,1,0,0,0],
* [1,1,0,0,0],
* [0,0,0,1,1],
* [0,0,0,1,1]
* ]
* return 1
* Given grid =
* [
* [1,1,0,1,1],
* [1,0,0,0,0],
* [0,0,0,0,1],
* [1,1,0,1,1]
* ]
* return 3
*/
class Solution {
public:
	/**
	* @param grid: a list of lists of integers
	* @return: return an integer, denote the number of distinct islands
	*/
	int numberofDistinctIslands(vector<vector<int>> &grid) {
		// write your code here
		if (grid.empty() || grid[0].empty())
			return 0;
		int rows = grid.size();
		int cols = grid[0].size();
		vector<vector<int>> dic{ { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
				map<int, int> visited;
		set<string> island;
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (grid[i][j] == 1 && visited.find(i*cols + j) == visited.end())
				{
					vector<pair<int, int>> pos;
					helper(i, j, grid, dic, pos, visited);
					//可由平移得到的岛屿其字符串是相同的
					island.insert(build(pos, cols));
				}
			}
		}
		return island.size();
	}
	//对位置(i,j)判断其是否为岛屿,并找到包含它的最大岛屿,位置是否被访问存放在visited中,岛屿的位置存放在pos中
	void helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dic,vector<pair<int,int>> &pos, map<int, int> &visited)
	{
		int rows = grid.size();
		int cols = grid[0].size();
		if (i < 0 || i >= rows || j < 0 || j >= cols)
			return ;
		if (grid[i][j] == 0 || visited[i*cols + j] == 1)
			return ;
		visited[i*cols + j] = 1;
		pos.push_back(make_pair(i,j));
		for (auto c : dic)
		{
			int x = i + c[0];
			int y = j + c[1];
			helper(x, y, grid, dic, pos, visited);
		}
	}
	//对于岛屿,找到其最左left和最上的位置top,用每个位置i,j分别减去left和top
	//得到的i-left和j-top存入字符串
	string build(vector<pair<int,int>> pos, int cols)
	{
		int left = INT_MAX, top = INT_MAX;
		for (auto c : pos)
		{
			if (c.first < left)
				left = c.first;
			if (c.second < top)
				top = c.second;
		}
		sort(pos.begin(), pos.end());
		string str;
		for (auto c : pos)
		{
			str += to_string(c.first - left) + to_string(c.second-top);
		}
		return str;
	}
};
#endif