#ifndef C683_H
#define C683_H
#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
class Solution {
public:
	/*
	* @param : A string
	* @param : A set of word
	* @return: the number of possible sentences.
	*/
	int wordBreak3(string& s, unordered_set<string>& dict) {
		// Write your code here
		if (s.empty() || dict.empty())
			return 0;
		int num = 0;
		helper(s, dict, 0, num);
		return num;
	}
	//pos表示字符串的当前位置,num表示可以组成语句的个数
	void helper(string &s, unordered_set<string>& dict, int pos,int &num)
	{
		if (pos == s.size())//已经遍历玩字符串,num++
		{
			num++;
			return;
		}
		string str;
		//从当前位置向后取字符串,若存在于set中,改变pos的值,深度搜索
		for (int j = 1; j <= s.size() - pos; ++j)
		{
			str = s.substr(pos, j);
			if (dict.find(str) != dict.end())
			{
				helper(s, dict, pos + j, num);
			}
		}
	}
};
#endif