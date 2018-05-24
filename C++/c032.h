#ifndef C32_H
#define C32_H
#include<string>
#include<map>
using namespace std;
/*
* ��С�Ӵ�����
*
* ����һ���ַ���source��һ��Ŀ���ַ���target�����ַ���source���ҵ���������Ŀ���ַ�����ĸ���Ӵ���
* ע������
* �����source��û���������Ӵ�������""������ж���������Ӵ���������ʼλ����С���Ӵ���
* ˵��
* �ڴ𰸵��Ӵ��е���ĸ��Ŀ���ַ������Ƿ���Ҫ������ͬ��˳��
* ��������Ҫ��
* ����
* ��source = "ADOBECODEBANC"��target = "ABC" ����Ҫ��Ľ�  "BANC"
* ��ս
* Ҫ��ʱ�临�Ӷ�ΪO(n)
*/
class Solution {
public:
	/**
	* @param source : A string
	* @param target: A string
	* @return: A string denote the minimum window, return "" if there is no such a string
	*/
	string minWindow(string &source, string &target) {
		// write your code here
		if (source.empty() || target.empty())
			return "";
		int slen = source.size();
		int tlen = target.size();
		//beg,end�ֱ��ʾ����Ŀ�ʼ�ͽ���λ��
		int beg = -1, end = slen, minLen = slen, len = 0;
		map<char, int> s, t;
		//t���target�е��ַ�������ִ���
		for (auto c : target)
			t[c]++;
		for (int i = 0, start = 0; i < slen; ++i)
		{
			s[source[i]]++;
			//��t�е��ַ���s�еĳ��ִ���С����t�еĳ��ִ���
			//len++
			if (s[source[i]] <= t[source[i]])
				++len;
			//len=tlen,��ʾĿǰ����target��������ĸ
			if (len == tlen)
			{
				//�ӿ�ͷ�������õ��ַ�(���ַ����ִ���������target�еĳ��ִ���)
				//�����ַ��ĳ��ִ�����һ,start�����һλ
				while (start<i&&s[source[start]]>t[source[start]])
				{
					s[source[start]]--;
					start++;
				}
				//Ѱ����С����
				if (i - start < minLen)
				{
					minLen = i - start;
					beg = start;
					end = i;
				}
				//��start��һλ��ʼ����Ѱ������Ҫ����ַ���
				//������start��һλ���¿�ʼ,��ǰ��source[start]�ĳ��ִ�����һ,�ַ������ȼ�һ
				s[source[start++]]--;
				len--;
			}
		}
		if (beg == -1)
			return "";
		else
			return source.substr(beg, end - beg + 1);
	}
};
#endif