#ifndef C1366_H
#define C1366_H
#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
/*
* 有向图判环
*
* 请你判断一个 n 个点，m 条边的有向图是否存在环。参数为两个int数组，start[i]到end[i]有一条有向边。
* 注意事项
* 2 <= n <= 10^5
* 1 <= m <= 4*10^5
* 1 <= start[i], end[i] <= n
* 样例
* 给出 start = [1],end = [2], 返回"False"。
* 解释：
* 只有1->2一条边，不存在环
* 给出 start = [1,2,3],end = [2,3,1], 返回"True"。
* 解释：
* 存在1->2->3->1这个环
*/
class Solution {
public:
	/**
	* @param start: The start points set
	* @param end: The end points set
	* @return: Return if the graph is cyclic
	*/
	bool isCyclicGraph(vector<int> &start, vector<int> &end) {
		// Write your code here
		queue<int> que;//存放入度为0的节点
		map<int, int> m;//存放结点及其入度
		for (auto t : start)
			m[t] = 0;
		for (auto c : end)
			m[c]++;
		int size = m.size();//获取节点个数
		//将入度为0的节点入队
		for (auto c : m)
		{
			if (c.second == 0)
				que.push(c.first);
		}
		//将队头节点temp出队
		//遍历与temp相连的节点，并将相连节点的入度减一,若入度变为0,将此节点入队
		//cnt++,直至que为空
		int cnt = 0;
		while (!que.empty())
		{
			int temp = que.front();
			que.pop();
			for (int i = 0; i < start.size(); ++i)
			{
				if (start[i] == temp)
				{
					m[end[i]]--;
					if (m[end[i]] == 0)
						que.push(end[i]);
				}
			}
			cnt++;
		}
		return cnt != size;
	}
};
#endif