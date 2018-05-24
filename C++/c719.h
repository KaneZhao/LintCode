#ifndef C719_H
#define C719_H
#include<iostream>
#include<string>
using namespace std;
/*
*计算最大值
*
*给一个字符串类型的数字, 写一个方法去找到最大值, 你可以在任意两个数字间加 + 或 *
*
*样例
*给出 str = 01231, 返回 10 ((((0 + 1) + 2) * 3) + 1) = 10 我们得到了最大值 10
*给出 str = 891, 返回 73 因为 8 * 9 * 1 = 72 和 8 * 9 + 1 = 73, 所以73是最大值
*/
class Solution {
public:
	/*
	* @param : the given string
	* @return: the maximum value
	*/
	int calcMaxValue(string &str) {
		// write your code here
		if (str.empty())
			return 0;
		int res = 0;
		//遍历字符串的每一位，转化为数字num，并将当前的结果res置为max{res*num,res+num},最后返回res
		for (int i = 0; i < str.size(); ++i)
		{
			int num = stoi(str.substr(i, 1));
			res = maxVal(res*num, res + num);
		}
		return res;
	}
	int maxVal(int a, int b)
	{
		return a>b ? a : b;
	}
};
#endif