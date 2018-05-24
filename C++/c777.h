#ifndef C777_H
#define C777_H
#include<iostream>
using namespace std;
/*
* Valid Perfect Square
*
* Given a positive integer num, write a function which returns True if num is a perfect square else False.
* 注意事项
* Do not use any built-in library function such as sqrt.
* 样例
* For example:
* Given num = 16
* Returns True
*/
class Solution {
public:
	/**
	* @param num: a positive integer
	* @return: if num is a perfect square else False
	*/
	bool isPerfectSquare(int num) {
		// write your code here
		int left = 0, right = num;
		while (left < right)
		{
			long long mid = (left + right) / 2;
			if (mid*mid>num)
				right = mid - 1;
			else if (mid*mid==num)
				return true;
			else
				left = mid + 1;
		}
		return left*left==num;
	}
};
#endif