#ifndef C424_H
#define C424_H
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
/*
* 逆波兰表达式求值
*
* 描述
* 求逆波兰表达式的值。
* 在逆波兰表达法中，其有效的运算符号包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰计数表达。
* 样例
* ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
* ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/
class Solution {
public:
	/**
	* @param tokens: The Reverse Polish Notation
	* @return: the value
	*/
	int evalRPN(vector<string> &tokens) {
		// write your code here
		if (tokens.empty())
			return 0;
		stack<string> stack;
		for (auto c : tokens)
		{
			//当c为运算符时,提取栈的前两个元素计算,并将结果入栈
			//若c为表示数字的字符串,直接入栈
			if (string("+-*/").find(c) != string::npos)
			{
				int x = stoi(stack.top());
				stack.pop();
				int y = stoi(stack.top());
				stack.pop();
				int num = 0;
				if (c == "+")
					num = y + x;
				else if (c == "-")
					num = y - x;
				else if (c == "*")
					num = y*x;
				else
				{
					if (x == 0)
						return 0;
					else
						num = y / x;
				}
				stack.push(to_string(num));
			}
			else
				stack.push(c);
		}
		if (stack.empty())
			return 0;
		else
			return stoi(stack.top());
	}
};
#endif 