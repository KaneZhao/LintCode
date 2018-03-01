#ifndef C82_H
#define C82_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 落单的数
*
* 给出2*n + 1 个的数字，除其中一个数字之外其他每个数字均出现两次，找到这个数字。
* 样例
* 给出 [1,2,2,1,3,4,3]，返回 4
* 挑战
* 一次遍历，常数级的额外空间复杂度
*/
class Solution {
public:
	/**
	* @param A: An integer array
	* @return: An integer
	*/
	int singleNumber(vector<int> &A) {
		// write your code here
		int res = A[0];
		//利用a^b^b=a
		for (int i = 1; i < A.size(); ++i)
			res ^= A[i];
		return res;
	}
};
#endif