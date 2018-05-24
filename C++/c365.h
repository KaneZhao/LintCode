#ifndef C365_H
#define C365_H
#include<iostream>
#include<Windows.h> 
using namespace std;
/*
* 二进制中有多少个1
*
* 计算在一个 32 位的整数的二进制表示中有多少个 1.
* 样例
* 给定 32 (100000)，返回 1
* 给定 5 (101)，返回 2
* 给定 1023 (1111111111)，返回 10
* 挑战
* If the integer is n bits with m 1 bits. Can you do it in O(m) time?
*/
class Solution {
public:
	/*
	* @param num: An integer
	* @return: An integer
	*/
	int countOnes(int num) {
		// write your code here
		if (num < 0)
			return 32 - countOnesRecur(num);
		else
			return countOnesRecur(num);
	}
	int countOnesRecur(int num)
	{
		int count = 0;
		if (num < 0)
		{
			num = -1 ^ num;
		}
		if (num == 1)
			return 1;
		if (num == 0)
			return 0;
		if (num % 2 == 0)
			return countOnes(num >> 1);
		else
			return countOnes(num >> 1) + 1;
	}
};
class Solution2 {
public:
	/*
	* @param num: An integer
	* @return: An integer
	*/
	int countOnes(int num) {
		// write your code here
		//把一个整数减去1，再和原整数做运算，会把改整数最右边的1变为0。一个整数的二进制表示中由多少个1，就可以进行多少次这样的操作。
		int cnt = 0;
		while (num)
		{
			++cnt;
			num = (num - 1)&num;
		}
		return cnt;
	}
};
#endif