#ifndef C958_H
#define C958_H
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
/*
* 回文数据流
*
* 一个数据流进来，每次一个字母，当前数据流的排列是否能组成回文串。
* 注意事项
* 1 <= |s| <= 10^5
* 样例
* 给出 s = ['a','a','a','a','a'], 返回 [1,1,1,1,1]。
* 解释：
* “a”的排列可以构成回文串
* “aa”的排列可以构成回文串
* “aaa”的排列可以构成回文串
* “aaaa”的排列可以构成回文串
* “aaaaa”的排列可以构成回文串
* 给出 s = ['a','b','a']，返回 [1,0,1]。
* 解释：
* “a”的排列可以构成回文串
* “ab”的排列不可以构成回文串
* “aba”的排列可以构成回文串
*/
class Solution {
public:
	/**
	* @param s: The data stream
	* @return: Return the judgement stream
	*/
	vector<int> getStream(string &s) {
		// Write your code here
		vector<int> res; 
		if (s.empty())
			return res;
		map<char, int> m;
		//只有在出现奇数次的字符个数为0或者1时,输出为1
		//表示当前数据流的排列可以构成回文串
		for (int i = 0; i < s.size(); ++i)
		{
			int num = 0;
			m[s[i] - 'a']++;
			for (auto c : m)
			{
				//出现次数为奇数的字符个数
				if (c.second % 2 == 1)
					num++;
			}
			res.push_back(num>1 ? 0 : 1);
		}
		return res;
	}
};
#endif