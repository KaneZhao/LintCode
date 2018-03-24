#ifndef C805_H
#define C805_H
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
/*
* 最大关联集合
*
* 亚麻卖书，每本书都有与其关联性很强的书，给出ListA与ListB，表示ListA[i]与ListB[i]有关联，输出互相关联的最大集合。(输出任意顺序)，题目保证只有一个最大的集合。
* 注意事项
* 书籍的数量不会超过5000。
* 样例
* 给出ListA = ["abc","abc","abc"], ListB = ["bcd","acd","def"], 返回 ["abc","acd","bcd","dfe"]。
* 解释：
* abc与bcd,acd,dfe均有关联，所以最大的集合就是全部书籍构成的集合。
* 给出 ListA = ["a","b","d","e","f"], ListB = ["b","c","e","g","g"], 返回["d","e","g","f"]。
* 解释：
* 当前的集合有[a,b,c],[d,e,g,f],那么最大的集合是[d,e,g,f]。
*/
class Solution {
public:
	/**
	* @param ListA: The relation between ListB's books
	* @param ListB: The relation between ListA's books
	* @return: The answer
	*/
	vector<string> maximumAssociationSet(vector<string> &ListA, vector<string> &ListB) {
		// Write your code here
		vector<string> res;
		if (ListA.empty() || ListB.empty())
			return res;
		map<string, string> m;
		map<string, int> count;
		//m存放ListA,ListB中出现的所有的字符串,并初始化
		for (auto c : ListA)
		{
			if (m.find(c) == m.end())
				m[c] = c;
		}
		for (auto t : ListB)
		{
			if (m.find(t) == m.end())
				m[t] = t;
		}
		//对于每对有关联性的书籍,求其最高层的书籍,并进行合并
		for (int i = 0; i < ListA.size(); ++i)
		{
			string root1 = unionSearch(ListA[i], m);
			string root2 = unionSearch(ListB[i], m);
			if (root1 != root2)
				m[root1] = root2; 
		}
		//对m进行路径压缩
		for (auto &c : m)
		{
			c.second = unionSearch(c.first, m);
		}
		//存放最高层书籍,与这些书籍相关书籍的本数
		for (auto c : m)
		{
			count[c.second]++;
		}
		//计算与高层书籍相关的最大本书和最高层书籍的书名
		int max = INT_MIN;
		string str;
		for (auto p : count)
		{
			if (p.second >= max)
			{
				str = p.first;
				max = p.second;
			}
		}
		//根据书名找到相关书籍
		for (auto t : m)
		{
			if (t.second == str)
				res.push_back(t.first);
		}
		return res;
	}
	//找到root的最高层结点
	string unionSearch(string root, map<string, string> &m)
	{
		while (root != m[root])
		{
			m[root] = m[m[root]];
			root = m[root];
		}
		return root;
	}
};
#endif