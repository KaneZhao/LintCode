#ifndef C411_H
#define C411_H
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
* 格雷编码
* 
* 格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个二进制的差异。
* 给定一个非负整数 n ，表示该代码中所有二进制的总数，请找出其格雷编码顺序。一个格雷编码顺序必须以 0 开始，并覆盖所有的 2n 个整数。
* 注意事项
* 对于给定的 n，其格雷编码顺序并不唯一。
* 根据以上定义， [0,2,3,1] 也是一个有效的格雷编码顺序。
* 样例
* 给定 n = 2， 返回 [0,1,3,2]。其格雷编码顺序为：
* 00 - 0
* 01 - 1
* 11 - 3
* 10 - 2
* 挑战
* O(2n) 时间复杂度。
*/
class Solution {
public:
	/*
	* @param n: a number
	* @return: Gray code
	*/
	vector<int> grayCode(int n) {
		// write your code here
		vector<int> res(pow(2,n),0);
		//当n=0，结果为{0}，当n=1，结果为{0,1}; 
		//由规律可得，n = 2时，前两项就是{ 00，01 }，后两项是{ 0，1 }每个数字前面加1的倒序，
		//即为{ 11, 10 }；递归可求结果。
		if (n <= 0)
			return res;
		if (n == 1)
		{
			res[1] = 1;
			return res;
		}
		vector<int> v = grayCode(n - 1);
		for (int i = 0; i < v.size(); ++i)
		{
			res[i] = v[i];
			res[res.size() - 1 - i] = v[i] + pow(2, n - 1);
		}
		return res;
	}
};
#endif