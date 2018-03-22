#ifndef C434_H
#define C434_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 岛屿的个数II
*
* 给定 n，m，分别代表一个2D矩阵的行数和列数，同时，给定一个大小为 k 的二元数组A。起初，2D矩阵的行数和列数均为 0，即该矩阵中只有海洋。二元数组有 k 个运算符，每个运算符有 2 个整数 A[i].x, A[i].y，你可通过改变矩阵网格中的A[i].x]，[A[i].y] 来将其由海洋改为岛屿。请在每次运算后，返回矩阵中岛屿的数量。
* 注意事项
* 0 代表海，1 代表岛。如果两个1相邻，那么这两个1属于同一个岛。我们只考虑上下左右为相邻。
* 样例
* 给定 n = 3, m = 3， 二元数组 A = [(0,0),(0,1),(2,2),(2,1)].
* 返回 [1,1,2,2].
*/
struct Point{
	int x;
	int y;
	Point() :x(0), y(0){}
	Point(int a, int b) :x(a), y(b){}
};
class Solution {
public:
	/**
	* @param n: An integer
	* @param m: An integer
	* @param operators: an array of point
	* @return: an integer array
	*/
	vector<int> numIslands2(int n, int m, vector<Point> &operators) {
		// write your code here
		vector<int> res;
		if (n <= 0 || m <= 0 || operators.empty())
			return res;
		vector<int> nums(n*m + 1, 0);
		vector<vector<int>> dic{ { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		int count = 0;
		for (auto c : operators)
		{
			int pos = c.x*m + c.y + 1;
			//若pos已经出现过,则返回当前的count值
			if (nums[pos] != 0)
			{
				res.push_back(count);
				continue;
			}
			nums[pos] = pos;
			++count;
			//遍历与当前位置相邻的位置
			//找到相邻位置cur最顶层的值,并赋值给nums[pos]
			//此时岛屿融合,count减一
			for (auto t : dic)
			{
				int a = c.x + t[0];
				int b = c.y + t[1];
				int cur = a*m + b + 1;
				if (a < 0 || a >= n || b < 0 || b >= m || nums[cur] == 0)
					continue;
				int root = unionSearch(cur, nums);
				if (pos != root)
				{
					nums[pos] = root;
					pos = root;
					--count;
				}
			}
			res.push_back(count);
		}
		return res;
	}
	//返回root最顶层的值,并进行路径压缩
	int unionSearch(int root, vector<int>&nums)
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