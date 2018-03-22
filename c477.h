#ifndef C477_H
#define C477_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
* 被围绕的区域
*
* 给一个二维的矩阵，包含 'X' 和 'O', 找到所有被 'X' 围绕的区域，并用 'X' 填充满。
* 样例
* 给出二维矩阵：
* X X X X
* X O O X
* X X O X
* X O X X
* 把被 'X' 围绕的区域填充之后变为：
* X X X X
* X X X X
* X X X X
* X O X X
*/
class Solution {
public:
	/*
	* @param board: board a 2D board containing 'X' and 'O'
	* @return: nothing
	*/
	void surroundedRegions(vector<vector<char>> &board) {
		// write your code here
		if (board.empty() || board[0].empty())
			return;
		int rows = board.size();
		int cols = board[0].size();
		map<int, int> visited;
		vector<vector<int>> dic{ { 0, -1 }, { 0, 1 }, { 1, 0 }, { -1, 0 } };
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				//只有考虑'O'在边界的情况
				if ((i == 0 || i == rows - 1 || j == 0 || j == cols - 1) && visited.find(i*cols + j) == visited.end())
					helper(board, i, j, visited, dic);
			}
		}
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (board[i][j] == 'O'&&visited.find(i*cols + j) == visited.end())
					board[i][j] = 'X';
			}
		}
	}
	void helper(vector<vector<char>> &board, int i, int j, map<int, int> &visited, vector<vector<int>> dic)
	{
		int rows = board.size();
		int cols = board[0].size();
		if (i < 0 || i >= rows || j < 0 || j >= cols)
			return;
		if (board[i][j] == 'X' || visited[i*cols + j] == 1)
			return;
		visited[i*cols + j] = 1;
		for (auto c : dic)
		{
			int x = i + c[0];
			int y = j + c[1];
			helper(board, x, y, visited, dic);
		}
	}
};
#endif