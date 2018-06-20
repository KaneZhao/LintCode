#ifndef C1347_H
#define C1347_H
#include<iostream>
using namespace std;
/*
* 尾随零
*
* 描述
* 给定一个整数n，返回n!（n的阶乘）的尾随零的个数。
* 您的解法时间复杂度应为对数级别。
*/
class Solution {
public:
	/**
	* @param n: a integer
	* @return: return a integer
	*/
	int trailingZeroes(int n) {
		// write your code here
		int cnt = 0;
		//由于2和5可以形成0,且2的个数总是多于5,即找0~n中的数包含5的个数
		while (n != 0)
		{
			cnt += n / 5;
			n = n / 5;
		}
		return cnt;
	}
};
#endif