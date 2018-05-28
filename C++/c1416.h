#ifndef C1416_H
#define C1416_H
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
* 前一个数
*
* 描述
* 给一个数组，对于每一个元素，找出它之前第一个比它小的元素的值。如果没有，则输出它本身。
* 输入的数组长度为n，n <= 100000。
* 元素的大小为x，x <= 1000000。
* 样例
* 给出 list = [2,3,6,1,5,5]，返回 [2,2,3,1,1,1]。
* 解释：
* 依据题意，找出每个数字前面第一个比它小的元素。
* 给出 list = [6,3,1,2,5,10,9,15]，返回[6,3,1,1,2,5,5,9]。
* 解释：
* 依据题意，找出每个数字前面第一个比它小的元素。
*/
class Solution {
public:
	/**
	* @param num: The arry you should handle
	* @return: Return the array
	*/
	vector<int> getPreviousNumber(vector<int> &num) {
		// Write your code here
		if (num.empty())
			return num;
		stack<int> s;
		vector<int> res;//返回最终结果
		s.push(num[0]);
		res.push_back(num[0]);
		//对于元素num[i],如果s的栈顶元素大于num[i],出栈
		//若栈空,表明num[i]前没有比它小的元素,num[i]压栈并添加到res
		//否则,将栈顶添加到res,并把num[i]压栈
		for (int i = 1; i < num.size(); ++i)
		{
			while (!s.empty()&&num[i]<=s.top())
			{
				s.pop();
			}
			if (s.empty())
			{
				s.push(num[i]);
				res.push_back(num[i]);
			}
			else
			{
				res.push_back(s.top());
				s.push(num[i]);
			}
		}
		return res;
	}
};
#endif