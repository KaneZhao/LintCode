#ifndef C774_H
#define C774_H
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
/*
* Repeated DNA
*
* All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T.
* For example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
* Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
* ����
* Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
* Return ["AAAAACCCCC", "CCCCCAAAAA"].
*/
class Solution {
public:
	/**
	* @param s: a string represent DNA sequences
	* @return: all the 10-letter-long sequences
	*/
	vector<string> findRepeatedDna(string &s) {
		// write your code here
		vector<string> res;
		if (s.empty() || s.size() <= 10)
			return res;
		int len = s.size();
		map<string, int> m;//m�д���Ӵ������Ӧ�ĳ��ִ���
		for (int i = 0; i + 9 < len ; ++i)
		{
			string str = s.substr(i, 10);
			if (m.find(str) == m.end())
			{
				m[str] = 1;
			}
			else
				m[str]++;
		}
		//���ڳ��ִ�������һ�ε��Ӵ�,��ӵ�res��
		for (auto c : m)
		{
			if (c.second > 1)
				res.push_back(c.first);
		}
		return res;
	}
};
#endif