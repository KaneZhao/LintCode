#ifndef C700_H
#define C700_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 杆子分割
* 给一个 n 英寸长的杆子和一个包含所有小于 n 的尺寸的价格. 确定通过切割杆并销售碎片可获得的最大值.例如，如果棒的长度为8，并且不同长度部件的值如下，则最大可获得值为 22(通过切割两段长度 2 和 6 )
*
* 样例
* 长度    | 1   2   3   4   5   6   7   8
* --------------------------------------------
* 价格    | 1   5   8   9  10  17  17  20
* 给出 price = [1, 5, 8, 9, 10, 17, 17, 20], n = 8 返回 22//切成长度为 2 和 6 的两段
*
* 长度    | 1   2   3   4   5   6   7   8
* --------------------------------------------
* 价格    | 3   5   8   9  10  17  17  20
* 给出 price = [3, 5, 8, 9, 10, 17, 17, 20], n = 8 返回 24//切成长度为 1 的 8 段
*/
class Solution {
public:
	/*
	* @param : the prices
	* @param : the length of rod
	* @return: the max value
	*/
	int cutting(vector<int>& prices, int n) {
		// Write your code here
		if (n == 0 || prices.empty())
			return 0;
		vector<int> dp(n + 1, 0);
		//动态转换方程dp[i] = max{ dp[j] + dp[i - j] }
		for (int i = 1; i <= n; ++i)
		{
			dp[i] = prices[i - 1];
			for (int j = 0; j <= i / 2; ++j)
			{
				dp[i] = maxVal(dp[i], dp[j] + dp[i - j]);
			}
		}
		return dp[n];
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif