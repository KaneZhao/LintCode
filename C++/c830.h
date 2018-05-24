#ifndef C830_H
#define C830_H
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
/*
* 字符串排序
*
* 给出一个字符串，以最常用的字符为第一关键字，字典顺序为第二关键字排序字符串。
* 注意事项
* 字符串长度大小小于10000
* 所有字符均为小写
* 样例
* 给出 str = “bloomberg” , 返回 “bbooeglmr”。
* 解释：
* 'b'出现次数最多，且字典序最小，排名第一，其次是'o'。
* 给出 str = “lintcode”, 返回 “cdeilnot”。
* 解释：
* 所有字符出现次数一样多，所以直接按照字典序排序。
*/
typedef pair<int, long long> node;
bool cmp(const node &a, const node &b)
{
	if (a.second != b.second)
		return a.second > b.second;
	else
		return a.first < b.first;
}
class Solution {
public:
	/**
	* @param str: the string that needs to be sorted
	* @return: sorted string
	*/
	string stringSort(string &str) {
		// Write your code here
		if (str.empty())
			return str;
		map<int, long long> map;
		vector<node> vec;
		for (auto c : str)
		{
			map[c - 'a']++;
		}
		for (auto t : map)
		{
			vec.push_back(make_pair(t.first, t.second));
		}
		sort(vec.begin(), vec.end(), cmp);
		str.clear();
		for (auto t : vec)
		{
			for (long long i = 0; i < t.second; ++i)
			{
				str += 'a' + t.first;
			}
		}
		return str;
	}
};
#endif