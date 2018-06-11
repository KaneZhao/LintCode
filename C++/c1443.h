#ifndef C1443_H
#define C1443_H
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
/*
* 最长AB子串
*
* 描述
* 给你一个只由字母'A'和'B'组成的字符串s，找一个最长的子串，要求这个子串里面'A'和'B'的数目相等，输出该子串的长度。
* 这个子串可以为空。
* s的长度n满足 2<=n<=1000000。
* 样例
* 给定s="ABAAABBBA"，返回8。
* 解释：
* 子串 s[0,7] 和子串 s[1,8] 满足条件，长度为 8。
* 给定s="AAAAAA"，返回0。
* 解释：
* s 中除了空字串，不存在 'A' 和 'B' 数目相等的子串。
*/
class Solution {
public:
	/**
	* @param S: a String consists of a and b
	* @return: the longest of the longest string that meets the condition
	*/
	int getAns(string &S) {
		// Write your code here
		if (S.find('A') == string::npos || S.find('B') == string::npos || S.empty())
			return 0;
		int len = S.size();
		int maxLen = 0;
		vector<int> vec(len);//存放当前A和B数目的差值
		unordered_map<int, int> m;//存放数目差值及其最大位置
		int temp = 0;
		for (int i = 0; i < len; ++i)
		{
			if (S[i] == 'A')
				temp--;
			else
				temp++;
			vec[i] = temp;
			m[temp] = i;
		}
		//寻找数目差为0的区域
		for (int i = 0; i < len; ++i)
		{
			if (vec[i] != 0)
			{
				maxLen = maxLen >= m[vec[i]] - i ? maxLen : m[vec[i]] - i;
			}
		}
		//为0返回最大位置+1
		if (m.find(0) != m.end())
		{
			if (m[0] + 1>maxLen)
				maxLen = m[0] + 1;
		}
		return maxLen;
	}
};
#endif