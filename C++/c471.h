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
* ���Ƶ��K������
*
* ����
* ��һ�������б��������б��г���Ƶ����ߵ�K�����ʡ�
* ����Ҫ���յ��ʵĴ�Ƶ����������Խ��Ƶ�Ĵ�����Խǰ�档����������ʳ��ֵĴ�����ͬ����ʵ���С������ǰ�档
* ����
* ���������б�
* [
* "yes", "lint", "code",
* "yes", "code", "baby",
* "you", "baby", "chrome",
* "safari", "lint", "code",
* "body", "lint", "code"
* ]
* ��� k = 3, ���� ["code", "lint", "baby"]��
* ��� k = 4, ���� ["code", "lint", "baby", "yes"]��
* ��ս
* �� O��n log k)��ʱ��� O(n) �Ķ���ռ���ɡ�
*/
//���ִ���Խ��Խ��ǰ,���ִ�����ͬ���ֵ���
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
		//�淶k��ֵ
		if (k > words.size())
			k = words.size();
		map<string, int> m;//����ַ���������ִ���
		priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> que;//������������Ķ�
		for (auto c : words)
			m[c]++;
		//�����е�<�ַ���,���ִ���>�������
		for (auto t : m)
		{
			pair<int, string> temp = make_pair(t.second, t.first);
			que.push(temp);
		}
		//��Ѷ���ǰk��ֵ
		for (int i = 0; i < k; ++i)
		{
			res.push_back(que.top().second);
			que.pop();
		}
		return res;
	}
};
#endif