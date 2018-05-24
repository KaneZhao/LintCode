#ifndef C116_H
#define C116_H
#include<iostream>
#include<vector>
using namespace std;
/*
* 跳跃游戏
*
* 给出一个非负整数数组，你最初定位在数组的第一个位置。　　　
* 数组中的每个元素代表你在那个位置可以跳跃的最大长度。　　　　
* 判断你是否能到达数组的最后一个位置。
* 样例
* A = [2,3,1,1,4]，返回 true.
* A = [3,2,1,0,4]，返回 false.
*/
class Solution {
public:
	/**
	* @param A: A list of integers
	* @return: The boolean answer
	*/
	bool canJump(vector<int> A) {
		// write you code here
		int len = A.size();
		vector<bool> v(len, false);
		v[len - 1] = true;
		for (int i = len - 2; i >= 0; --i)
		{
			if (i + A[i] == len - 1)
				v[i] = true;
			for (int j = 0; j <= A[i]; ++j)
			{
				if (i + j <= len - 1 && v[i + j] == true)
				{
					v[i] = true;
					break;
				}
			}
		}
		return v[0];
	}
};
#endif