#ifndef C209_H
#define C209_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* First Unique Character in a String
*
* ����һ���ַ������ҳ���һ��ֻ����һ�ε��ַ���
* ����
* ���� "abaccdeff", 'b'Ϊ��һ��ֻ����һ�ε��ַ�.
*/
class Solution {
public:
	/**
	* @param str: str: the given string
	* @return: char: the first unique character in a given string
	*/
	char firstUniqChar(string &str) {
		// Write your code here
		vector<int> dic(26, -1);//����ַ���һ�γ��ֵ�λ��
		//�Ӻ���ǰ�����ַ���,dic[pos]����-1��ʾ֮ǰû�г���
		//����Ǹ�,��֮ǰ���ֹ�,��Ϊ-2,�����������д���
		for (int i = str.size() - 1; i >= 0; --i)
		{
			int pos = str[i] - 'a';
			if (dic[pos] == -1)
			{
				dic[pos] = i;
			}
			else
			{
				if (dic[pos] >= 0)
				{
					dic[pos] = -2;
				}
			}
		}
		//��dic��Ѱ��ֵ�Ǹ�����С��λ��,�����������ַ�
		int res = INT_MAX;
		int tmp = 0;
		for (int i = 0; i < dic.size(); ++i)
		{
			if (dic[i]<res&&dic[i]>=0)
			{
				res = dic[i];
				tmp = i;
			}
		}
		return 'a' + tmp;
	}
};
#endif