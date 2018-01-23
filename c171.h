#ifndef C171_H
#define C171_H
#include<iostream>
#include<vector>
#include<string>
#include <map>
using namespace std;
/*
* 乱序字符串
*
* 给出一个字符串数组S，找到其中所有的乱序字符串(Anagram)。如果一个字符串是乱序字符串，那么他存在一个字母集合相同，但顺序不同的字符串也在S中。
* 注意事项
* 所有的字符串都只包含小写字母
* 样例
* 对于字符串数组 ["lint","intl","inlt","code"]
* 返回 ["lint","inlt","intl"]
* 挑战
* What is Anagram?
* - Two strings are anagram if they can be the same after change the order of characters.
*/
class Solution {
public:
	/**
	* @param strs: A list of strings
	* @return: A list of strings
	*/
	vector<string> anagrams(vector<string> &strs) {
		// write your code here
		vector<string> vstr;
		if (strs.empty())
			return vstr;
		map<vector<int>, string> m;//存放字符串中每个字母出现的个数,以及第一个满足前者的字母
		int cnt = 0;
		for (auto c : strs)
		{
			if (c != "")//跳过""
			{
				vector<int> vec(26, 0);
				for (auto t : c)
					vec[t - 'a']++;
				//m中存在vec,m[vec]=""表示c不是第二个乱序字符串
				//m[vec]!=""表示c是第二个乱序字符串,还要考虑到第一个字符串
				if (m.find(vec) != m.end())
				{
					if (m[vec] == "")
						vstr.push_back(c);
					else
					{
						vstr.push_back(m[vec]);
						vstr.push_back(c);
						m[vec] = "";
					}
				}
				else
				{
					m[vec] = c;
				}
			}
			else
			{
				cnt++;
			}
		}
		//cnt>1,表明""也存在乱序字符串,将其添加到vstr后面
		if (cnt > 1)
		{
			while (cnt > 0)
			{
				vstr.push_back("");
				cnt--;
			}
		}
		return vstr;
	}
	
};

#endif