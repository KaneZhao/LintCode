#ifndef C960_H
#define C960_H
#include<iostream>
#include<set>
#include<queue>
using namespace std;
/*
* First Unique Number in a Stream II
*
* We need to implement a data structure named DataStream. There are two methods required to be implemented:
* void add(number) // add a new number
* int firstUnique() // return first unique number
* ע������
* You can assume that there must be at least one unique number in the stream when calling the firstUnique.
* ����
* add(1)
* add(2)
* firstUnique() => 1
* add(1)
* firstUnique() => 2
*/
class DataStream {
public:

	DataStream(){
		// do intialization if necessary
	}

	/**
	* @param num: next number in stream
	* @return: nothing
	*/
	void add(int num) {
		// write your code here
		//���num���ǵ�һ�γ���,��two�����num
		//����num��Ӳ���dic�����num
		if (dic.find(num) != dic.end())
		{
			two.insert(num);
		}
		else
		{
			que.push(num);
			dic.insert(num);
		}
		//�����ͷԪ�س�����������,����
		while (!que.empty() && two.find(que.front()) != two.end())
		{
			que.pop();
		}		
	}
	/**
	* @return: the first unique number in stream
	*/
	int firstUnique() {
		// write your code here
		return que.front();//ֱ�ӷ��ض�ͷ
	}
	set<int> two, dic;//two�д�����ٳ������ε���,dic�д�����г��ֵ���
	queue<int> que;
};
#endif