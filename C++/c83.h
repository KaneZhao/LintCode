#ifndef C83_H
#define C83_H
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
* 落单的数 II
*
* 给出3*n + 1 个的数字，除其中一个数字之外其他每个数字均出现三次，找到这个数字。
* 样例
* 给出 [1,1,2,3,3,3,2,2,4,1] ，返回 4
* 挑战
* 一次遍历，常数级的额外空间复杂度
*/
class Solution {
public:
	int singleNumberII(vector<int> &A) {
		vector<int> nums(32, 0);
		int res = 0;
		//利用nums存放A中元素在二进制位每个位置上的数字之和,并将出现三次的消除
		for (auto c : A)
		{
			for (int i = 0; i < 32; ++i)
			{
				nums[i] = (nums[i] + ((c >> i) & 1))%3;
			}
		}
		//将得到的二进制结果转化为十进制
		for (int i = 0; i < 32; ++i)
		{
			res += nums[i] * pow(2, i);
		}
		return res;
	}
};
#endif