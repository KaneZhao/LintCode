#ifndef C142_H
#define C142_H
#include<iostream>
using namespace std;
/*
* O(1)时间检测2的幂次
*
* 用 O(1) 时间检测整数 n 是否是 2 的幂次。
* 样例
* n=4，返回 true;
* n=5，返回 false.
* 挑战
* O(1) time
*/
class Solution {
public:
	/*
	* @param n: An integer
	* @return: True or false
	*/
	//利用递归,判断是否可以被连续的2整除
	bool checkPowerOf2(int n) {
		// write your code here
		if (n == 1)
			return true;
		if (n <= 0)
			return false;
		if (n % 2 != 0)
			return false;
		else
		{
			if (checkPowerOf2(n >> 1))
				return true;
		}
	}
};
class Solution2 {
public:
	/**
	* @param n: An integer
	* @return: True or false
	*/
	//2的次幂,二进制表示只有一个1且在最左边
	//n&(n-1)消除仅有的1,值为0
	bool checkPowerOf2(int n) {
		// write your code here
		if (n <= 0)
			return false;
		return (n&(n - 1)) == 0 ? true: false;
	}
};
#endif