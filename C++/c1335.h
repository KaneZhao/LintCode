#ifndef C1335_H
#define C1335_H
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
/*
* Repeated DNA Sequences
&
* 描述
* All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
* Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
* Example:
* Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
* Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/
class Solution {
public:
	/**
	* @param s: a string
	* @return: return List[str]
	*/
	vector<string> findRepeatedDnaSequences(string &s) {
		// write your code here
		vector<string> res;
		if (s.size() < 10)
			return res;
		map<string, int> m;//存放字符串及其出现的次数
		for (int i = 0; i + 10 <= s.size(); ++i)
			m[s.substr(i, 10)]++;
		for (auto c : m)
		{
			if (c.second>1)
				res.push_back(c.first);
		}
		return res;
	}	
};
#endif