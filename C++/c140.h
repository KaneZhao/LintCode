#ifndef C140_H
#define C140_H
#include<iostream>
using namespace std;
/*
* 快速幂
*
* 计算an % b，其中a，b和n都是32位的整数。
* 样例
* 例如 231 % 3 = 2
* 例如 1001000 % 1000 = 0
* 挑战
* O(logn)
*/
class Solution {
public:
	/*
	* @param a, b, n: 32bit integers
	* @return: An integer
	*/
	int fastPower(int a, int b, int n) {
		// write your code here
		if (b == 0||n < 0)
			return -1;
		if (n == 0)
			return 1 % b;
		if (n == 1)
			return a%b;
		long long res = fastPower(a, b, n >> 1)%b;//二分法
		res = (res*res) % b;
		//注意n为奇数的情况
		if (n & 1 == 1)
			res = (res*a) % b;
		return res;
	}
};
#endif