#ifndef C654_H
#define C654_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
* 稀疏矩阵乘法
*
* 描述
* 给定两个 稀疏矩阵 A 和 B，返回AB的结果。
* 您可以假设A的列数等于B的行数。
* 样例
* A = [
* [ 1, 0, 0],
* [-1, 0, 3]
* ]
* B = [
* [ 7, 0, 0 ],
* [ 0, 0, 0 ],
* [ 0, 0, 1 ]
* ]
* 
*      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
* AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
*                   | 0 0 1 |
*/
class Solution {
public:
	/**
	* @param A: a sparse matrix
	* @param B: a sparse matrix
	* @return: the result of A * B
	*/
	vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
		// write your code here
		vector<vector<int>> res(A.size(),vector<int>(B[0].size(),0));
		map<int, int> ma, mb;
		int cols = A[0].size();
		//将A,B中元素的位置和值分别存入ma和mb
		for (int i = 0; i < A.size(); ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (A[i][j] != 0)
				{
					ma[i*cols + j] = A[i][j];
				}
			}
		}
		for (int j = 0; j < B[0].size(); ++j)
		{
			for (int i = 0; i < cols; ++i)
			{
				if (B[i][j] != 0)
				{
					mb[j*cols + i] = B[i][j];
				}
			}
		}
		//对于ma中的元素,分别于mb中相应位置的元素相乘,并加到res的对应位置
		for (auto c : ma)
		{
			int num = c.first%cols;
			int temp = 0;
			while (temp <= cols*(B[0].size() - 1))
			{
				if (mb.find(num + temp) != mb.end())
				{
					res[c.first / cols][(num+temp)/cols] += c.second*mb[num + temp];
				}
				temp += cols;
			}
		}
		return res;
	}
};
#endif