#ifndef C111_H
#define C111_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 爬楼梯
*
* 假设你正在爬楼梯，需要n步你才能到达顶部。但每次你只能爬一步或者两步，你能有多少种不同的方法爬到楼顶部？
* 样例
* 比如n=3，1+1+1=1+2=2+1=3，共有3种不同的方法
* 返回 3
*/
class Solution {
public:
	/**
	* @param n: An integer
	* @return: An integer
	*/
	int climbStairs(int n) {
		// write your code here
		if (n == 0)
			return 1;
		vector<int> v(n);
		v[0] = 1;
		v[1] = 2;
		//由于每次只能爬一步或者两步
		//走了i步,可能是从i-1或者i-2走出来的
		for (int i = 2; i <= n - 1; ++i)
		{
			v[i] = v[i - 1] + v[i - 2];
		}
		return v[n - 1];
	}
};
#endif