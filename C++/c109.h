#ifndef C109_H
#define C109_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 数字三角形
*
* 给定一个数字三角形，找到从顶部到底部的最小路径和。每一步可以移动到下面一行的相邻数字上。
* 注意事项
* 如果你只用额外空间复杂度O(n)的条件下完成可以获得加分，其中n是数字三角形的总行数。
* 样例
* 比如，给出下列数字三角形：
* [
* [2],
* [3,4],
* [6,5,7],
* [4,1,8,3]
* ]
* 从顶到底部的最小路径和为11 ( 2 + 3 + 5 + 1 = 11)。
*/
class Solution {
public:
	/**
	* @param triangle: a list of lists of integers.
	* @return: An integer, minimum path sum.
	*/
	int minimumTotal(vector<vector<int>> &triangle) {
		// write your code here
		if (triangle.empty() || triangle[0].empty())
			return 0;
		int size = triangle.size();
		//从三角形底层向上计算每个位置的最小路径和,并将其赋值给triangle[i][j]
		//triangle[i][j] = min{triangle[i+1][j],triangle[i+1][j+1]}+triangle[i][j]
		for (int i = size - 2; i >= 0; --i)
		{
			for (int j = 0; j < triangle[i].size(); ++j)
			{
				triangle[i][j] += minVal(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}
		return triangle[0][0];
	}
	int minVal(int a, int b)
	{
		return a < b ? a : b;
	}
};

#endif