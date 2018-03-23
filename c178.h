#ifndef C178_H
#define C178_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 图是否是树
*
* 给出 n 个节点，标号分别从 0 到 n - 1 并且给出一个 无向 边的列表 (给出每条边的两个顶点), 写一个函数去判断这张｀无向｀图是否是一棵树
* 
* 注意事项
* 你可以假设我们不会给出重复的边在边的列表当中. 无向边　[0, 1] 和 [1, 0]　是同一条边， 因此他们不会同时出现在我们给你的边的列表当中。
* 样例
* 给出n = 5 并且 edges = [[0, 1], [0, 2], [0, 3], [1, 4]], 返回 true.
* 给出n = 5 并且 edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], 返回 false.
*/
class Solution {
public:
	/**
	* @param n: An integer
	* @param edges: a list of undirected edges
	* @return: true if it's a valid tree, or false
	*/
	bool validTree(int n, vector<vector<int>> &edges) {
		// write your code here
		int len = edges.size();
		if (len != n - 1)
			return false;
		vector<int> nums;
		for (int i = 0; i < n; ++i)
			nums.push_back(i);
		for (auto c : edges)
		{
			int root1 = unionSearch(c[0], nums);
			int root2 = unionSearch(c[1], nums);
			//若最顶层的节点相同则出现环,不是树
			if (root1 == root2)
				return false;
			nums[root1] = root2;
		}
		return true;
	}
	//找到root最高层的点
	int unionSearch(int root, vector<int> &nums)
	{
		while (root != nums[root])
		{
			nums[root] = nums[nums[root]];
			root = nums[root];
		}
		return root;
	}
};
#endif