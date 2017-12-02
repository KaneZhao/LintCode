#ifndef C107_H
#define C107_H
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
/*
* ����һ���ַ���s��һ���ʵ䣬�ж��ַ���s�Ƿ���Ա��ո��зֳ�һ�������������ֵ��еĵ��ʡ�
* 
* ����
* s = "lintcode"
* dict = ["lint","code"]
* ���� true ��Ϊ"lintcode"���Ա��ո��зֳ�"lint code"
*/
class Solution {
public:
	/**
	* @param s: A string s
	* @param dict: A dictionary of words dict
	*/
	bool wordBreak(string s, unordered_set<string> &dict) {
		int len = s.size();
		//��ʾ�ַ�תs.substr(0,len)�Ƿ�����г������ֵ��еĵ��ʹ���
		vector<bool> dp(len + 1, false);
		int maxLength = getMaxLength(dict);
		dp[0] = true;
		for (int i = 1; i <= len; ++i)
		{
			//��ǰѰ��,�Ƿ����ĳλ�ü����ֵ��еĵ��ʿ��Ե������ڵ�λ��i
			for (int j = 1; j <= maxLength&&j <= i; ++j)
			{
				if (!dp[i - j])//ǰ�����һλ��������,ֱ������
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
	//���dict�е��ʵ���󳤶�
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