#ifndef C20_H
#define C20_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
* 骰子求和
*
* 扔 n 个骰子，向上面的数字之和为 S。给定 Given n，请列出所有可能的 S 值及其相应的概率。
* 注意事项
* You do not care about the accuracy of the result, we will help you to output results.
* 样例
* 给定 n = 1，返回 [ [1, 0.17], [2, 0.17], [3, 0.17], [4, 0.17], [5, 0.17], [6, 0.17]]。
*/
class Solution {
public:
	vector<pair<int, double>> dicesSum(int n) {
		// Write your code here
		vector<pair<int, double>> vec;
		if (n <= 0)
			return vec;
		map<int, double> m = helper(n);
		for (auto c : m)
		{
			vec.push_back(make_pair(c.first, c.second));
		}
		return vec;
	}
	//递归求骰子的概率
	map<int, double> helper(int n){
		map<int, double> m;
		for (int i = 1; i <= 6; ++i)
			m[i] = (double)1 / 6;
		if (n == 1)
			return m;
		map<int, double> num = helper(n - 1);
		map<int, double> res;
		for (auto t : m)
		{
			for (auto c : num)
			{
				res[t.first + c.first] += t.second*c.second;
			}
		}
		return res;
	}
};
#endif