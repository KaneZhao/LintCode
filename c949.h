#ifndef C949_H
#define C949_H
#include<iostream>
#include<string>
using namespace std;
/*
* Fibonacci II
*
* In the Fibonacci integer sequence, F0 = 0, F1 = 1, and Fn = Fn − 1 + Fn − 2 for n ≥ 2. For example, the first ten terms of the Fibonacci sequence are:0,1,1,2,3,5,8,13,21,34,…
* Given an integer n, your goal is to compute the last 4 digits of Fn
* 注意事项
* 1.0 ≤ n ≤ 1,000,000,000
* 2.If the last four digits of Fn are all zeros, print ‘0’; otherwise, omit any leading zeros(print Fn mod 10000)
* 样例
* Given: n = 9
* Return: 34
*/
class Matrix{
public:
	int a, b, c, d;
	Matrix(int a, int b, int c, int d)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
};
class Solution {
public:
	/**
	* @param n: an integer
	* @return: return a string
	*/
	string lastFourDigitsOfFn(int n) {
		// write your code here
		if (n == 0)
			return "0";
		else if (n == 1)
			return "1";
		Matrix matrix = matrixPow(n);
		//matrix.b表示Fn
		string res = to_string(matrix.b);
		int pos = 0;
		//清楚不必要的'0'
		for (int i = 0; i < res.size(); ++i)
		{
			if (res[i] != '0')
			{
				pos = i;
				break;
			}
		}
		return res.substr(pos);
	}
	//基本的2*2矩阵乘法,只取后四位,结果模10000
	Matrix matrixMul(Matrix A, Matrix B)
	{
		Matrix C(0, 0, 0, 0);
		C.a = (A.a*B.a + A.b*B.c) % 10000;
		C.b = (A.a*B.b + A.b*B.d) % 10000;
		C.c = (A.c*B.a + A.d*B.c) % 10000;
		C.d = (A.c*B.b + A.d*B.d) % 10000;
		return C;
	}
	//基本的2*2矩阵幂
	Matrix matrixPow(int n)
	{
		Matrix matrix(0, 0, 0, 0);
		if (n == 1)
			matrix = Matrix(1, 1, 1, 0);
		else if ((n & 1) == 0)
		{
			matrix = matrixPow(n >> 1);
			matrix = matrixMul(matrix, matrix);
		}
		else if ((n & 1) == 1)
		{
			matrix = matrixPow((n - 1) >> 1);
			matrix = matrixMul(matrix, matrix);
			matrix = matrixMul(matrix, Matrix(1, 1, 1, 0));
		}
		return matrix;
	}
};
#endif