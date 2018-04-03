#ifndef C666_H
#define C666_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 猜数游戏 II
*
* 我们正在玩猜数游戏, 游戏内容如下:
* 我在 1到 n 的范围内选择一个数作为待猜的数, 你需要来猜这个数,
* 每次你猜错的时候, 我会告诉你我选择的这个数是比你说的数要高还是低,
* 但是, 当你猜这个数为 x 并且猜错的时候你需要支付 $x. 当你猜到我选择的数时, 你将赢得这场游戏
* 样例
* 给出 n = 10, 我选择待猜数为 8
* 第一轮: 你猜测为 5, 我告诉你待猜的值要更大一些. 你需要支付 $5
* 第二轮: 你猜测为 7, 我告诉你待猜的值要更大一些. 你需要支付 $7
* 第三轮: 你猜测为 9, 我告诉你待猜的值要更小一些. 你需要支付 $9
* 游戏结束. 8 是我选择的待猜数.
* 你最终需要支付 $5 + $7 + $9 = $21
* 给一个具体的大于等于 1 的数 n, 计算你需要多少钱才可以保证赢.
* 所以当 n = 10 时, 返回 16.
*/
class Solution {
public:
	/*
	* @param n: An integer
	* @return: how much money you need to have to guarantee a win
	*/
	int getMoneyAmount(int n) {
		// write your code here
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));//dp[i][j]表示猜i-j赢,所需要的最小钱数
		//易得数组长度为1,需要钱数为0,对dp[i][i]不做特殊的初始化
		//从长度为2的子数组开始计算,如1-2,2-3,3-4
		//对于子数组i - i+path,计算第一次取每个位置时的最小钱数,并取所有钱数的最小值
		for (int path = 1; path < n; ++path)
		{
			for (int i = 1; i + path <= n; ++i)
			{
				int res = INT_MAX;
				int tmp = INT_MAX;
				for (int j = i; j <= i + path; ++j)
				{
					if (j == i)
						tmp = j + dp[j + 1][i + path];
					else if (j == i + path)
						tmp = dp[i][j - 1] + j;
					else
						tmp = j + maxVal(dp[i][j - 1],dp[j + 1][i + path]);//j位于子数组中间位置,取两边子数组钱数的最大值
					res = minVal(res, tmp);
				}
				dp[i][i + path] = res;
			}
		}
		return dp[1][n];
	}
	int minVal(int a, int b)
	{
		return a < b ? a : b;
	}
	int maxVal(int a, int b)
	{
		return a>b ? a : b;
	}
};
#endif