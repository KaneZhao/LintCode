#ifndef C125_H
#define C125_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 背包问题 II
*
* 给出n个物品的体积A[i]和其价值V[i]，将他们装入一个大小为m的背包，最多能装入的总价值有多大？
* 注意事项
* A[i], V[i], n, m均为整数。你不能将物品进行切分。你所挑选的物品总体积需要小于等于给定的m。
* 样例
* 对于物品体积[2, 3, 5, 7]和对应的价值[1, 5, 2, 4], 假设背包大小为10的话，最大能够装入的价值为9。
* 挑战
* O(n x m) memory is acceptable, can you do it in O(m) memory?
*/
class Solution {
public:
	/**
	* @param m: An integer m denotes the size of a backpack
	* @param A & V: Given n items with size A[i] and value V[i]
	* @return: The maximum value
	*/
	int backPackII(int m, vector<int> A, vector<int> V) {
		// write your code here
		if (A.empty() || V.empty())
			return 0;
		vector<int> dp(m + 1, 0);//dp[j]表示容量为j时可以存放的最大价值
		for (int i = 0; i < A.size(); ++i)
		{
			for (int j = m; j >= A[i]; --j)
			{
				dp[j] = maxVal(dp[j - A[i]] + V[i], dp[j]);//当容量大于A[i],空出A[i]体积,加上相应的价值V[i]并与原dp[j]比较
			}
		}
		return dp[m];
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif