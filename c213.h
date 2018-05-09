#ifndef C213_H
#define C213_H
#include<iostream>
#include<string>
using namespace std;
/*
* 字符串压缩
*
* 描述
* 设计一种方法，通过给重复字符计数来进行基本的字符串压缩。
* 例如，字符串 aabcccccaaa 可压缩为 a2b1c5a3 。而如果压缩后的字符数不小于原始的字符数，则返回原始的字符串。
* 可以假设字符串仅包括a-z的字母。
* 样例
* str=aabcccccaaa 返回 a2b1c5a3
* str=aabbcc 返回 aabbcc
* str=aaaa 返回 a4
*/
class Solution {
public:
	/**
	* @param str: a string
	* @return: a compressed string
	*/
	string compress(string &str) {
		// write your code here
		if (str.empty() || str.size() == 1)
			return str;
		string res;
		int num = 1;//表示字符出现的次数
		char c = str[0];
		for (int i = 1; i < str.size(); ++i)
		{
			if (c == str[i])
			{
				num++;
			}
			else
			{
				res += c + to_string(num);
				c = str[i];
				num = 1;
			}
			//当遍历到末尾,添加c和对应的num
			if (i == str.size() - 1)
			{
				res += c + to_string(num);
			}
		}
		//返回原字符串和压缩后字符串长度较小者
		return res.size() < str.size() ? res : str;
	}
};
#endif