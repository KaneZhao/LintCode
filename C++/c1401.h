#ifndef C1401_H
#define C1401_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* 抽搐词
*
* 描述
* 我们正常的单词不会有连续两个以上相同的字母，如果出现连续三个或以上的字母，那么这是一个抽搐词。现在给一个单词，从左至右求出所有抽搐字母的起始点和结束点。
* 输入的字符串长度为n，n <= 100000。
* 样例
* 给出 str = "whaaaaatttsup", 返回 [[2,6],[7,9]]。
* 解释：
* "aaaa"和"ttt"是抽搐字母，输出他们的起始点和结束点。
* 给出 str = "whooooisssbesssst", 返回 [[2,5],[7,9],[12,15]]。
* 解释：
* "ooo"和"sss"和"ssss"都是抽搐字母，输出他们的起始点和结束点。
*/
class Solution {
public:
	/**
	* @param str: the origin string
	* @return: the start and end of every twitch words
	*/
	vector<vector<int>> twitchWords(string &str) {
		// Write your code here
		vector<vector<int>> vec;
		if (str.empty())
			return vec;
		int start = -1, end = -1;
		//从左到右遍历数组,将start和end分别表示连续字母的起始位置和结束位置
		for (int i = 0; i < str.size() - 1; ++i)
		{
			if (str[i] == str[i + 1])
			{
				if (start == -1)
					start = i;
				end = i + 1;
			}
			else
			{
				//至少有三个相同的字母
				if (end - start >= 2)
				{
					vec.push_back({ start, end });
				}
				start = -1;
				end = -1;
			}
		}
		//防止出现遗漏
		if (end - start >= 2)
		{
			vec.push_back({ start, end });
		}
		return vec;
	}
};
#endif