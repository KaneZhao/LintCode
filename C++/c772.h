#ifndef C772_H
#define C772_H
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
/*
* Group Anagrams
*
* Given an array of strings, group anagrams together.
* 注意事项
* All inputs will be in lower-case.
* 样例
* Given strs = ["eat", "tea", "tan", "ate", "nat", "bat"],
* Return
* [
* ["ate", "eat","tea"],
* ["nat","tan"],
* ["bat"]
* ]
*/
class Solution {
public:
	/**
	* @param strs: the given array of strings
	* @return: The anagrams which have been divided into groups
	*/
	vector<vector<string>> groupAnagrams(vector<string> &strs) {
		// write your code here
		vector<vector<string>> res;
		if (strs.empty())
			return res;
		//构建vector存放字符串中每个字母的出现次数,int型代表字符串在res中的位置
		map<vector<int>, int> mstr;
		for (auto c : strs)
		{
			vector<int> vec(26, 0);
			for (auto t : c)
			{
				vec[t - 'a']++;
			}
			//如果vec存在于mstr中,在res的相应位置上添加vec
			//否则,将{c}添加到res,并将mstr[vec]的值设置为{c}的位置
			if (mstr.find(vec) != mstr.end())
				res[mstr[vec]].push_back(c);
			else
			{
				res.push_back({ c });
				mstr[vec] = res.size() - 1;
			}
		}
		//为了满足答案中的结果按字典排序
		for (auto &c : res)
			sort(c.begin(), c.end());
		sort(res.begin(), res.end());
		return res;
	}
};
#endif