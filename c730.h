#ifndef C730_H
#define C730_H
#include<iostream>
#include<cmath>
using namespace std;
/*
*�����Ӽ��ĺ�
*
*����
*��һ���� n, ������Ҫ��ǰn����Ȼ���γɵļ��ϵ����п����Ӽ�������Ԫ�صĺ͡�
*
*����
*���� n = 2, ���� 6
*���ܵ��Ӽ�Ϊ {{1}, {2}, {1, 2}}.�Ӽ���Ԫ�غ�Ϊ 1 + 2 + 1 + 2 = 6
*���� n = 3, ���� 24
*���ܵ��Ӽ�Ϊ {{1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}
*�Ӽ��ĺ�Ϊ:1 + 2 + 3 + (1 + 2) + (1 + 3) + (2 + 3) + (1 + 2 + 3) = 24
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