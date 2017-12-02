#ifndef C107_H
#define C107_H
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
/*
* 给出一个字符串s和一个词典，判断字符串s是否可以被空格切分成一个或多个出现在字典中的单词。
* 
* 样例
* s = "lintcode"
* dict = ["lint","code"]
* 返回 true 因为"lintcode"可以被空格切分成"lint code"
*/
class Solution {
public:
	/**
	* @param s: A string s
	* @param dict: A dictionary of words dict
	*/
	bool wordBreak(string s, unordered_set<string> &dict) {
		int len = s.size();
		//表示字符转s.substr(0,len)是否可以有出现在字典中的单词构成
		vector<bool> dp(len + 1, false);
		int maxLength = getMaxLength(dict);
		dp[0] = true;
		for (int i = 1; i <= len; ++i)
		{
			//向前寻找,是否存在某位置加上字典中的单词可以到达现在的位置i
			for (int j = 1; j <= maxLength&&j <= i; ++j)
			{
				if (!dp[i - j])//前面的那一位都不可以,直接跳过
					continue;
				string str = s.substr(i - j, j);
				if (dict.find(str) != dict.end())
				{
					dp[i] = true;
					break;
				}
			}
		}
		return dp[len];
	}
	//获得dict中单词的最大长度
	int getMaxLength(unordered_set<string> &dict)
	{
		int maxLen = 0;
		for (auto c : dict)
		{
			if (c.size() > maxLen)
				maxLen = c.size();
		}
		return maxLen;
	}
};
#endif