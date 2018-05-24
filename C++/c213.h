#ifndef C213_H
#define C213_H
#include<iostream>
#include<string>
using namespace std;
/*
* �ַ���ѹ��
*
* ����
* ���һ�ַ�����ͨ�����ظ��ַ����������л������ַ���ѹ����
* ���磬�ַ��� aabcccccaaa ��ѹ��Ϊ a2b1c5a3 �������ѹ������ַ�����С��ԭʼ���ַ������򷵻�ԭʼ���ַ�����
* ���Լ����ַ���������a-z����ĸ��
* ����
* str=aabcccccaaa ���� a2b1c5a3
* str=aabbcc ���� aabbcc
* str=aaaa ���� a4
*/
class Solution {
public:
	/**
	* @param str: a string
	* @return: a compressed string
	*/
	string compress(string &str) {
		// write your code here
		if (str.empty() || str.size() == 1)
			return str;
		string res;
		int num = 1;//��ʾ�ַ����ֵĴ���
		char c = str[0];
		for (int i = 1; i < str.size(); ++i)
		{
			if (c == str[i])
			{
				num++;
			}
			else
			{
				res += c + to_string(num);
				c = str[i];
				num = 1;
			}
			//��������ĩβ,���c�Ͷ�Ӧ��num
			if (i == str.size() - 1)
			{
				res += c + to_string(num);
			}
		}
		//����ԭ�ַ�����ѹ�����ַ������Ƚ�С��
		return res.size() < str.size() ? res : str;
	}
};
#endif