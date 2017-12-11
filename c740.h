#ifndef C740_H
#define C740_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* Coin Change II
* You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.
*
* 注意事项
* You can assume below:
* 0 <= amount <= 5000
* 1 <= coin <= 5000
* the number of coins is less than 500
* the answer is guaranteed to fit into signed 32-bit integer
* 样例
* Given amount = 10, coins = [10], return 1
* Given amount = 8, coins = [2, 3, 8], return 3
* there are three ways to make up the amount:
* 8 = 8
* 8 = 3 + 3 + 2
* 8 = 2 + 2 + 2 + 2
*/
class Solution {
public:
	/**
	* @param amount: a total amount of money amount
	* @param coins: the denomination of each coin
	* @return: the number of combinations that make up the amount
	*/
	int change(int amount, vector<int> &coins) {
		// write your code here
		if (amount == 0 || coins.empty())
			return 0;
		sort(coins.begin(), coins.end());
		vector<int> res(amount+1, 0);
		res[0] = 1;
		for (auto c : coins)
		{
			for (int j = 0; j < res.size(); ++j)
			{
				if (j + c <= amount)
					res[j + c] += res[j];
			}
		}
		return res[amount];
	}
};
#endif