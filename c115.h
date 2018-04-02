#ifndef C115_H
#define C115_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 不同的路径 II
*
* "不同的路径" 的跟进问题：
* 现在考虑网格中有障碍物，那样将会有多少条不同的路径？
* 网格中的障碍和空位置分别用 1 和 0 来表示。
* 注意事项
* m 和 n 均不超过100
* 样例
* 如下所示在3x3的网格中有一个障碍物：
* [
* [0,0,0],
* [0,1,0],
* [0,0,0]
* ]
* 一共有2条不同的路径从左上角到右下角。
*/
class Solution {
public:
	/**
	* @param obstacleGrid: A list of lists of integers
	* @return: An integer
	*/
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		// write your code here
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> v(m, vector<int>(n));
		int flag1=0, flag2=0;
		//初始化i,j=0的情况,出现obstacleGrid[i][0]或者obstacleGrid[0][j]其后的元素的值均为0
		for (int i = 0; i < m; ++i)
		{
			if (obstacleGrid[i][0] == 0&&flag1==0)
				v[i][0] = 1;
			else
			{
				flag1 = 1;
				v[i][0] = 0;
			}
		}
		for (int j = 0; j < n; ++j)
		{
			if (obstacleGrid[0][j] == 0 && flag2 == 0)
				v[0][j] = 1;
			else
			{
				flag2 = 1;
				v[0][j] = 0;
			}
		}
		//若obstacleGrid[i][j]=1,无法到达v[i][j]取值为0
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (obstacleGrid[i - 1][j] == 0)
					v[i][j] += v[i - 1][j];
				if (obstacleGrid[i][j - 1] == 0)
					v[i][j] += v[i][j - 1];
				if (obstacleGrid[i][j] == 1)
					v[i][j] = 0;
			}
		}
		return v[m - 1][n - 1];
	}
};
#endif