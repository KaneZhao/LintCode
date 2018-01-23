#ifndef C171_H
#define C171_H
#include<iostream>
#include<vector>
#include<string>
#include <map>
using namespace std;
/*
* �����ַ���
*
* ����һ���ַ�������S���ҵ��������е������ַ���(Anagram)�����һ���ַ����������ַ�������ô������һ����ĸ������ͬ����˳��ͬ���ַ���Ҳ��S�С�
* ע������
* ���е��ַ�����ֻ����Сд��ĸ
* ����
* �����ַ������� ["lint","intl","inlt","code"]
* ���� ["lint","inlt","intl"]
* ��ս
* What is Anagram?
* - Two strings are anagram if they can be the same after change the order of characters.
*/
class Solution {
public:
	/**
	* @param strs: A list of strings
	* @return: A list of strings
	*/
	vector<string> anagrams(vector<string> &strs) {
		// write your code here
		vector<string> vstr;
		if (strs.empty())
			return vstr;
		map<vector<int>, string> m;//����ַ�����ÿ����ĸ���ֵĸ���,�Լ���һ������ǰ�ߵ���ĸ
		int cnt = 0;
		for (auto c : strs)
		{
			if (c != "")//����""
			{
				vector<int> vec(26, 0);
				for (auto t : c)
					vec[t - 'a']++;
				//m�д���vec,m[vec]=""��ʾc���ǵڶ��������ַ���
				//m[vec]!=""��ʾc�ǵڶ��������ַ���,��Ҫ���ǵ���һ���ַ���
				if (m.find(vec) != m.end())
				{
					if (m[vec] == "")
						vstr.push_back(c);
					else
					{
						vstr.push_back(m[vec]);
						vstr.push_back(c);
						m[vec] = "";
					}
				}
				else
				{
					m[vec] = c;
				}
			}
			else
			{
				cnt++;
			}
		}
		//cnt>1,����""Ҳ���������ַ���,������ӵ�vstr����
		if (cnt > 1)
		{
			while (cnt > 0)
			{
				vstr.push_back("");
				cnt--;
			}
		}
		return vstr;
	}
	
};

#endif