#ifndef C1413_H
#define C1413_H
#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
/*
* ��
*
* ����
* ��������list x��y������x[i]��y[i]֮����һ���ߣ������߼�����һ������1Ϊ���������и�list a,b����ʾѯ�ʽڵ�a[i]��b[i]��ʲô��ϵ�����a[i]��b[i]���ֵܣ�����ͬһ�����ڵ㣬���1�����a[i]��b[i]�Ǹ��ӹ�ϵ�����2���������0��
* �ڵ���������100000��
* ���Ե�����Ϊ������100000��������
* ����
* ���� x = [1,1], y = [2,3], a =[1,2], b = [2,3], ����[2,1]��
* ���ͣ�
* 1��2�Ǹ��ӹ�ϵ��2��3���ֵܹ�ϵ�����ǵĹ�ͬ���ڵ�Ϊ1��
* ���� x = [1,1,2], y = [2,3,4], a = [1,2,1], b = [2,3,4], ����[2,1,0]��
* ���ͣ�
* 1��2�Ǹ��ӹ�ϵ��2��3���ֵܹ�ϵ�����ǵĹ�ͬ���ڵ�Ϊ1��1��4�����ֵܹ�ϵҲ���Ǹ��ӹ�ϵ��
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
		vector<vector<int>> vec(100001, vector<int>());//��Ž��Ķ�Ӧ��ϵ
		map<int, int> dic;//��Ž�㼰�丸�ڵ�
		for (int i = 0; i < x.size(); ++i)
		{
			vec[x[i]].push_back(y[i]);
			vec[y[i]].push_back(x[i]);
		}
		//����vec
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
	//���������ڵ�Ĺ�ϵ
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