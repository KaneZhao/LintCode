#ifndef C944_H
#define C944_H
#include<iostream>
#include<vector>
using namespace std;
/*
* Maximum Submatrix
*
* Given an n x n matrix of positive and negative integers, find the submatrix with the largest possible sum.
* 样例
* Given matrix =
* [
* [1,3,-1],
* [2,3,-2],
* [-1,-2,-3]
* ]
* return 9.
* Explanation:
* the submatrix with the largest possible sum is:
* [
* [1,2],
* [2,3]
* ]
*/
class Solution {
public:
	/**
	* @param matrix: the given matrix
	* @return: the largest possible sum
	*/
	int maxSubmatrix(vector<vector<int>> &matrix) {
		// write your code here
		if (matrix.empty() || matrix[0].empty())
			return 0;
		int res = 0;
		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<vector<int>> sum = matrix;
		//sum[i][j]表示以matrix[0][0]为左上角,matrix[i][j]为右下角的矩阵,其包含元素的和
		for (int i = 1; i < rows; ++i)
			sum[i][0] += sum[i - 1][0];
		for (int j = 1; j < cols; ++j)
			sum[0][j] += sum[0][j - 1];
		for (int i = 1; i < rows; ++i)
		{
			for (int j = 1; j < cols; ++j)
			{
				sum[i][j] = sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			}
		}
		//遍历数组,将matrix[i][j]的值置为以matrix[i][j]为右下角的矩阵其元素的最大值
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				int val = INT_MIN;
				for (int k = 0; k <= i; ++k)
				{
					for (int l = 0; l <= j; ++l)
					{
						int temp = 0;
						if (k == 0 && l>0)
							temp = sum[i][j] - sum[i][l - 1];
						else if (k > 0 && l == 0)
							temp = sum[i][j] - sum[k - 1][j];
						else if (k == 0 && l == 0)
							temp = sum[i][j];
						else
						    temp = sum[i][j] - sum[k - 1][j] - sum[i][l - 1] + sum[k - 1][l - 1];
						val = maxVal(val, temp);
					}
				}
				matrix[i][j] = val;
			}
		}
		for (auto c : matrix)
		{
			for (auto t : c)
			{
				res = maxVal(t, res);
			}
		}
		return res;
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif