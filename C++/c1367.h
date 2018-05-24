#ifndef C1367_H
#define C1367_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
* 警察距离
*
* 给一个n x m的矩阵，里面的值1代表那个位置站了一个警察，-1代表是墙，0代表是空地。
* 现在请你输出一个n x m矩阵，输出每一个空地到离他最近的警察的距离。
* 注意事项
* 给的n x m 的矩阵， n <= 200，m <= 200。
* 保证每个空地都至少能走到一个警察。
* 样例
* 给出 mat =
* [
* [0,-1,0],
* [0,1,1],
* [0,0,0]
* ] ,返回[[2,-1,1],[1,0,0],[2,1,1]]。
* 警察到警察自身的距离都是0，这2个警察到其他空地的最近距离如上所示。
* 给出 mat =
* [
* [0,-1,-1],
* [0,-1,1],
* [0,0,0]
* ],返回[[5,-1,-1],[4,-1,0],[3,2,1]]。
* 警察到5个空地的最近距离如上所示。
*/
class Solution {
public:
	/**
	* @param matrix : the martix
	* @return: the distance of grid to the police
	*/
	vector<vector<int>> policeDistance(vector<vector<int>> &matrix) {
		// Write your code here
		if (matrix.empty() || matrix[0].empty())
			return matrix;
		int rows = matrix.size();
		int cols = matrix[0].size();
		int cnt = rows*cols;
		map<int, int> visited;//存放已经访问的位置与其值
		vector<vector<int>> dic{ { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
		//先存放警察位置和墙的位置
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (matrix[i][j] == 1)
				{
					visited[i*cols + j] = 0;
					matrix[i][j] = 0;
				}
				else if (matrix[i][j] == -1)
					visited[i*cols + j] = -1;
			}
		}
		//从警察位置开始处理其周围位置的值
		int num = 0;
		while (visited.size() < cnt)
		{
			helper(matrix, dic, visited, num);
			++num;
		}
		return matrix;
	}
	//在visited中寻找所有值为num的位置,并遍历其上下左右四个位置,设置值为num+1
	void helper(vector<vector<int>> &matrix, vector<vector<int>> dic, map<int, int> &visited, int num)
	{
		int rows = matrix.size();
		int cols = matrix[0].size();
		for (auto c : visited)
		{
			if (c.second == num)
			{
				for (auto t : dic)
				{
					int x = c.first / cols + t[0];
					int y = c.first % cols + t[1];
					if (x >= 0 && x < rows&&y >= 0 && y < cols && visited.find(x*cols+y)==visited.end())
					{
						matrix[x][y] = num + 1;
						visited[x*cols + y] = num + 1;
					}
				}
			}
		}
	}
};
#endif