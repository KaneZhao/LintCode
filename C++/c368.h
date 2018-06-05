#ifndef C368_H
#define C368_H
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
/*
* 表达式求值
*
* 描述
* 给一个用字符串表示的表达式数组，求出这个表达式的值。
* 表达式只包含整数, +, -, *, /, (, ).
* 样例
* 对于表达式 (2*6-(23+7)/(1+2)), 对应的数组为：
* [
* "2", "*", "6", "-", "(",
* "23", "+", "7", ")", "/",
* "(", "1", "+", "2", ")"
* ],
* 其值为 2
*/
class Solution {
public:
	/*
	* @param expression: a list of strings
	* @return: an integer
	*/
	int evaluateExpression(vector<string> &expression) {
		// write your code here
		vector<string> post = postExpression(expression);
		stack<string> sk;
		for (auto c : post)
		{
			if (string("+-*/").find(c) != string::npos)
			{
				int num = 0;
				string x = sk.top();
				int xint = atoi(x.c_str());
				sk.pop();
				string y = sk.top();
				sk.pop();
				int yint = atoi(y.c_str());
				if (c == "+")
					num = yint + xint;
				else if (c == "-")
					num = yint - xint;
				else if (c == "*")
					num = yint*xint;
				else
				{
					if (xint == 0)
					{
						return 0;
						break;
					}
					else
						num = yint / xint;
				}
				sk.push(to_string(num));
			}
			else
				sk.push(c);
		}
		if (sk.empty())
			return 0;
		else
		{
			string s = sk.top();
			return atoi(s.c_str());
		}
	}
	int getPriority(string s)
	{
		if (s == "(")
			return 0;
		else if (s == "+" || s == "-")
			return 1;
		else if (s == "*" || s == "/")
			return 2;
		else
			return 3;
	}
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
				if (string("+-*/").find(c) == string::npos)
					stack.push(c);
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