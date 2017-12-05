#ifndef C728_H
#define C728_H
#include<iostream>
#include<cmath>
using namespace std;
/*
*3个不同的因子
*给一 正整数 n (1 <= n <= 10^18). 判断这个数是否正好只有 3 个不同的因子, 如果正好有 3 个不同的因子就返回 true, 否则返回 false
*
*样例
*给出 n = 9, 返回 true 数字 9 正好有 3 个因子: 1, 3, 9, 所以返回 true.
*给出 n = 10, 返回 false
*思路
*判断正整数是否正好只有 3 个不同的因子，其实就是判断此正整数是否是一个素数的平方。
*/
class Solution {
public:
	/*
	* @param : the given number
	* @return:  return true if it has exactly three distinct factors, otherwise false
	*/
	bool isThreeDisctFactors(long long n) {
		// write your code here
		if (n < 2)
			return false;
		long long num = sqrt(n);
		//若n是num的平方
		if (num*num == n)
		{
			if (isPrime(num))
				return true;
			else
				return false;
		}
		else
			return false;		
	}
	//判断num是否是素数
	bool isPrime(long long num)
	{
		if (num < 2)
			return false;
		for (long long i = 2; i*i < num; ++i)
		{
			if (num%i == 0)
				return false;
		}
		return true;
	}
};
#endif