#ifndef C807_H
#define C807_H
#include<iostream>
#include<string>
using namespace std;
/*
* 回文数 II
*
* 判断一个非负整数 n 的二进制表示是否为回文数
* 注意事项
* 我们保证 0 <= n <= 2^32 - 1
* 样例
* 给出 n = 0，返回True。
* 解释：
* 0 的二进制表示为：0。
* 给出 n = 3，返回True。
* 解释：
* 3 的二进制表示为：11。
* 给出 n = 4，返回False。
* 解释：
* 4 的二进制表示为：100。
* 给出 n = 6，返回False。
* 解释：
* 6 的二进制表示为：110。
*/
class Solution {
public:
	/**
	* @param n: non-negative integer n
	* @return: return whether a binary representation of a non-negative integer n is a palindrome.
	*/
	bool isPalindrome(int n) {
		// Write your code here
		string res = change(n);
		int l = 0, r = res.size() - 1;
		//判断是否是回文串
		while (l < r)
		{
			if (res[l] != res[r])
				return false;
			l++;
			r--;
		}
		return true;
	}
	//将整数转化为二进制,并用字符串表示
	string change(int n)
	{
		string res;
		int m = 1;
		for (int i = 0; i < 32; ++i,m=m<<1)
		{
			if (n&m)
				res = "1" + res;
			else
				res = "0" + res;
		}
		//去除前面多余的0
		if (res.find("1") == string::npos)
			res = "0";
		else
			res = res.substr(res.find("1"));
		return res;
	}
};
#endif