#ifndef C741_H
#define C741_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
* Calculate Maximum Value II
*
* Given a string of numbers, write a function to find the maximum value from the string, you can add a + or * sign between any two numbers，It's different with Calculate Maximum Value, You can insert parentheses anywhere.
* 样例
* Given str = 01231, return 12
* (0 + 1 + 2) * (3 + 1) = 12 we get the maximum value 12
* Given str = 891, return 80
* As 8 * (9 + 1) = 80, so 80 is maximum.
*/
class Solution {
public:
	/**
	* @param str: a string of numbers
	* @return: the maximum value
	*/
	int maxValue(string &str) {
		// write your code here
		if (str.empty())
			return 0;
		int len = str.size();
		vector<vector<int>> res(len, vector<int>(len, INT_MIN));//res[i][j]存放从str[i]到str[j]的最大值
		for (int i = 0; i<len; ++i)//初始化res
			res[i][i] = str[i] - '0';
		//在不同步长不同位置的情况下计算res的值
		for (int path = 2; path <= len; ++path)
		{
			for (int i = 0; i + path <= len;++i)
			    res[i][i + path - 1] = ComputeMax(i, path, res);
		}
		return res[0][len - 1];
	}
	//递归计算位置i,步长为path的情况下取得的最大值
	int ComputeMax(int i,int path,vector<vector<int>> vec) {
		int res = INT_MIN;
		if (vec[i][i + path - 1] != INT_MIN)
			return vec[i][i + path - 1];
		for (int k = 1; k < path; ++k) {
				int left = ComputeMax(i, k, vec);
				int right = ComputeMax(i + k, path - k, vec);
				res = maxVal(maxVal(left + right, left*right),res);
			}
		return res;
	}
	int maxVal(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif