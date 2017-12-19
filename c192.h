#ifndef C192_H
#define C192_H
#include<iostream>
#include<string>
#include<map>
using namespace std;
/*
* 通配符匹配
*
* 判断两个可能包含通配符“？”和“*”的字符串是否匹配。匹配规则如下：
* '?' 可以匹配任何单个字符。
* '*' 可以匹配任意字符串（包括空字符串）。
* 两个串完全匹配才算匹配成功。
* 函数接口如下:
* bool isMatch(const char *s, const char *p)
*
* 样例
* 一些例子：
* isMatch("aa","a") → false
* isMatch("aa","aa") → true
* isMatch("aaa","aa") → false
* isMatch("aa", "*") → true
* isMatch("aa", "a*") → true
* isMatch("ab", "?*") → true
* isMatch("aab", "c*a*b") → false
*/
class Solution {
public:
	/*
	* @param s: A string
	* @param p: A string includes "?" and "*"
	* @return: is Match?
	*/
	bool isMatch(string &s, string &p) {
		// write your code here
		map<pair<int, int>, bool> map;//利用map存放计算过的数据,减少运算量
		return helper(s, p, 0, 0,map);
	}
	bool helper(string &s, string &p, int m, int n,map<pair<int,int>,bool> &map)
	{
		pair<int, int> pairVal = make_pair(m, n);
		if (map.find(pairVal) != map.end())
			return map[pairVal];
		if (m >= s.size() && n == p.size())//设定终止条件
			return true;
		else if (m < s.size() && n < p.size())
		{
			if (isalpha(p[n]))            //p中元素为字母的情况，直接判断与s[m]是否相等
			{
				if (p[n] == s[m])
					return helper(s, p, m + 1, n + 1,map);
				else
				{
					map[pairVal] = false;
					return false;
				}
			}
			else if (p[n] == '?')         //p中元素为'?',可以匹配任一单个字符,直接处理下一位
				return helper(s, p, m + 1, n + 1,map);
			else                          //p中元素为'*',循环判断是否存在满足条件的情况
			{
				bool flag = false;
				for (int i = m; i <= s.size(); ++i)
				{
					flag = flag || helper(s, p, i, n + 1,map);
				}
				map[pairVal] = flag;
				return flag;
			}
		}          
		//此时p[n]只能为'*'
		else if (m >= s.size() && n < p.size())
		{
			for (int j = n; j < p.size(); ++j)
			{
				if (p[j] != '*')
					return false;
			}
			return true;
		}
		else
			return false;
	}
};
#endif