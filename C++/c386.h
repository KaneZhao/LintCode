#ifndef C386_H
#define C386_H
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
/*
* 最多有k个不同字符的最长子字符串
*
* 描述
* 给定一个字符串，找到最多有k个不同字符的最长子字符串。
* 样例
* 例如，给定 s = "eceba" , k = 3,
* T 是 "eceb"，长度为 4.
* 挑战
* O(n), n 是所给字符串的长度
*/
using namespace std;
class Solution {
public:
	/**
	* @param s: A string
	* @param k: An integer
	* @return: An integer
	*/
	int lengthOfLongestSubstringKDistinct(string &s, int k) {
		// write your code here
		if (s.empty())
			return 0;
		int left = 0, res = 0;//left表示最多有k个不同字符子串的起始位置,res表示符合条件的子串的最大长度
		map<char, int> m;//存放字符与其目前出现的最大位置
		//当m中多于k个不同的字符时,若left就是s[left]目前出现的最大位置,
		//在m中直接删除s[left],否则left后移
		for (int i = 0; i < s.size(); ++i)
		{
			m[s[i]] = i;
			while (m.size()>k)
			{
				if (m[s[left]] == left)
					m.erase(s[left]);
				++left;
			}
			res = max(res, i - left + 1);
		}
		return res;
	}
};
#endif