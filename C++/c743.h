#ifndef C743_H
#define C743_H
#include<iostream>
#include<string>
using namespace std;
/*
* Monotone Increasing Digits
*
* Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.
* (Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)
* 注意事项
* Note: N is an integer in the range [0, 10^9].
* 样例
* Given N = 10, return 9
* Given N = 12345, return 12345
* Given N = 10000, return 9999
*/
class Solution {
public:
	/**
	* @param num: a non-negative integer N
	* @return: the largest number that is less than or equal to N with monotone increasing digits.
	*/
	int monotoneDigits(int num) {
		// write your code here
		string str = to_string(num);
		int len = str.size();
		if (len == 1)
			return num;
		for (int i = 0; i < len-1; ++i)
		{
			if (str[i]>str[i + 1])//查找第一个不是递增的位置i
			{
				int j = i;
				while (j >= 0)//向前寻找与str[i]不相等的数所在的位置j
				{
					if (str[j] == str[i])
						--j;
					else
						break;
				}
				str[++j]--;
				for (int k = j + 1; k < len; ++k)//将str的j+1位到最后均置为'9'
					str[k] = '9';
				break;
			}
		}
		return stoi(str);
	}
};
#endif