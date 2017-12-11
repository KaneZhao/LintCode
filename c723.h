#ifndef C723_H
#define C723_H
#include<iostream>
#include<cmath>
using namespace std;
/*
* 左旋转二进制位
*
* 位旋转 -—— 旋转（或循环移位）是类似于移位的操作, 不同的是一端脱落的那一位会被放回到另一端
* 在左旋转中, 左端掉下来的那一位会放在右端
* 假设 n 用 8 位二进制来存. 对 n = 11100101 左旋转 3 位, 得到 n = 00101111 (左移3位, 原先的前3位放在末尾).
* 如果 n 用 16 位或 32 位二进制来存, 那么对 n (000…11100101)左旋转了之后会变成 (00..0011100101000).
* 在本问题中, 你可以假设 n 是用 32 位二进制来存的.
*/
class Solution {
public:
	/*
	* @param : a number
	* @param : digit needed to be rorated
	* @return: a number
	*/
	int leftRotate(int n, int d) {
		// write code here
		if (d < 0)
			return 0;
		d = d % 32;//保证在0-31之间
		long long num = pow(2, d) - 1;
		num = num << (32 - d);
		num = num&n;//与n取交,来取n的高d位
		num = num >> (32 - d);//将num右移成d位数,即为n高d位所表示的数
		n = n << d;//n左移d位
		n += num;//将高d位表示的数加在n的右端
		return n;
	}
};
#endif