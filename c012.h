#ifndef C_12_H
#define C_12_H
#include<iostream>
#include<stack>
using namespace std;
/*
* 带最小值操作的栈
*
* 实现一个带有取最小值min方法的栈，min方法将返回当前栈中的最小值。
* 你实现的栈将支持push，pop 和 min 操作，所有操作要求都在O(1)时间内完成。
* 注意事项
* 如果堆栈中没有数字则不能进行min方法的调用
* 样例
* 如下操作：push(1)，pop()，push(2)，push(3)，min()， push(1)，min() 返回 1，2，1
*/
class MinStack {
public:
	MinStack() {
		// do intialization if necessary
	}

	/*
	* @param number: An integer
	* @return: nothing
	*/
	void push(int number) {
		// write your code here
		//当stack2为空,直接压栈
		//否则将取栈顶和number的最大值,压栈
		stack1.push(number);
		if (stack2.empty())
			stack2.push(number);
		else
		{
			int minVal = stack2.top();
			minVal = minVal < number ? minVal : number;
			stack2.push(minVal);
		}
	}

	/*
	* @return: An integer
	*/
	int pop() {
		// write your code here
		//stack1,stack2同时出栈
		int res = 0;
		if (!stack1.empty() && !stack2.empty())
		{
			res = stack1.top();
			stack1.pop();
			stack2.pop();
		}
		return res;
	}

	/*
	* @return: An integer
	*/
	int min() {
		// write your code here
		//直接取stack2的栈顶
		if (!stack2.empty())
			return stack2.top();
	}
	stack<int> stack1, stack2;//stack1为主栈,stack2为辅助栈存放最小值
};
#endif