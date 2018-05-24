#ifndef C734_H
#define C734_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* 形式为a^i b^j c^k的子序列数量
*
* 给一字符串, 对形式为 a^i b^j c^k 的子序列进行计数, 即它由 i 个字符 a, 接着是 j 个字符 b, 然后是 k 个字符 c组成, i >= 1, j >= 1, k >= 1.
* Note: 如果两个子序列在原字符串中的index集合是不同的，则认为两个子序列不同。
*
* 样例
* 给定 s = abbc, 返回 3 子序列为 abc, abc 和 abbc
* 给定 s = abcabc, 返回 7 子序列为 abc, abc, abbc, aabc, abcc, abc 和 abc
*/
class Solution {
public:
	/*
	* @param : the input string
	* @return: the number of subsequences
	*/
	int countSubsequences(string &source) {
		// write your code here
		int a = 0, b = 0, c = 0;
		for (auto t : source)
		{
			if (t == 'a')
				a = 2 * a + 1;//每个a可以取代前面的a,或者跟随前一个的a,或者作为新的开始
			else if (t == 'b')
				b = a + 2 * b;//每个b可以跟随前面的a,或者跟随前一个的b,或者取代前一个的b
			else if (t == 'c')
				c = b + c * 2;//每个c可以跟随前面的b,或者跟随前一个的c,或者取代前一个的c
		}
		return c;
	}
};
#endif