#ifndef C84_H
#define C84_H
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
/*
* 落单的数 III
*
* 给出2*n + 2个的数字，除其中两个数字之外其他每个数字均出现两次，找到这两个数字。
* 样例
* 给出 [1,2,2,3,4,4,5,3]，返回 1和5
* 挑战
* O(n)时间复杂度，O(1)的额外空间复杂度
*/
class Solution {
public:
	vector<int> singleNumberIII(vector<int> &A) {
		// write your code here
		vector<int> nums(32, 0);
		vector<int> vec;
		int res = 0;
		int pos = 0;
		int num1 = 0, num2 = 0;
		//nums存放的结果为num1^num2,记为Xor
		for (auto c : A)
		{
			for (int i = 0; i < 32; ++i)
			{
				nums[i] = (nums[i] + ((c >> i) & 1)) % 2;
			}
		}
		//找到Xor中最低位的1所在位置pos
		for (int i = 0; i < 32; ++i)
		{
			if (nums[i] == 1)
			{
				pos = i;
				break;
			}
		}
		//根据位置pos是否为1,将A分成两组,分别求其落单的数
		for (auto c : A)
		{
			if ((c >> pos) & 1 == 1)
				num1 ^= c;
			else
				num2 ^= c;
		}
		vec.push_back(num1);
		vec.push_back(num2);
		return vec;
	}
};
#endif