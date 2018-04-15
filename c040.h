#ifndef C40_H
#define C40_H
#include<iostream>
#include<stack>
using namespace std;
/*
* 用栈实现队列
*
* 正如标题所述，你需要使用两个栈来实现队列的一些操作。
* 队列应支持push(element)，pop() 和 top()，其中pop是弹出队列中的第一个(最前面的)元素。
* pop和top方法都应该返回第一个元素的值。
* 样例
* 比如push(1), pop(), push(2), push(3), top(), pop()，你应该返回1，2和2
* 挑战
* 仅使用两个栈来实现它，不使用任何其他数据结构，push，pop 和 top的复杂度都应该是均摊O(1)的
*/
class MyQueue {
public:
	MyQueue() {
		// do intialization if necessary
	}

	/*
	* @param element: An integer
	* @return: nothing
	*/
	void push(int element) {
		// write your code here
		stack1.push(element);//向stack1中压栈
	}

	/*
	* @return: An integer
	*/
	int pop() {
		// write your code here
		int val = 0;
		//如果stack2中存在元素,返回stack2的栈顶,之后出栈
		//否则,将stack1中的元素依次出栈,并压入stack2中,返回stack2的栈顶,之后出栈
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		val = stack2.top();
		stack2.pop();
		return val;
	}

	/*
	* @return: An integer
	*/
	int top() {
		// write your code here
		//如果stack2中存在元素,返回stack2的栈顶
		//否则,将stack1中的元素依次出栈,并压入stack2中,之后返回stack2的栈顶
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		return stack2.top();
	}
	stack<int> stack1, stack2;
};
#endif