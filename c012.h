#ifndef C_12_H
#define C_12_H
#include<iostream>
#include<stack>
using namespace std;
/*
* ����Сֵ������ջ
*
* ʵ��һ������ȡ��Сֵmin������ջ��min���������ص�ǰջ�е���Сֵ��
* ��ʵ�ֵ�ջ��֧��push��pop �� min ���������в���Ҫ����O(1)ʱ������ɡ�
* ע������
* �����ջ��û���������ܽ���min�����ĵ���
* ����
* ���²�����push(1)��pop()��push(2)��push(3)��min()�� push(1)��min() ���� 1��2��1
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
		//��stack2Ϊ��,ֱ��ѹջ
		//����ȡջ����number�����ֵ,ѹջ
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
		//stack1,stack2ͬʱ��ջ
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
		//ֱ��ȡstack2��ջ��
		if (!stack2.empty())
			return stack2.top();
	}
	stack<int> stack1, stack2;//stack1Ϊ��ջ,stack2Ϊ����ջ�����Сֵ
};
#endif