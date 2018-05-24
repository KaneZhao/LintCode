#ifndef C428_H
#define C428_H
#include<iostream>
using namespace std;
/*
* x的n次幂
*
* 实现 pow(x,n)
* 注意事项
* 不用担心精度，当答案和标准输出差绝对值小于1e-3时都算正确
* 样例
* Pow(2.1, 3) = 9.261
* Pow(0, 1) = 0
* Pow(1, 0) = 1
* 挑战
* O(logn) time
*/
class Solution {
public:
	/*
	* @param x: the base number
	* @param n: the power number
	* @return: the result
	*/
	double myPow(double x, int n) {
		// write your code here
		if (n < 0)
		{
			if (n == INT_MIN)
				return 1 / Pow(x, INT_MAX);
			else
				return 1 / Pow(x, -n);
		}
		else
			return Pow(x, n);
	}
	//二分法
	double Pow(double x, int n)
	{
		if (n == 0)
			return 1;
		if (n == 1)
			return x;
		double res = pow(x, n >> 1);
		res *= res;
		if (n & 1 == 1)
			res *= x;
		return res;
	}

};
#endif