#ifndef C114_H
#define C114_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 不同的路径
*
* 有一个机器人的位于一个 m × n 个网格左上角。
* 机器人每一时刻只能向下或者向右移动一步。机器人试图达到网格的右下角。
* 问有多少条不同的路径？
* 注意事项
* n和m均不超过100
* 样例
* 给出 m = 3 和 n = 3, 返回 6.
* 给出 m = 4 和 n = 5, 返回 35.
*/
class Solution {
public:
	/**
	* @param n, m: positive integer (1 <= n ,m <= 100)
	* @return an integer
	*/
	int uniquePaths(int m, int n) {
		// wirte your code here
		vector<vector<int>> v(m, vector<int>(n));//v[i][j]表示从v[0][0]到v[i][j]的路径数
		for (int i = 0; i < m; ++i)
			v[i][0] = 1;
		for (int j = 0; j < n; ++j)
			v[0][j] = 1;
		//由于只能向下或者向右
		//v[i][j]只能从v[i-1][j]或v[i][j-1]到达,其值为两个位置路径数之和
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				v[i][j] = v[i - 1][j] + v[i][j - 1];
			}
		}
		return v[m-1][n - 1];
	}
};

#endif