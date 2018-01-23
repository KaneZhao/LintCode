#ifndef C158_H
#define C158_H
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
* �����ַ����Ǳ�λ��
*
* д��һ������ anagram(s, t) �ж������ַ����Ƿ����ͨ���ı���ĸ��˳����һ�����ַ�����
*
* ˵��
* What is Anagram?
* - Two strings are anagram if they can be the same after change the order of characters.
* ����
* ���� s = "abcd"��t="dcab"������ true.
* ���� s = "ab", t = "ab", ���� true.
* ���� s = "ab", t = "ac", ���� false.
* ��ս
* O(n) time, O(1) extra space
*/
class Solution {
public:
	/**
	* @param s: The first string
	* @param b: The second string
	* @return true or false
	*/
	bool anagram(string s, string t) {
		// write your code here
		if (s.empty() || t.empty() || s.size() != t.size())
			return false;
		//��s,t���ֵ�����,���Ƚ��������ַ����Ƿ���ͬ
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t ? true : false;
	}
};
#endif