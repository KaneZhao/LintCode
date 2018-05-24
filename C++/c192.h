#ifndef C192_H
#define C192_H
#include<iostream>
#include<string>
#include<map>
using namespace std;
/*
* ͨ���ƥ��
*
* �ж��������ܰ���ͨ����������͡�*�����ַ����Ƿ�ƥ�䡣ƥ��������£�
* '?' ����ƥ���κε����ַ���
* '*' ����ƥ�������ַ������������ַ�������
* ��������ȫƥ�����ƥ��ɹ���
* �����ӿ�����:
* bool isMatch(const char *s, const char *p)
*
* ����
* һЩ���ӣ�
* isMatch("aa","a") �� false
* isMatch("aa","aa") �� true
* isMatch("aaa","aa") �� false
* isMatch("aa", "*") �� true
* isMatch("aa", "a*") �� true
* isMatch("ab", "?*") �� true
* isMatch("aab", "c*a*b") �� false
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
		map<pair<int, int>, bool> map;//����map��ż����������,����������
		return helper(s, p, 0, 0,map);
	}
	bool helper(string &s, string &p, int m, int n,map<pair<int,int>,bool> &map)
	{
		pair<int, int> pairVal = make_pair(m, n);
		if (map.find(pairVal) != map.end())
			return map[pairVal];
		if (m >= s.size() && n == p.size())//�趨��ֹ����
			return true;
		else if (m < s.size() && n < p.size())
		{
			if (isalpha(p[n]))            //p��Ԫ��Ϊ��ĸ�������ֱ���ж���s[m]�Ƿ����
			{
				if (p[n] == s[m])
					return helper(s, p, m + 1, n + 1,map);
				else
				{
					map[pairVal] = false;
					return false;
				}
			}
			else if (p[n] == '?')         //p��Ԫ��Ϊ'?',����ƥ����һ�����ַ�,ֱ�Ӵ�����һλ
				return helper(s, p, m + 1, n + 1,map);
			else                          //p��Ԫ��Ϊ'*',ѭ���ж��Ƿ�����������������
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
		//��ʱp[n]ֻ��Ϊ'*'
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