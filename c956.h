#ifndef C956_H
#define C956_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* 数据分割
*
* 给出一个字符串 str,你需要按顺序提取出该字符串的符号和单词。
* 注意事项
* str长度不会超过10000。
* 字符串只包含小写字母，符号和空格。
* 样例
* 给出 str = "(hi (i am)bye)"，返回 ["(","hi","(","i","am",")","bye",")"]。
* 解释：
* 将符号和单词分割。
*/
class Solution {
public:
	/**
	* @param str: The input string
	* @return: The answer
	*/
	vector<string> dataSegmentation(string &str) {
		// Write your code here
		vector<string> res;
		if (str.empty())
			return res;
		string temp;
		//遍历字符串.遇到字母temp加上当前字符,直至遇到空格或标点符号,添加到res
		//遇到标点符号,用当前字符赋值temp,添加到res
		//遇到空格,跳过
		for (int i = 0; i < str.size(); ++i)
		{
			if (ispunct(str[i]))
			{
				if (!temp.empty())
					res.push_back(temp);
				temp = str[i];
				res.push_back(temp);
				temp.clear();
			}
			else if (isalpha(str[i]))
			{
				temp += str[i];
			}
			else
			{
				if (!temp.empty())
					res.push_back(temp);
				temp.clear();
			}
		}
		if (!temp.empty())
			res.push_back(temp);
		return res;
	}
};
#endif