#ifndef C953_H
#define C953_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
* �������÷�
*
* һ�� n �����Ķ�����������Ϊ[0, n - 1]�������ı��Ϊ 0��ÿ�������һ�����棬���������ˣ��Ϳ��Լ�������������棻ÿ������һ�����ѣ������������ߣ���Ҫ��ȥ�����ߵĻ��ѡ��ʣ��Ӹ�����ߵ�����һ��Ҷ�ӽ����ܵ÷֣��ܵ÷� = ������ - �ܻ��ѣ����Ϊ���٣�
* ע������
* x[i], y[i] ����� i ���ߵ�������㣬cost[i] ����� i ���ߵĻ��ѣ�profit[i] ������Ϊ i �Ľ�������
* 1 <= x[i], y[i] <= 10^5
* 1 <= cost[i], profit[i] <= 100
* ����
* ���� x = [0,0,0],y = [1,2,3], cost = [1,1,1], profit = [1,1,2,3]������3��
* ·�ߣ�0��3
* ���� x = [0,0],y = [1,2], cost =[1,2], profit = [1,2,5]������4��
* ·�ߣ�0��2
*/
class Solution {
public:
	/**
	* @param x: The vertex of edge
	* @param y: The another vertex of edge
	* @param cost: The cost of edge
	* @param profit: The profit of vertex
	* @return: Return the max score
	*/
	int getMaxScore(vector<int> &x, vector<int> &y, vector<int> &cost, vector<int> &profit) {
		// Write your code here
		int n = x.size() + 1;
		vector<int> nums(n, INT_MIN);//��Ž��ĵ÷�
		nums[0] = profit[0];
		vector<vector<int>> tree(n);//��Ž�㼰������
		map<pair<int, int>, int> m;//���ÿ���ߵĻ���
		int res = INT_MIN;
		//��x[i]Ϊ�����,y[i]Ϊ�ӽ�㹹�����ϵ
		for (int i = 0; i < x.size(); ++i)
		{
			tree[x[i]].push_back(y[i]);
		}
		//�ø��ӹ�ϵ��ʾÿһ����,���洢�仨��
		for (int i = 0; i < x.size(); ++i)
		{
			m[make_pair(x[i], y[i])] = cost[i];
		}
		//�������,�õ�ÿ�����ĵ÷�
		for (int j = 0; j < n; ++j)
		{
			if (!tree[j].empty())
			{
				int size = tree[j].size();
				for (int k = 0; k < size; ++k)
				{
					nums[tree[j][k]] = nums[j] + profit[tree[j][k]] - m[make_pair(j, tree[j][k])];
				}
			}
		}
		//��Ҷ�ӽڵ����ҵ����ֵ
		for (int j = 0; j < n; ++j)
		{
			if (tree[j].empty() && res < nums[j])
			{
				res = nums[j];
			}
		}
		return res;
	}
};
#endif