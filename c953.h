#ifndef C953_H
#define C953_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
* 树上最大得分
*
* 一棵 n 个结点的多叉树，结点编号为[0, n - 1]，根结点的编号为 0。每个结点有一个收益，到这个结点了，就可以加上这个结点的收益；每条边有一个花费，沿着这条边走，就要减去这条边的花费。问，从根结点走到任意一个叶子结点的总得分（总得分 = 总收益 - 总花费）最大为多少？
* 注意事项
* x[i], y[i] 代表第 i 条边的两个结点，cost[i] 代表第 i 条边的花费，profit[i] 代表编号为 i 的结点的收益
* 1 <= x[i], y[i] <= 10^5
* 1 <= cost[i], profit[i] <= 100
* 样例
* 给出 x = [0,0,0],y = [1,2,3], cost = [1,1,1], profit = [1,1,2,3]，返回3。
* 路线：0→3
* 给出 x = [0,0],y = [1,2], cost =[1,2], profit = [1,2,5]，返回4。
* 路线：0→2
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
		vector<int> nums(n, INT_MIN);//存放结点的得分
		nums[0] = profit[0];
		vector<vector<int>> tree(n);//存放结点及其子树
		map<pair<int, int>, int> m;//存放每条边的花费
		int res = INT_MIN;
		//以x[i]为父结点,y[i]为子结点构建其关系
		for (int i = 0; i < x.size(); ++i)
		{
			tree[x[i]].push_back(y[i]);
		}
		//用父子关系表示每一条边,并存储其花费
		for (int i = 0; i < x.size(); ++i)
		{
			m[make_pair(x[i], y[i])] = cost[i];
		}
		//深度优先,得到每个结点的得分
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
		//在叶子节点中找到最大值
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