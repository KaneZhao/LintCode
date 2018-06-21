#ifndef C1352_H
#define C1352_H
#include<iostream>
#include<string>
using namespace std;
/*
* Compare Version Numbers
*
* ����
* Compare two version numbers version1 and version2.
* If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
* You may assume that the version strings are non-empty and contain only digits and the . character.
* The . character does not represent a decimal point and is used to separate number sequences.
* For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
* ����
* Here is an example of version numbers ordering:
* 0.1 < 1.1 < 1.2 < 13.37
*/
class Solution {
public:
	/**
	* @param version1: the first given number
	* @param version2: the second given number
	* @return: the result of comparing
	*/
	int compareVersion(string &version1, string &version2) {
		// Write your code here
		int len1 = version1.size(), len2 = version2.size();
		int i = 0, j = 0;
		string str1, str2;//��ʾ��ż���Ӵ�
		bool flag1 = false, flag2 = false;//��ʾ�Ƿ����˵��
		while (i < len1||j < len2)
		{
			if (i<len1 && version1[i] != '.')
			{
				if (flag1)
				{
					flag1 = false;
					str1.clear();
				}
				str1 += version1[i];
				++i;
			}
			else
				flag1 = true;
			if (j<len2 && version2[j] != '.')
			{
				if (flag2)
				{
					flag2 = false;
					str2.clear();
				}
				str2 += version2[j];
				++j;
			}
			else
				flag2 = true;
			//�����߶��ڵ����,�Ƚ��ַ����Ĵ�С
			if (flag1&&flag2)
			{
				int temp = strCompare(str1, str2);
				if (temp > 0)
					return 1;
				else if (temp < 0)
					return -1;
				else
				{
					++i;
					++j;
				}
			}
		}
		return strCompare(str1,str2);
	}
	//�ж�str1��str2�Ĵ�С,str1>str2,����1;str1<str2,����-1;��ȷ���0
	int strCompare(string &str1, string &str2)
	{
		//���ַ���ǰ���'0',ʹ�ö��߳������
		int len1 = str1.size(), len2 = str2.size();
		if (len1 > len2)
		{
			for (int i = 0; i < len1 - len2; ++i)
				str2 = '0' + str2;
		}
		else
		{
			for (int i = 0; i < len2 - len1; ++i)
				str1 = '0' + str1;
		}
		//�Ƚ��ַ���
		int size = str1.size();
		for (int i = 0; i < size; ++i)
		{
			if (str1[i]>str2[i])
				return 1;
			else if (str1[i] < str2[i])
				return -1;
		}
		return 0;
	}
};
#endif