#ifndef C952_H
#define C952_H
#include<iostream>
using namespace std;
/*
* 数字问题
*
* 给一个转换规则来转换数字n：
* n是奇数，n = 3n + 1
* n是偶数，n = n / 2
* 经过若干次转换后，n会变成1。
* 现在给一个n，输出它转换到1需要的次数。
* 注意事项
* 1 <= n <= 1000000
* 样例
* 给出 n = 2, 返回 1.
* 解释:
* 2→1
* 给出 n = 3, 返回 7.
* 解释:
* 3→10→5→16→8→4→2→1
*/
class Solution {
public:
	/**
	* @param n: the number n
	* @return: the times n convert to 1
	*/
	int digitConvert(int n) {
		// Write your code here 
		int cnt = 0;
		//尽量使用位运算
		while (n != 1)
		{
			if (n & 1 == 1)
				n = 3 * n + 1;
			else
				n = n >> 1;
			cnt++;
		}
		return cnt;
	}
};
#endif