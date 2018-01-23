#ifndef C55_H
#define C55_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* �Ƚ��ַ���
*
* �Ƚ������ַ���A��B��ȷ��A���Ƿ����B�����е��ַ����ַ���A��B�е��ַ����� ��д��ĸ
* ע������
* �� A �г��ֵ� B �ַ�������ַ�����Ҫ������������
* ����
* ���� A = "ABCD" B = "ACD"������ true
* ���� A = "ABCD" B = "AABC"�� ���� false
*/
class Solution {
public:
	bool compareStrings(string A, string B) {
		// write your code here
		vector<int> vecA(26, 0), vecB(26, 0);
		for (auto a : A)
			vecA[a - 'A']++;
		for (auto b : B)
			vecB[b - 'A']++;
		for (int i = 0; i < 26; ++i)
		{
			if (vecA[i] < vecB[i])
				return false;
		}
		return true;
	}
};
#endif