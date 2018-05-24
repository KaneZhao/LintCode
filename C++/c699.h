#ifndef C699_H
#define C699_H
#include<iostream>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
/*
* 给两个数字 n 和 k. 我们需要判断 n 是否可以写成 k 个素数的和.
* 注意事项
* n <= 10 ^ 9
* 
* 戈德巴赫的猜想
* 任一大于2的偶数都可写成两个素数之和
*/
class Solution {
public:
	/*
	* @param : an int
	* @param : an int
	* @return: if N can be expressed in the form of sum of K primes, return true; otherwise, return false.
	*/
	bool isSumOfKPrimes(int n, int k) {
		// write your code here
		//由于最小的素数为2，当n<2k时，不可能实现，返回false
		if (n<2*k||k <= 0)
			return false;
		if (k == 1)
			return isPrime(n);
		//若k也为偶数（k=2q），n>=4q，n可以分成q个大于等于4的数，根据猜想，每个数又可以表示为两个质数的和，故可以表示为k（即2q）个质数的和，返回true
		//若k为奇数，为了保证n可以是k个数的和，必存在素数2，返回isSumOfKPrimes(n - 2, k - 1)
		if (n % 2 == 0)
		{
			if (k%2==0)
				return true;
			else
				return isSumOfKPrimes(n - 2, k - 1);
		}
		//若k为偶数，n不可能由偶数个奇数组成，必存在素数2，返回isSumOfKPrimes(n - 2, k - 1)
		//若k为奇数，必然存在至少一个奇数，返回isSumOfKPrimes(n - 3, k - 1)
		else
		{
			if (k %2==0)
				return isSumOfKPrimes(n - 2, k - 1);
			else
				return isSumOfKPrimes(n - 3, k - 1);
		}
	}
	//判断是否是质数
	bool isPrime(int num)
	{
		if (num < 2)
			return false;
		for (int i = 2; i*i < num; ++i)
		{
			if (num%i == 0)
				return false;
		}
		return true;
	}
};
#endif