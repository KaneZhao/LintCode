#ifndef C211_H
#define C211_H
#include<iostream>
#include<string>
#include<map>
using namespace std;
/*
* �ַ����û�
* 
* ���������ַ����������һ���������ж�����һ���ַ����Ƿ�Ϊ��һ���ַ������û���
* �û�����˼�ǣ�ͨ���ı�˳�����ʹ�������ַ�����ȡ�
* ����
* "abc" Ϊ "cba" ���û���
* "aabc" ���� "abcc" ���û���
*/
class Solution {
public:
	/*
	* @param A: a string
	* @param B: a string
	* @return: a boolean
	*/
	bool Permutation(string &A, string &B) {
		// write your code here
		if (A.empty() || B.empty())
		{
			if (A.empty() && B.empty())
				return true;
			else
				return false;
		}
		if (A.size() != B.size())
			return false;
		map<char, int> m;
		for (int i = 0; i < A.size(); ++i)
			m[A[i]]++;
		for (int j = 0; j < B.size(); ++j)
			m[B[j]]--;
		for (int k = 0; k < m.size(); ++k)
		{
			if (m[k] != 0)
			{
				return false;
				break;
			}
		}
		return true;
	}
};
#endif