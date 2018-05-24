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
* ע������
* All inputs will be in lower-case.
* ����
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
		//����vector����ַ�����ÿ����ĸ�ĳ��ִ���,int�ʹ����ַ�����res�е�λ��
		map<vector<int>, int> mstr;
		for (auto c : strs)
		{
			vector<int> vec(26, 0);
			for (auto t : c)
			{
				vec[t - 'a']++;
			}
			//���vec������mstr��,��res����Ӧλ�������vec
			//����,��{c}��ӵ�res,����mstr[vec]��ֵ����Ϊ{c}��λ��
			if (mstr.find(vec) != mstr.end())
				res[mstr[vec]].push_back(c);
			else
			{
				res.push_back({ c });
				mstr[vec] = res.size() - 1;
			}
		}
		//Ϊ��������еĽ�����ֵ�����
		for (auto &c : res)
			sort(c.begin(), c.end());
		sort(res.begin(), res.end());
		return res;
	}
};
#endif