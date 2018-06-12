#ifndef C1401_H
#define C1401_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* �鴤��
*
* ����
* ���������ĵ��ʲ�������������������ͬ����ĸ����������������������ϵ���ĸ����ô����һ���鴤�ʡ����ڸ�һ�����ʣ���������������г鴤��ĸ����ʼ��ͽ����㡣
* ������ַ�������Ϊn��n <= 100000��
* ����
* ���� str = "whaaaaatttsup", ���� [[2,6],[7,9]]��
* ���ͣ�
* "aaaa"��"ttt"�ǳ鴤��ĸ��������ǵ���ʼ��ͽ����㡣
* ���� str = "whooooisssbesssst", ���� [[2,5],[7,9],[12,15]]��
* ���ͣ�
* "ooo"��"sss"��"ssss"���ǳ鴤��ĸ��������ǵ���ʼ��ͽ����㡣
*/
class Solution {
public:
	/**
	* @param str: the origin string
	* @return: the start and end of every twitch words
	*/
	vector<vector<int>> twitchWords(string &str) {
		// Write your code here
		vector<vector<int>> vec;
		if (str.empty())
			return vec;
		int start = -1, end = -1;
		//�����ұ�������,��start��end�ֱ��ʾ������ĸ����ʼλ�úͽ���λ��
		for (int i = 0; i < str.size() - 1; ++i)
		{
			if (str[i] == str[i + 1])
			{
				if (start == -1)
					start = i;
				end = i + 1;
			}
			else
			{
				//������������ͬ����ĸ
				if (end - start >= 2)
				{
					vec.push_back({ start, end });
				}
				start = -1;
				end = -1;
			}
		}
		//��ֹ������©
		if (end - start >= 2)
		{
			vec.push_back({ start, end });
		}
		return vec;
	}
};
#endif