#ifndef C638_H
#define C638_H
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
* �ַ�ͬ��
*
* ���������ַ��� s �� t ��ȷ�������Ƿ���ͬ���ġ�
* �����ַ�����ͬ������� s �е��ַ����Ա��滻�õ� t��
* ���г��ֵ��ַ���������һ���ַ����棬ͬʱ�����ַ�����˳�� û�������ַ�����ӳ�䵽ͬһ���ַ�����һ���ַ�����ӳ�䵽�Լ���
* ע������
* ����Լٶ������ַ��� s �� t ��һ�����ȵ�.
* ����
* ���� s = "egg", t= "add", ���� true��
* ���� s = "foo", t= "bar", ���� false��
* ���� s = "paper", t= "title", ���� true��
*/
class Solution {
public:
	/*
	* @param s: a string
	* @param t: a string
	* @return: true if the characters in s can be replaced to get t or false
	*/
	bool isIsomorphic(string s, string t) {
		// write your code here
		if (s.empty() && t.empty())
			return true;
		vector<int> ms(127, 0);
		vector<int> mt(127, 0);
		for (auto c : s)
			ms[c - ' ']++;
		for (auto c : t)
			mt[c - ' ']++;
		sort(ms.begin(), ms.end());
		sort(mt.begin(), mt.end());
		return ms == mt;
	}
};
#endif