#ifndef C807_H
#define C807_H
#include<iostream>
#include<string>
using namespace std;
/*
* ������ II
*
* �ж�һ���Ǹ����� n �Ķ����Ʊ�ʾ�Ƿ�Ϊ������
* ע������
* ���Ǳ�֤ 0 <= n <= 2^32 - 1
* ����
* ���� n = 0������True��
* ���ͣ�
* 0 �Ķ����Ʊ�ʾΪ��0��
* ���� n = 3������True��
* ���ͣ�
* 3 �Ķ����Ʊ�ʾΪ��11��
* ���� n = 4������False��
* ���ͣ�
* 4 �Ķ����Ʊ�ʾΪ��100��
* ���� n = 6������False��
* ���ͣ�
* 6 �Ķ����Ʊ�ʾΪ��110��
*/
class Solution {
public:
	/**
	* @param n: non-negative integer n
	* @return: return whether a binary representation of a non-negative integer n is a palindrome.
	*/
	bool isPalindrome(int n) {
		// Write your code here
		string res = change(n);
		int l = 0, r = res.size() - 1;
		//�ж��Ƿ��ǻ��Ĵ�
		while (l < r)
		{
			if (res[l] != res[r])
				return false;
			l++;
			r--;
		}
		return true;
	}
	//������ת��Ϊ������,�����ַ�����ʾ
	string change(int n)
	{
		string res;
		int m = 1;
		for (int i = 0; i < 32; ++i,m=m<<1)
		{
			if (n&m)
				res = "1" + res;
			else
				res = "0" + res;
		}
		//ȥ��ǰ������0
		if (res.find("1") == string::npos)
			res = "0";
		else
			res = res.substr(res.find("1"));
		return res;
	}
};
#endif