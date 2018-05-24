#ifndef C744_H
#define C744_H
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
/*
* Sum of first K even-length Palindrome numbers
*
* Given a integer k, find the sum of first k even-length palindrome numbers.
* Even length here refers to the number of digits of a number is even.
*
* 样例
* Given k = 3, return 66 // 11 + 22 + 33 = 66 (Sum of first three even-length palindrome
* numbers)
* Given k = 10, return 1496
* // 11 + 22 + 33 + 44 + 55 + 66 + 77 + 88 + 99 + 1001 = 1496
*/
class Solution {
public:
	/**
	* @param k:
	* @return: the sum of first k even-length palindrome numbers
	*/
	int sumKEven(int k) {
		// Write your code here
		if (k <= 0)
			return 0;
		int res = 0;
		for (int i = 1; i <= k; ++i)
		{
			res += createPalNum(i);
		}
		return res;
	}
	//对于每个数k,构造其回文数
	int createPalNum(int k)
	{
		string str = to_string(k);
		int len = str.size();
		int res = k*pow(10, len);
		for (int i = 0; i < len; ++i)
		{
			res += stoi(str.substr(i, 1))*pow(10, i);
		}
		return res;
	}
};
#endif