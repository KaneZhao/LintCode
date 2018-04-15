#ifndef C40_H
#define C40_H
#include<iostream>
#include<stack>
using namespace std;
/*
* ��ջʵ�ֶ���
*
* �����������������Ҫʹ������ջ��ʵ�ֶ��е�һЩ������
* ����Ӧ֧��push(element)��pop() �� top()������pop�ǵ��������еĵ�һ��(��ǰ���)Ԫ�ء�
* pop��top������Ӧ�÷��ص�һ��Ԫ�ص�ֵ��
* ����
* ����push(1), pop(), push(2), push(3), top(), pop()����Ӧ�÷���1��2��2
* ��ս
* ��ʹ������ջ��ʵ��������ʹ���κ��������ݽṹ��push��pop �� top�ĸ��Ӷȶ�Ӧ���Ǿ�̯O(1)��
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
		stack1.push(element);//��stack1��ѹջ
	}

	/*
	* @return: An integer
	*/
	int pop() {
		// write your code here
		int val = 0;
		//���stack2�д���Ԫ��,����stack2��ջ��,֮���ջ
		//����,��stack1�е�Ԫ�����γ�ջ,��ѹ��stack2��,����stack2��ջ��,֮���ջ
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
		//���stack2�д���Ԫ��,����stack2��ջ��
		//����,��stack1�е�Ԫ�����γ�ջ,��ѹ��stack2��,֮�󷵻�stack2��ջ��
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