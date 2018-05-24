#ifndef C181_H
#define C181_H
#include<iostream>
using namespace std;
/*
* 将整数A转换为B
* 
* 如果要将整数A转换为B，需要改变多少个bit位？
* 注意事项
* Both n and m are 32-bit integers.
* 样例
* 如把31转换为14，需要改变2个bit位。
* (31)10=(11111)2
* (14)10=(01110)2
*/
class Solution {
public:
	/**
	*@param a, b: Two integer
	*return: An integer
	*/
	int bitSwapRequired(int a, int b) {
		// write your code here
		//取ab的异或,得到的二进制中1的个数就是需要改变的位数
		int temp = a^b;
		int cnt = 0;
		//计算需要改变的位数
		while (temp)
		{
			temp &= (temp - 1);
			cnt++;
		}
		return cnt;
	}
};
#endif