#ifndef C209_H
#define C209_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* First Unique Character in a String
*
* 给出一个字符串，找出第一个只出现一次的字符。
* 样例
* 对于 "abaccdeff", 'b'为第一个只出现一次的字符.
*/
class Solution {
public:
	/**
	* @param str: str: the given string
	* @return: char: the first unique character in a given string
	*/
	char firstUniqChar(string &str) {
		// Write your code here
		vector<int> dic(26, -1);//存放字符第一次出现的位置
		//从后先前遍历字符串,dic[pos]等于-1表示之前没有出现
		//如果非负,则之前出现过,置为-2,再遇到不进行处理
		for (int i = str.size() - 1; i >= 0; --i)
		{
			int pos = str[i] - 'a';
			if (dic[pos] == -1)
			{
				dic[pos] = i;
			}
			else
			{
				if (dic[pos] >= 0)
				{
					dic[pos] = -2;
				}
			}
		}
		//在dic中寻找值非负且最小的位置,返回其代表的字符
		int res = INT_MAX;
		int tmp = 0;
		for (int i = 0; i < dic.size(); ++i)
		{
			if (dic[i]<res&&dic[i]>=0)
			{
				res = dic[i];
				tmp = i;
			}
		}
		return 'a' + tmp;
	}
};
#endif