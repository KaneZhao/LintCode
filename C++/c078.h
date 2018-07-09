#ifndef C78_H
#define C78_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
* �����ǰ׺
*
* ����
* ��k���ַ�����������ǵ������ǰ׺(LCP)
* ����
* �� "ABCD" "ABEF" �� "ACEF" ��,  LCP Ϊ "A"
* �� "ABCDEFG", "ABCEFG", "ABCEFA" ��, LCP Ϊ "ABC"
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
		int pos = 0;//�����ǰ׺�ĸ���
		//����strs[0][i],�ж�strs���Ƿ�����strs[j][i]==strs[0][i]
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