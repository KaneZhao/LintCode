#ifndef C517_H
#define C517_H
#include<iostream>
using namespace std;
/*
* 丑数
*
* 描述
* 写一个程序来检测一个整数是不是丑数。
* 丑数的定义是，只包含质因子 2, 3, 5 的正整数。比如 6, 8 就是丑数，但是 14 不是丑数以为他包含了质因子 7。
* 可以认为 1 是一个特殊的丑数。
* 样例
* 给出 num = 8，返回 true。
* 给出 num = 14，返回 false。
*/
class Solution {
public:
	/*
	* @param num: An integer
	* @return: true if num is an ugly number or false
	*/
	bool isUgly(int num) {
		// write your code here
		if (num <= 0)
			return false;
		if (num == 1)
			return true;
		if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0)
			return false;
		else
		{
			if (num % 2 == 0)
				return isUgly(num / 2);
			else if (num % 3 == 0)
				return isUgly(num / 3);
			else
				return isUgly(num / 5);
		}
	}
};
#endif