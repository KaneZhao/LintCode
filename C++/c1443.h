#ifndef C1443_H
#define C1443_H
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
/*
* �AB�Ӵ�
*
* ����
* ����һ��ֻ����ĸ'A'��'B'��ɵ��ַ���s����һ������Ӵ���Ҫ������Ӵ�����'A'��'B'����Ŀ��ȣ�������Ӵ��ĳ��ȡ�
* ����Ӵ�����Ϊ�ա�
* s�ĳ���n���� 2<=n<=1000000��
* ����
* ����s="ABAAABBBA"������8��
* ���ͣ�
* �Ӵ� s[0,7] ���Ӵ� s[1,8] ��������������Ϊ 8��
* ����s="AAAAAA"������0��
* ���ͣ�
* s �г��˿��ִ��������� 'A' �� 'B' ��Ŀ��ȵ��Ӵ���
*/
class Solution {
public:
	/**
	* @param S: a String consists of a and b
	* @return: the longest of the longest string that meets the condition
	*/
	int getAns(string &S) {
		// Write your code here
		if (S.find('A') == string::npos || S.find('B') == string::npos || S.empty())
			return 0;
		int len = S.size();
		int maxLen = 0;
		vector<int> vec(len);//��ŵ�ǰA��B��Ŀ�Ĳ�ֵ
		unordered_map<int, int> m;//�����Ŀ��ֵ�������λ��
		int temp = 0;
		for (int i = 0; i < len; ++i)
		{
			if (S[i] == 'A')
				temp--;
			else
				temp++;
			vec[i] = temp;
			m[temp] = i;
		}
		//Ѱ����Ŀ��Ϊ0������
		for (int i = 0; i < len; ++i)
		{
			if (vec[i] != 0)
			{
				maxLen = maxLen >= m[vec[i]] - i ? maxLen : m[vec[i]] - i;
			}
		}
		//Ϊ0�������λ��+1
		if (m.find(0) != m.end())
		{
			if (m[0] + 1>maxLen)
				maxLen = m[0] + 1;
		}
		return maxLen;
	}
};
#endif