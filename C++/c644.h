#ifndef C644_H
#define C644_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 数 1
*
* 描述
* 给以 非负 整数 num. 对所有满足 0 ≤ i ≤ num 条件的数字 i 均需要计算其二进制表示 1 的个数并以数组的形式返回
* 样例
* 给出 num = 5 你需要返回 [0,1,1,2,1,2].
* 挑战
* 时间复杂度为 O(n * sizeof(integer))的解法很容易想到, 但是你是否可以用线性的时间复杂度 O(n)/可能只遍历一遍吗, 空间复杂度应为 O(n).
* 你能霸气的完成这项挑战吗? 不借助任何内嵌的函数, 比如C++ 中的__builtin_popcount 亦或是任何其他语言中的方法
*/
class Solution {
public:
	/**
	* @param num: a non negative integer number
	* @return: an array represent the number of 1's in their binary
	*/
	vector<int> countBits(int num) {
		// write your code here
		if (num <= 0)
			return{0};
		vector<int> res(num + 1, 0);
		//如果i是奇数,包含1的个数是i-1包含1的个数加一
		//如果i是偶数,包含1的个数等于i/2包含1的个数
		for (int i = 1; i <= num; ++i)
		{
			if (i % 2 != 0)
				res[i] = res[i - 1] + 1;
			else
				res[i] = res[i / 2];
		}
		return res;
	}
};
#endif