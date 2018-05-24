#ifndef C638_H
#define C638_H
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 字符同构
*
* 给定两个字符串 s 和 t ，确定它们是否是同构的。
* 两个字符串是同构的如果 s 中的字符可以被替换得到 t。
* 所有出现的字符必须用另一个字符代替，同时保留字符串的顺序。 没有两个字符可以映射到同一个字符，但一个字符可以映射到自己。
* 注意事项
* 你可以假定两个字符串 s 和 t 是一样长度的.
* 样例
* 给出 s = "egg", t= "add", 返回 true。
* 给出 s = "foo", t= "bar", 返回 false。
* 给出 s = "paper", t= "title", 返回 true。
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