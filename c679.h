#ifndef C679_H
#define C679_H
#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
* 不同的路径 III
* 
* "不同的路径II"的 follow up:http://lintcode.com/en/problem/unique-paths-ii/
* 现在每一个格子都包含了一个值,所以每条路径都有一个值,找到所有值不同的路径的和
* 样例
* 举个例子,
* [
* [1,1,2],
* [1,2,3],
* [3,2,4]
* ]
* 这里有两条值不同的路径:
* [1,1,2,3,4] = 11
* [1,1,2,2,4] = 10
* 返回 21
*/
class Solution {
public:
	/*
	* @param : an array of arrays
	* @return: the sum of all unique weighted paths
	*/
	int uniqueWeightedPaths(vector<vector<int>>& grid) {
		// write your codes here
		if (grid.empty()||grid[0].empty())
			return 0;
		int row = grid.size();
		int col = grid[0].size();
		int len = row*col;
		vector<vector<int>> res(len, vector<int>());//保存grid每个位置上的不同路径值
		for (int i = 1; i < row; ++i)
		{
			grid[i][0] += grid[i - 1][0];
			res[i*col].push_back(grid[i][0]);
		}
		for (int j = 1; j < col; ++j)
		{
			grid[0][j] += grid[0][j - 1];
			res[j].push_back(grid[0][j]);
		}
		//提取grid[i-1][j]与grid[i][j-1]位置上的不同路径值,并存入res[i*col+j]中
		for (int i = 1; i < row; ++i)
		{
			for (int j = 1; j < col; ++j)
			{
				set<int> set;
				int m = 0;
				for (auto c : res[(i-1)*col + j])
					set.insert(c);
				for (auto t : res[i*col + (j - 1)])
					set.insert(t);
				for (auto s : set)
				{
					res[i*col + j].push_back(s+grid[i][j]);
					m += grid[i][j] + s;
				}
				grid[i][j] = m;
			}
		}
		return grid[row - 1][col - 1];
	}
};
#endif