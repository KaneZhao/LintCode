#ifndef C370_H
#define C370_H
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
/*
* �����ʽת��Ϊ�沨�����ʽ
*
* ����
* ����һ�����ʽ�ַ������飬���ظñ��ʽ���沨�����ʽ����ȥ�����ţ���
* ����
* ���� [3 - 4 + 5]�ı��ʽ���ñ��ʽ�ɱ�ʾΪ["3", "-", "4", "+", "5"]�������� [3 4 - 5 +]���ñ��ʽ�ɱ�ʾΪ ["3", "4", "-", "5", "+"]����
*/
class Solution {
public:
	/*
	* @param expression: A string array
	* @return: The Reverse Polish notation of this expression
	*/
	vector<string> convertToRPN(vector<string> &expression) {
		// write your code here
		vector<string> post;
		if (expression.empty())
			return post;
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
	int getPriority(string &str)
	{
		if (str == "(")
			return 0;
		else if (str == "-" || str == "+")
			return 1;
		else if (str == "*" || str == "/")
			return 2;
		else
			return 3;
	}
};
#endif