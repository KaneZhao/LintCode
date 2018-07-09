#ifndef C78_H
#define C78_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
* 最长公共前缀
*
* 描述
* 给k个字符串，求出他们的最长公共前缀(LCP)
* 样例
* 在 "ABCD" "ABEF" 和 "ACEF" 中,  LCP 为 "A"
* 在 "ABCDEFG", "ABCEFG", "ABCEFA" 中, LCP 为 "ABC"
*/
class Solution {
public:
	/**
	* @param strs: A list of strings
	* @return: The longest common prefix
	*/
	string longestCommonPrefix(vector<string> &strs) {
		// write your code here
		if (strs.empty())
			return "";
		if (strs.size() == 1)
			return strs[0];
		int pos = 0;//最长公共前缀的个数
		//对于strs[0][i],判断strs中是否满足strs[j][i]==strs[0][i]
		for (int i = 0; i < strs[0].size(); ++i)
		{
			int num = 0;
			for (int j = 0; j < strs.size(); ++j)
			{
				if (j == 0)
					num = strs[j][i] - 'a';
				if (i == strs[j].size() || strs[j][i] - 'a' != num)
				{
					return strs[0].substr(0, pos);
				}
			}
			pos++;
		}
		return pos==0?"":strs[0].substr(0,pos);
	}
};
#endif