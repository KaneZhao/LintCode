#ifndef C1385_H
#define C1385_H
#include<iostream>
using namespace std;
/*
* 幸运数字8
*
* 描述
* 8是小九的幸运数字，小九想知道在1~n的数中有多少个数字含有8。
* 1 <= n <= 1000000
* 样例
* 给出 n = 20， 返回2。
* 解释：
* 只有8,18 含有8。
* 给出 n = 100， 返回19。
* 解释：
* 有8,18,28,38,48,58,68,78,80,81,82,83,84,85,86,87,88,89,98。
*/
class Solution {
public:
	/**
	* @param n: count lucky numbers from 1 ~ n
	* @return: the numbers of lucky number
	*/
	int luckyNumber(int n) {
		// Write your code here
		if (n <= 7)
			return 0;
		int num = 1;
		int i = 8;
		//下一个含有8的数字出现情况只可能比现在的数字大1,2,9或10
		while (i <= n)
		{
			if (hasEight(i+1))
			{
				i += 1;
				num++;
			}
			else if (hasEight(i + 2))
			{
				i += 2;
				num++;
			}
			else if (hasEight(i + 9))
			{
				i += 9;
				num++;
			}
			else if (hasEight(i + 10))
			{
				i += 10;
				num++;
			}
		}
		return --num;
	}
	//判断数字中是否有8
	bool hasEight(int n)
	{
		while (n)
		{
			if (n % 10 == 8)
				return true;
			n = n / 10;
		}
		return false;
	}
};
#endif