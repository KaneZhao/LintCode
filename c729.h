#ifndef C729_H
#define C729_H
#include<iostream>
using namespace std;
/*
*�׳˳��������һλ��
*
*����
*���������� A �� B, ���� B >= A. ������Ҫ������ F �����һλ����ʲô, ����F = B! / A!(1 <= A, B <= 10^18, A �� B �ǳ���)
*
*����
*���� A = 2, B = 4, ���� 2
*A! = 2 �Լ� B! = 24, F = 24 / 2 = 12 --> ���һλ��Ϊ 2
*
*���� A = 107, B = 109, ���� 2
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