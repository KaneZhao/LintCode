#ifndef C1399_H
#define C1399_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 拿硬币
*
* 描述
* 有n个硬币排成一排，每次要你从最左边或者最右侧拿出一个硬币。总共拿k次，写一个算法，使能拿到的硬币的和最大。
* 1 <= k <= n <= 100000。
* 硬币的价值不大于10000。
* 样例
* 给出 list = [5,4,3,2,1], k = 2, 返回 9.
* 解释：
* 从左边开始连取两个硬币即可。
* 给出 list = [5,4,3,2,1,6], k = 3, 返回 15.
* 从左边开始连取两个硬币,右边取一个即可。
*/
class Solution {
public:
	/**
	* @param list: The coins
	* @param k: The k
	* @return: The answer
	*/
	int takeCoins(vector<int> &list, int k) {
		// Write your code here
		int len = list.size();
		//list[i]表示从0到list[i]元素累加的值
		for (int i = 1; i < len; ++i)
			list[i] += list[i - 1];
		int res = INT_MIN;
		//取k次,左右两边取的次数可以为0,k;1,k-1;2,k-2...
		//求出银币和的最大值
		for (int i = 0; i <= k; ++i)
		{
			int left = 0, right = 0;
			if (i>0)
				left = list[i - 1];
			if (i<k)
				right = list[len - 1] - list[len - 1 - k + i];
			res = maxVal(res, left + right);
		}
		return res;
	}
	int maxVal(int a, int b)
	{
		return a>b ? a : b;
	}
};
#endif