#ifndef C386_H
#define C386_H
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
/*
* �����k����ͬ�ַ�������ַ���
*
* ����
* ����һ���ַ������ҵ������k����ͬ�ַ�������ַ�����
* ����
* ���磬���� s = "eceba" , k = 3,
* T �� "eceb"������Ϊ 4.
* ��ս
* O(n), n �������ַ����ĳ���
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
		int left = 0, res = 0;//left��ʾ�����k����ͬ�ַ��Ӵ�����ʼλ��,res��ʾ�����������Ӵ�����󳤶�
		map<char, int> m;//����ַ�����Ŀǰ���ֵ����λ��
		//��m�ж���k����ͬ���ַ�ʱ,��left����s[left]Ŀǰ���ֵ����λ��,
		//��m��ֱ��ɾ��s[left],����left����
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