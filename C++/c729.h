#ifndef C729_H
#define C729_H
#include<iostream>
using namespace std;
/*
*阶乘除法的最后一位数
*
*描述
*给出两个数 A 和 B, 其中 B >= A. 我们需要计算结果 F 的最后一位数是什么, 其中F = B! / A!(1 <= A, B <= 10^18, A 和 B 非常大)
*
*样例
*给出 A = 2, B = 4, 返回 2
*A! = 2 以及 B! = 24, F = 24 / 2 = 12 --> 最后一位数为 2
*
*给出 A = 107, B = 109, 返回 2
*/
class Solution {
public:
	/*
	* @param : the given number
	* @param : another number
	* @return: the last digit of B! / A!
	*/
	int computeLastDigit(long long A, long long B) {
		// write your code here
		long long num = B;
		long long res = 1;
		while (num!=A)
		{
			if (num % 10 == 0)
				return 0;
			res = (res*(num % 10))%10;
			num--;
		}
		return res;
	}
};
#endif