#ifndef C980_H
#define C980_H
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
/*
* Basic Calculator II
* 
* 描述
* Implement a basic calculator to evaluate a simple expression string.
* The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
* You may assume that the given expression is always valid.
* Do not use the eval built-in library function.
* 样例
* "3+2*2" = 7
* " 3/2 " = 1
* " 3+5 / 2 " = 5
*/
class Solution {
public:
	/**
	* @param s: the given expression
	* @return: the result of expression
	*/
	int calculate(string &s) {
		// Write your code here
		if (s.empty())
			return 0;
		vector<string> expression = getExpression(s);
		vector<string> post = postExpression(expression);
		stack<string> stack;
		for (auto c : post)
		{
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
	//获得元素的优先级
	int getPriority(string &str)
	{
		if (str == "(")
			return 0;
		else if (str == "+" || str == "-")
			return 1;
		else if (str == "*" || str == "/")
			return 2;
		else
			return 3;
	}
	//将字符串转化为表达式
	vector<string> getExpression(string &s)
	{
		vector<string> expression;
		string str;
		for (auto c : s)
		{
			if (ispunct(c))
			{
				if (!str.empty())
				{
					expression.push_back(str);
					str.clear();
				}
				str += c;
				expression.push_back(str);
				str.clear();
			}
			else if (isdigit(c))
			{
				str += c;
			}
		}
		if (!str.empty())
			expression.push_back(str);
		return expression;
	}
	//将表达式转化为逆波兰表达式
	vector<string> postExpression(vector<string> &expression)
	{
		vector<string> post;
		stack<string> stack;
		for (auto c : expression)
		{
			if (c == "(")
				stack.push(c);
			else if (c == ")")
			{
				while (stack.top() != "(")
				{
					post.push_back(stack.top());
					stack.pop();
				}
				stack.pop();
			}
			else
			{
				while (!stack.empty() && getPriority(stack.top()) >= getPriority(c))
				{
					post.push_back(stack.top());
					stack.pop();
				}
				stack.push(c);
			}
		}
		while (!stack.empty())
		{
			post.push_back(stack.top());
			stack.pop();
		}
		return post;
	}
};
#endif