#ifndef C477_H
#define C477_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
* ��Χ�Ƶ�����
*
* ��һ����ά�ľ��󣬰��� 'X' �� 'O', �ҵ����б� 'X' Χ�Ƶ����򣬲��� 'X' �������
* ����
* ������ά����
* X X X X
* X O O X
* X X O X
* X O X X
* �ѱ� 'X' Χ�Ƶ��������֮���Ϊ��
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
				//ֻ�п���'O'�ڱ߽�����
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