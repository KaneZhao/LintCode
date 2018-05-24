#ifndef C154_H
#define C154_H
#include<iostream>
#include<string>
using namespace std;
/*
* 正则表达式匹配
* Implement regular expression matching with support for '.' and '*'.
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
* The matching should cover the entire input string (not partial).
* The function prototype should be:
* bool isMatch(string s, string p)
* 样例
* isMatch("aa","a") → false
* isMatch("aa","aa") → true
* isMatch("aaa","aa") → false
* isMatch("aa", "a*") → true
* isMatch("aa", ".*") → true
* isMatch("ab", ".*") → true
* isMatch("aab", "c*a*b") → true
*/
class Solution {
public:
	/**
	* @param s: A string
	* @param p: A string includes "." and "*"
	* @return: A boolean
	*/
	bool isMatch(string s, string p) {
		// write your code here
		return helper(s, p, 0, 0);
	}
	//构造函数判断对于给定的位置m,n, s和p是否匹配
	//若p[n]是字母，如果n不是p的最后一位且p[n + 1] = '*'，可以匹配0个或多个字母，
	//处理i + 1和n + 1位置（保证配p[n] == s[i]）; 否则，如果p[n] == s[m]，处理m + 1和n + 1位置， 否则返回false。
	// 若p[n] = '.’，如果n不是p的最后一位且p[n+1]='*'，可以匹配任意长度任意内容的字符串，
	//处理j和n + 1位置（m = < j <= s.size()）； 否则，处理m + 1和n + 1位置。
	// 若p[n] = '*’，跳过，处理m和n+1位置。
	bool helper(string s, string p, int m, int n)
	{
		if (m >= s.size() && n == p.size())//设置终止条件
			return true;
		else if (m < s.size() && n < p.size())
		{
			if (isalpha(p[n]))            
			{
				if (n < p.size() - 1&&p[n+1]=='*')
				{
					bool blg = helper(s, p, m, n + 1);
					if (p[n] == s[m])
					{						
						for (int i = m; i <= s.size(); ++i)
						{
							if (s[i] == p[n])
								blg = blg || helper(s, p, i + 1, n + 1);
							else
								break;
						}
					}
					return blg;
				}
				else
				{
					if (p[n] == s[m])
						return helper(s, p, m + 1, n + 1);
					else
						return false;
				}
			}
			else if (p[n] == '.')
			{
				if (n < p.size() - 1 && p[n + 1] == '*')
				{
					bool flag = false;
					for (int i = m; i <= s.size(); ++i)
					{
						flag = flag || helper(s, p, i, n + 1);
					}
					return flag;
				}
				else
					return helper(s, p, m + 1, n + 1);
			}
			else                          
			{
				return helper(s, p, m, n + 1);
			}
		}
		//此情况下,n位置后的p必须是x*y*z*形式
		else if (m >= s.size() && n < p.size())
		{
			for (int j = n; j < p.size(); ++j)
			{
				if (isalpha(p[j])||p[j]=='.')
				{
					if (j == p.size() - 1)
						return false;
					else
					{
						if (p[j + 1] != '*')
							return false;
					}
				}
			}
			return true;
		}
		else
			return false;
	}
};
#endif