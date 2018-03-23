#ifndef C178_H
#define C178_H
#include<iostream>
#include<vector>
using namespace std;
/*
* ͼ�Ƿ�����
*
* ���� n ���ڵ㣬��ŷֱ�� 0 �� n - 1 ���Ҹ���һ�� ���� �ߵ��б� (����ÿ���ߵ���������), дһ������ȥ�ж����ţ������ͼ�Ƿ���һ����
* 
* ע������
* ����Լ������ǲ�������ظ��ı��ڱߵ��б���. ����ߡ�[0, 1] �� [1, 0]����ͬһ���ߣ� ������ǲ���ͬʱ���������Ǹ���ıߵ��б��С�
* ����
* ����n = 5 ���� edges = [[0, 1], [0, 2], [0, 3], [1, 4]], ���� true.
* ����n = 5 ���� edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], ���� false.
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
			//�����Ľڵ���ͬ����ֻ�,������
			if (root1 == root2)
				return false;
			nums[root1] = root2;
		}
		return true;
	}
	//�ҵ�root��߲�ĵ�
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