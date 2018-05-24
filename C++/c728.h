#ifndef C728_H
#define C728_H
#include<iostream>
#include<cmath>
using namespace std;
/*
*3����ͬ������
*��һ ������ n (1 <= n <= 10^18). �ж�������Ƿ�����ֻ�� 3 ����ͬ������, ��������� 3 ����ͬ�����Ӿͷ��� true, ���򷵻� false
*
*����
*���� n = 9, ���� true ���� 9 ������ 3 ������: 1, 3, 9, ���Է��� true.
*���� n = 10, ���� false
*˼·
*�ж��������Ƿ�����ֻ�� 3 ����ͬ�����ӣ���ʵ�����жϴ��������Ƿ���һ��������ƽ����
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
		//��n��num��ƽ��
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
	//�ж�num�Ƿ�������
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