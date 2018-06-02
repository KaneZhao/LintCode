#ifndef C1413_H
#define C1413_H
#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
/*
* 树
*
* 描述
* 给出两个list x，y，代表x[i]与y[i]之间有一条边，整个边集构成一棵树，1为根，现在有个list a,b，表示询问节点a[i]与b[i]是什么关系，如果a[i]与b[i]是兄弟，即有同一个父节点，输出1，如果a[i]与b[i]是父子关系，输出2，否则输出0。
* 节点数不大于100000。
* 所以的数均为不大于100000的正整数
* 样例
* 给出 x = [1,1], y = [2,3], a =[1,2], b = [2,3], 返回[2,1]。
* 解释：
* 1与2是父子关系，2与3是兄弟关系，它们的共同父节点为1。
* 给出 x = [1,1,2], y = [2,3,4], a = [1,2,1], b = [2,3,4], 返回[2,1,0]。
* 解释：
* 1与2是父子关系，2与3是兄弟关系，它们的共同父节点为1，1与4不是兄弟关系也不是父子关系。
*/
class Solution {
public:
	/**
	* @param x: The x
	* @param y: The y
	* @param a: The a
	* @param b: The b
	* @return: The Answer
	*/
	vector<int> tree(vector<int> &x, vector<int> &y, vector<int> &a, vector<int> &b) {
		// Write your code here
		vector<int> res;
		if (x.empty() || y.empty() || a.empty() || b.empty())
			return res;
		vector<vector<int>> vec(100001, vector<int>());//存放结点的对应关系
		map<int, int> dic;//存放结点及其父节点
		for (int i = 0; i < x.size(); ++i)
		{
			vec[x[i]].push_back(y[i]);
			vec[y[i]].push_back(x[i]);
		}
		//构建vec
		dfs(1, 0, dic, vec);
		for (int i = 0; i < a.size(); ++i)
			res.push_back(getRelationship(a[i], b[i], dic));
		return res;
	}
	void dfs(int node, int root, map<int, int> &dic, vector<vector<int>> &vec)
	{
		dic[node] = root;
		for (auto c : vec[node])
		{
			if (c != root)
			{
				dfs(c, node, dic, vec);
			}
		}
	}
	//返回两个节点的关系
	int getRelationship(int node1, int node2, map<int, int> dic)
	{
		if (dic[node1] == node2 || dic[node2] == node1)
			return 2;
		else if (dic[node1] == dic[node2])
			return 1;
		return 0;
	}
};
#endif