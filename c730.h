#ifndef C730_H
#define C730_H
#include<iostream>
#include<cmath>
using namespace std;
/*
*所有子集的和
*
*描述
*给一整数 n, 我们需要求前n个自然数形成的集合的所有可能子集中所有元素的和。
*
*样例
*给出 n = 2, 返回 6
*可能的子集为 {{1}, {2}, {1, 2}}.子集的元素和为 1 + 2 + 1 + 2 = 6
*给出 n = 3, 返回 24
*可能的子集为 {{1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}
*子集的和为:1 + 2 + 3 + (1 + 2) + (1 + 3) + (2 + 3) + (1 + 2 + 3) = 24
*/
class Solution {
public:
	/*
	* @param : the given number
	* @return: Sum of elements in subsets
	*/
	int subSum(int n) {
		// write your code here
		if (n == 0)
			return 0;
		long long num = subSum(n - 1) * 2 + n*pow(2, n - 1);
		return num;
	}
};
#endif