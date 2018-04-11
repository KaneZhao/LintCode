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
* 注意事项
* You can assume that there must be at least one unique number in the stream when calling the firstUnique.
* 样例
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
		//如果num不是第一次出现,在two中添加num
		//否则将num入队并在dic中添加num
		if (dic.find(num) != dic.end())
		{
			two.insert(num);
		}
		else
		{
			que.push(num);
			dic.insert(num);
		}
		//如果队头元素出现至少两次,出队
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
		return que.front();//直接返回队头
	}
	set<int> two, dic;//two中存放至少出现两次的数,dic中存放所有出现的数
	queue<int> que;
};
#endif