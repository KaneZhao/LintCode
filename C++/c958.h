#ifndef C958_H
#define C958_H
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
/*
* ����������
*
* һ��������������ÿ��һ����ĸ����ǰ�������������Ƿ�����ɻ��Ĵ���
* ע������
* 1 <= |s| <= 10^5
* ����
* ���� s = ['a','a','a','a','a'], ���� [1,1,1,1,1]��
* ���ͣ�
* ��a�������п��Թ��ɻ��Ĵ�
* ��aa�������п��Թ��ɻ��Ĵ�
* ��aaa�������п��Թ��ɻ��Ĵ�
* ��aaaa�������п��Թ��ɻ��Ĵ�
* ��aaaaa�������п��Թ��ɻ��Ĵ�
* ���� s = ['a','b','a']������ [1,0,1]��
* ���ͣ�
* ��a�������п��Թ��ɻ��Ĵ�
* ��ab�������в����Թ��ɻ��Ĵ�
* ��aba�������п��Թ��ɻ��Ĵ�
*/
class Solution {
public:
	/**
	* @param s: The data stream
	* @return: Return the judgement stream
	*/
	vector<int> getStream(string &s) {
		// Write your code here
		vector<int> res; 
		if (s.empty())
			return res;
		map<char, int> m;
		//ֻ���ڳ��������ε��ַ�����Ϊ0����1ʱ,���Ϊ1
		//��ʾ��ǰ�����������п��Թ��ɻ��Ĵ�
		for (int i = 0; i < s.size(); ++i)
		{
			int num = 0;
			m[s[i] - 'a']++;
			for (auto c : m)
			{
				//���ִ���Ϊ�������ַ�����
				if (c.second % 2 == 1)
					num++;
			}
			res.push_back(num>1 ? 0 : 1);
		}
		return res;
	}
};
#endif