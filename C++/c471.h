#ifndef C471_H
#define C471_H
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<functional>
using namespace std;
/*
* 最高频的K个单词
*
* 描述
* 给一个单词列表，求出这个列表中出现频次最高的K个单词。
* 你需要按照单词的词频排序后输出，越高频的词排在越前面。如果两个单词出现的次数相同，则词典序小的排在前面。
* 样例
* 给出单词列表：
* [
* "yes", "lint", "code",
* "yes", "code", "baby",
* "you", "baby", "chrome",
* "safari", "lint", "code",
* "body", "lint", "code"
* ]
* 如果 k = 3, 返回 ["code", "lint", "baby"]。
* 如果 k = 4, 返回 ["code", "lint", "baby", "yes"]。
* 挑战
* 用 O（n log k)的时间和 O(n) 的额外空间完成。
*/
//出现次数越多越靠前,出现次数相同按字典序
struct cmp{
	bool operator()(pair<int, string> a, pair<int, string> b)
	{
		if (a.first != b.first)
		{
			return a.first < b.first;
		}
		else
			return a.second>b.second;
	}
};
class Solution {
public:
	/**
	* @param words: an array of string
	* @param k: An integer
	* @return: an array of string
	*/
	vector<string> topKFrequentWords(vector<string> &words, int k) {
		// write your code here
		if (words.empty())
			return words;
		vector<string> res;
		if (k <= 0)
			return res;
		//规范k的值
		if (k > words.size())
			k = words.size();
		map<string, int> m;//存放字符串及其出现次数
		priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> que;//构建符合题意的堆
		for (auto c : words)
			m[c]++;
		//将所有的<字符串,出现次数>放入堆中
		for (auto t : m)
		{
			pair<int, string> temp = make_pair(t.second, t.first);
			que.push(temp);
		}
		//求堆顶的前k个值
		for (int i = 0; i < k; ++i)
		{
			res.push_back(que.top().second);
			que.pop();
		}
		return res;
	}
};
#endif