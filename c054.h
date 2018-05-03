#ifndef C54_H
#define C54_H
#include<iostream>
#include<string>
#include <math.h>
using namespace std;
/*
* String to Integer (atoi)
*
* 实现atoi这个函数，将一个字符串转换为整数。如果没有合法的整数，返回0。如果整数超出了32位整数的范围，返回INT_MAX(2147483647)如果是正整数，或者INT_MIN(-2147483648)如果是负整数。
* 样例
* "10" =>10
* "-1" => -1
* "123123123123123" => 2147483647
* "1.0" => 1
*/
class Solution {
public:
	/**
	* @param str: A string
	* @return: An integer
	*/
	int atoi(string &str) {
		// write your code here
		if (str.empty())
			return 0;
		long long res = 0;
		bool isNeg = false;
		string nums("0123456789");
		int posNum = 0;
		//找到第一个数字出现的位置
		if (str.find_first_of(nums) != string::npos)
			posNum = str.find_first_of(nums);
		else
			return 0;
		//若第一个数字前不是是空格,-或者+,不合法
		if (posNum > 0 && str[posNum - 1] != ' ' && str[posNum - 1] != '-' && str[posNum-1] != '+')
			return 0;
		//从字符串开始到第一个字母的前一个位置之前,只能是空格,否则不合法
		for (int i = 0; i< posNum - 1; ++i)
		{
			if (str[i] != ' ')
				return 0;
		}
		//判断是否是负数
		if (posNum>0 && str[posNum - 1] == '-')
			isNeg = true;
		str = str.substr(posNum);
		//寻找合法数字的结束位置,遇到非数字就结束(处理了小数问题)
		int end = 0;
		for (int i = 0; i<str.size(); ++i)
		{
			if (isdigit(str[i]))
			{
				end = i;
			}
			else
				break;
		}
		//对于提取到的合法整数,计算其值
		str = str.substr(0, end + 1);
		for (int j = 0; j <str.size(); ++j)
			res += (str[j] - '0')*pow(10, str.size() - 1 - j);
		if (isNeg)
			res = -res;
		if (res > INT_MAX)
			res = INT_MAX;
		else if (res < INT_MIN)
			res = INT_MIN;
		return res;
	}
};
#endif