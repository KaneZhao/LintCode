#ifndef C1366_H
#define C1366_H
#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
/*
* ����ͼ�л�
*
* �����ж�һ�� n ���㣬m ���ߵ�����ͼ�Ƿ���ڻ�������Ϊ����int���飬start[i]��end[i]��һ������ߡ�
* ע������
* 2 <= n <= 10^5
* 1 <= m <= 4*10^5
* 1 <= start[i], end[i] <= n
* ����
* ���� start = [1],end = [2], ����"False"��
* ���ͣ�
* ֻ��1->2һ���ߣ������ڻ�
* ���� start = [1,2,3],end = [2,3,1], ����"True"��
* ���ͣ�
* ����1->2->3->1�����
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
		queue<int> que;//������Ϊ0�Ľڵ�
		map<int, int> m;//��Ž�㼰�����
		for (auto t : start)
			m[t] = 0;
		for (auto c : end)
			m[c]++;
		int size = m.size();//��ȡ�ڵ����
		//�����Ϊ0�Ľڵ����
		for (auto c : m)
		{
			if (c.second == 0)
				que.push(c.first);
		}
		//����ͷ�ڵ�temp����
		//������temp�����Ľڵ㣬���������ڵ����ȼ�һ,����ȱ�Ϊ0,���˽ڵ����
		//cnt++,ֱ��queΪ��
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