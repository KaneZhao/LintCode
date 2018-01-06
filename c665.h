#ifndef C665_H
#define C665_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 平面范围求和 -不可变矩阵
*
* 给一 二维矩阵,计算由左上角 (row1, col1) 和右下角 (row2, col2) 划定的矩形内元素和.
* 注意事项
* 你可以假设矩阵不变
* 对函数 sumRegion 的调用次数有很多次
* 你可以假设 row1 ≤ row2 并且 col1 ≤ col2
* 样例
* 给出矩阵
* [
* [3, 0, 1, 4, 2],
* [5, 6, 3, 2, 1],
* [1, 2, 0, 1, 5],
* [4, 1, 0, 1, 7],
* [1, 0, 3, 0, 5]
* ]
* sumRegion(2, 1, 4, 3) -> 8
* sumRegion(1, 1, 2, 2) -> 11
* sumRegion(1, 2, 2, 4) -> 12
*/
class NumMatrix {
public:
	/*
	* @param matrix: a 2D matrix
	*/
	//构造数组vec[][]，vec[i][j]表示从matrix[0][0]到matrix[i][j]的区间的数组元素之和
	NumMatrix(vector<vector<int>> matrix) {
		// do intialization if necessary
		vec = matrix;
		int row = vec.size(), col = vec[0].size();
		for (int j = 1; j < col; ++j)
		{
			vec[0][j] += vec[0][j - 1];
		}
		for (int i = 1; i < row; ++i)
		{
			vec[i][0] += vec[i - 1][0];
		}
		for (int i = 1; i < row; ++i)
		{
			for (int j = 1; j < col; ++j)
			{
				vec[i][j] += vec[i - 1][j] + vec[i][j - 1] - vec[i - 1][j - 1];
			}
		}
	}

	  /*
	  * @param row1: An integer
	  * @param col1: An integer
	  * @param row2: An integer
	  * @param col2: An integer
	  * @return: An integer
	  */
	  int sumRegion(int row1, int col1, int row2, int col2) {
		  // write your code here
		  int res = 0;
		  if (row1 == 0 && col1 == 0)
			  return vec[row2][col2];
		  else if (row1 == 0 && col1 != 0)
			  return vec[row2][col2] - vec[row2][col1 - 1];
		  else if (row1 != 0 && col1 == 0)
			  return vec[row2][col2] - vec[row1 - 1][col2];
		  else 
			  return vec[row2][col2] - vec[row2][col1 - 1] - vec[row1 - 1][col2] +
			  vec[row1 - 1][col1 - 1];

	  }
	  vector<vector<int>> vec;
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix obj = new NumMatrix(matrix);
* int param_1 = obj.sumRegion(row1,col1,row2,col2);
*/
#endif