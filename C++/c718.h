#ifndef C718_H
#define C718_H
#include<iostream>
#include<string>
using namespace std;
/*
* 重复子串
*
* 写一个方法, 给一个由 N 个字符构成的字符串 A和一个由 M 个字符构成的字符串 B, 返回 A 必须重复的次数，使得 B 是重复字符串的子串.如果 B 不可能为重复字符串的子串, 则返回 -1.
*
* 注意事项
* Assume that 0 <= N <= 1000, 1 <= M <= 1000
*
* 样例
* 给出 A = abcd, B = cdabcdab
* 你的方法需要返回 3, 因为在重复字符串 A 3次之后我们得到了字串 abcdabcdabcd. 字符串B是这个字符串的一个子串.
*/
class Solution {
public:
	/*
	* @param : string A to be repeated
	* @param : string B
	* @return: the minimum number of times A has to be repeated
	*/
	int repeatedString(string &A, string &B) {
		// write your code here
		if (A.empty())
			return -1;
		int cnt = 0;
		while (B.find(A) != string::npos)//不断删除B中的A,并计数
		{
			B.erase(B.find(A), A.size());
			cnt++;
		}
		//若删除之后B为空，则直接返回cnt；否则，若B是A的子串，返回cnt + 1，
		//否则，若B是AA的子串，返回cnt + 2，否则返回 - 1
		if (B.empty())
			return cnt;
		if (A.find(B)!=string::npos)
			return cnt + 1;
		else
		{
			A += A;
			if (A.find(B) != string::npos)
				return cnt + 2;
			else
				return -1;
		}
	}
};
#endif