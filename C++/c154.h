#ifndef C154_H
#define C154_H
#include<iostream>
#include<string>
using namespace std;
/*
* ������ʽƥ��
* Implement regular expression matching with support for '.' and '*'.
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
* The matching should cover the entire input string (not partial).
* The function prototype should be:
* bool isMatch(string s, string p)
* ����
* isMatch("aa","a") �� false
* isMatch("aa","aa") �� true
* isMatch("aaa","aa") �� false
* isMatch("aa", "a*") �� true
* isMatch("aa", ".*") �� true
* isMatch("ab", ".*") �� true
* isMatch("aab", "c*a*b") �� true
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
	//���캯���ж϶��ڸ�����λ��m,n, s��p�Ƿ�ƥ��
	//��p[n]����ĸ�����n����p�����һλ��p[n + 1] = '*'������ƥ��0��������ĸ��
	//����i + 1��n + 1λ�ã���֤��p[n] == s[i]��; �������p[n] == s[m]������m + 1��n + 1λ�ã� ���򷵻�false��
	// ��p[n] = '.�������n����p�����һλ��p[n+1]='*'������ƥ�����ⳤ���������ݵ��ַ�����
	//����j��n + 1λ�ã�m = < j <= s.size()���� ���򣬴���m + 1��n + 1λ�á�
	// ��p[n] = '*��������������m��n+1λ�á�
	bool helper(string s, string p, int m, int n)
	{
		if (m >= s.size() && n == p.size())//������ֹ����
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
		//�������,nλ�ú��p������x*y*z*��ʽ
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