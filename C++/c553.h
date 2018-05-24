#ifndef C553_H
#define C553_H
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*
* ը��Ϯ��
*
* ����
* ��һ����ά����, ÿһ�����Ӷ�������һ��ǽ W, һ������ E ���߿� 0 (���� '0'), �����������һ��ը��ɱ������������. ը����ɱ��������ͬһ�к�ͬһ��û��ǽ����ĵ���, ��Ϊǽ�Ƚϼ�����Դݻ�.
* ��ֻ���ڿյĵط�����ը��.
* ����
* ��һ������:
* 0 E 0 0
* E 0 W E
* 0 E 0 0
* ���� 3.(�ڣ�1, 1������ը������ɱ�� 3 ������)
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
		//up[i][j],down[i][j],left[i][j],right[i][j]�ֱ��ʾgrid[i-1][j-1]���������ĸ������Ͽ���ɱ���ĵ�����
		vector<vector<int>> 
			left(rows + 2, vector<int>(cols + 2, 0)),
			right(rows + 2, vector<int>(cols + 2, 0)),
			up(rows + 2, vector<int>(cols + 2, 0)),
			down(rows + 2, vector<int>(cols + 2, 0));
		//left[i][j]��ʾ��grid[i-1][j-1]����ը��,�������ɱ������������
		//����EҲ���Է���ը��,��ǰԪ��ΪE,����ɱ���ĵ�������һ
		//��ǰԪ��ΪW,���ܷ���ը��,����ɱ��������Ϊ0
		//��ǰԪ��Ϊ0,����ɱ������������
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
		//right[i][j]��ʾ��grid[i - 1][j - 1]����ը��, ���ҿ���ɱ������������
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
		//up[i][j]��ʾ��grid[i-1][j-1]����ը��,���Ͽ���ɱ������������
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
		//down[i][j]��ʾ��grid[i-1][j-1]����ը��,���¿���ɱ������������
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
		//����grid[i-1][j-1]Ϊ0ʱ�������������ҿ���ɱ�����˵�����
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