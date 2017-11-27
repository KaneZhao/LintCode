#ifndef C702_H
#define C702_H
#include<iostream>
#include<set>
#include<string>
using namespace std;
/*
* Description
* Two strings are given and you have to modify 1st string such that all the common characters of the 2nd strings have to be 
* removed and the uncommon characters of the 2nd string have to be concatenated with uncommon characters of the 1st string.
* 
* Example
* Given s1 = aacdb, s2 = gafd
* return cbgf
* Given s1 = abcs, s2 = cxzca;
* return bsxz
*/
class Solution {
public:
	/*
	* @param : the 1st string
	* @param : the 2nd string
	* @return: uncommon characters of given strings
	*/
	string concatenetedString(string &s1, string &s2) {
		// write your code here
		if (s1.empty())
			return s2;
		if (s2.empty())
			return s1;
		set<char> set1;
		set<char> set2;
		for (auto c : s2)
			set1.insert(c);
		string str;
		for (auto c : s1)
		{
			if (set1.find(c) == set1.end())
				str += c;
			else
				set2.insert(c);
		}
		for (auto t : s2)
		{
			if (set2.find(t) == set2.end())
				str += t;
		}
		return str;
	}
};
#endif