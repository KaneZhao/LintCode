#ifndef C776_H
#define C776_H
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 对称数II
*
* 对称数是一个旋转180度后(倒过来)看起来与原数相同的数.找到所有长度为 n 的对称数.
* 样例
* 给出 n = 2 返回 ["11","69","88","96"].
*/
class Solution {
public:
	/**
	* @param n: the length of strobogrammatic number
	* @return: All strobogrammatic numbers
	*/
	vector<string> findStrobogrammatic(int n) {
		// write your code here
		vector<string> res;
		if (n <= 0)
			return{""};
		res = helper(n);
		if (n == 1)
			return res;
		//去除其中以0开头的字符串
		sort(res.begin(), res.end());
		int pos = 0;
		for (int i = 0; i < res.size(); ++i)
		{
			if (res[i][0] != '0')
			{
				pos = i;
				break; 
			}
		}
		if (pos != 0)
			res.erase(res.begin(), res.begin() + pos);
		return res;
	}
	//递归求解
	vector<string> helper(int n)
	{
		if (n == 1)
			return{ "0", "1", "8" };
		else if (n == 2)
			return{ "00","11", "69", "88", "96" };
		vector<string> res = helper(n - 2);
		vector<string> tmp = helper(2);
		vector<string> vec;
		//n的结果就等同于将n=2的每个结果加到n-2每个结果的两边
		for (auto c : res)
		{
			for (auto t : tmp)
				vec.push_back(t[0] + c + t[1]);
		}
		return vec;
	}
};
#endif