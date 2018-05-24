#ifndef C158_H
#define C158_H
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
* 两个字符串是变位词
*
* 写出一个函数 anagram(s, t) 判断两个字符串是否可以通过改变字母的顺序变成一样的字符串。
*
* 说明
* What is Anagram?
* - Two strings are anagram if they can be the same after change the order of characters.
* 样例
* 给出 s = "abcd"，t="dcab"，返回 true.
* 给出 s = "ab", t = "ab", 返回 true.
* 给出 s = "ab", t = "ac", 返回 false.
* 挑战
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
		//将s,t按字典排序,并比较排序后的字符串是否相同
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t ? true : false;
	}
};
#endif