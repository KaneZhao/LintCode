#ifndef C720_H
#define C720_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* Rearrange a String With Integers
* Given a string containing uppercase alphabets and integer digits (from 0 to 9), write a function to return the alphabets in the order followed by the sum of digits.
*
* 样例
* Given str = AC2BEW3, return ABCEW5
* Alphabets in the lexicographic order, followed by the sum of integers(2 and 3).
*/
class Solution {
public:
	/*
	* @param str: a string containing uppercase alphabets and integer digits
	* @return: the alphabets in the order followed by the sum of digits
	*/
	string rearrange(string &str) {
		// Write your code here
		if (str.empty())
			return str;
		vector<int> dic(26, 0);//存放str中出现字符的个数
		const string alphaDic("ABCDEFGHIJKLMNOPQRSTUVWXYZ");//当做字典
		int num = 0;
		//遍历str的每一位元素,字母存放在dic中,数字加到num上
		for (auto c : str)
		{
			if (isalpha(c))
				dic[c - 'A']++;
			else
				num += (c - '0');
		}
		str.clear();
		//重新构建字符串
		for (int i = 0; i < dic.size(); ++i)
		{
			if (dic[i]>0)
			{
				for (int j = 0; j < dic[i]; ++j)
					str+=alphaDic[i];
			}
		}
		str += to_string(num);
		return str;
	}
};
#endif