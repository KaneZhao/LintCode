#ifndef C408_H
#define C408_H
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
/*
* 二进制求和
*
* 给定两个二进制字符串，返回他们的和（用二进制表示）。
* 样例
* a = 11
* b = 1
* 返回 100
*/
//处理字符串,相加进位
class Solution {
public:
	/*
	* @param a: a number
	* @param b: a number
	* @return: the result
	*/
	string addBinary(string &a, string &b) {
		// write your code here
		int a_size = a.size();
		int b_size = b.size();
		if (a_size < b_size)
		{
			int diff = b_size - a_size;
			while (diff != 0)
			{
				a = "0" + a;
				diff--;
			}
		}
		else
		{
			int diff = a_size - b_size;
			while (diff != 0)
			{
				b = "0" + b;
				diff--;
			}
		}
		int len = a.size();
		int flag = 0;
		for (int i = len - 1; i >= 0; --i)
		{
			if (flag == 0)
			{
				if (a[i] == '1'&&b[i] == '1')
				{
					a[i] = '0';
					flag = 1;
				}
				else if (a[i] == '0'&&b[i] == '0')
				{
					a[i] = '0';
					flag = 0;
				}
				else
				{
					a[i] = '1';
					flag = 0;
				}
			}
			else
			{
				if (a[i] == '1'&&b[i] == '1')
				{
					a[i] = '1';
					flag = 1;
				}
				else if (a[i] == '0'&&b[i] == '0')
				{
					a[i] = '1';
					flag = 0;
				}
				else
				{
					a[i] = '0';
					flag = 1;
				}
			}
			if (i == 0 && flag == 1)
				a = "1" + a;
		}
		return a;
	}
};
//将二进制表示的字符串转换为十进制,再进行运算
class Solution2 {
public:
	/**
	* @param a: a number
	* @param b: a number
	* @return: the result
	*/
	string addBinary(string &a, string &b) {
		// write your code here
		long long size_a = a.size();
		long long size_b = b.size();
		long long num_a =0, num_b = 0;
		for (long long i = 0; i < size_a; ++i)
			num_a += (a[i] - '0')*pow(2, size_a - i - 1);
		for (long long i = 0; i < size_b; ++i)
			num_b += (b[i] - '0')*pow(2, size_b - i - 1);
		long long res = num_a + num_b;
		string str;
		if (res == 0)
			return "0";
		while (res)
		{
			if (res & 1 == 1)
				str = "1" + str;
			else
				str = "0" + str;
			res = res >> 1;
		}
		return str;
	}
};
#endif