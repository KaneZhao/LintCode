#ifndef C424_H
#define C424_H
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
/*
* �沨�����ʽ��ֵ
*
* ����
* ���沨�����ʽ��ֵ��
* ���沨����﷨�У�����Ч��������Ű��� +, -, *, / ��ÿ��������������������Ҳ��������һ���沨��������
* ����
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
			//��cΪ�����ʱ,��ȡջ��ǰ����Ԫ�ؼ���,���������ջ
			//��cΪ��ʾ���ֵ��ַ���,ֱ����ջ
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