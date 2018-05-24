#ifndef C211_H
#define C211_H
#include<iostream>
#include<string>
#include<map>
using namespace std;
/*
* 字符串置换
* 
* 给定两个字符串，请设计一个方法来判定其中一个字符串是否为另一个字符串的置换。
* 置换的意思是，通过改变顺序可以使得两个字符串相等。
* 样例
* "abc" 为 "cba" 的置换。
* "aabc" 不是 "abcc" 的置换。
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