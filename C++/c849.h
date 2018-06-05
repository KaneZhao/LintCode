#ifndef C849_H
#define C849_H
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
/*
* Basic Calculator III
*
* ����
* Implement a basic calculator to evaluate a simple expression string.
* The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
* The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.
* You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647]
* Do not use the eval built-in library function.
* ����
* "1 + 1" = 2
* " 6-4 / 2 " = 4
* "2*(5+5*2)/3+(6/2+8)" = 21
* "(2+6* 3+5- (3*14/7+2)*5)+3"=-12
*/
class Solution {
public:
	/**
	* @param s: the expression string
	* @return: the answer
	*/
	int calculate(string &s) {
		// Write your code here
		if (s.empty())
			return 0;
		vector<string> expression = getExpression(s);
		vector<string> post = postExpression(expression);
		stack<string> stack;
		//������,�����������Ϊlong long��
		for (auto c : post)
		{
			if (string("+-*/").find(c) != string::npos)
			{
				long long x = stoll(stack.top());
				stack.pop();
				long long y = stoll(stack.top());
				stack.pop();
				long long num = 0;
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
			return stoll(stack.top());
	}
	//���Ԫ�ص����ȼ�
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
	//���ַ���ת��Ϊ���ʽ
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
	//�����ʽת��Ϊ�沨�����ʽ
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