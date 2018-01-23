#ifndef C55_H
#define C55_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* 比较字符串
*
* 比较两个字符串A和B，确定A中是否包含B中所有的字符。字符串A和B中的字符都是 大写字母
* 注意事项
* 在 A 中出现的 B 字符串里的字符不需要连续或者有序。
* 样例
* 给出 A = "ABCD" B = "ACD"，返回 true
* 给出 A = "ABCD" B = "AABC"， 返回 false
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