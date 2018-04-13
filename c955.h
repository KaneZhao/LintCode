#ifndef C955_H
#define C955_H
#include<iostream>
#include<vector>
using namespace std;
/*
* Implement Queue by Circular Array
*
* Implement queue by circulant array. You need to support the following methods:
* 1. CircularQueue(n): initialize a circular array with size n to store elements
* 2. boolean isFull(): return true if the array is full
* 3. boolean isEmpty(): return true if there is no element in the array
* 4. void enqueue(element): add an element to the queue
* 5. int dequeue(): pop an element from the queue
* 注意事项
* it's guaranteed in the test cases we won't call enqueue if it's full and we also won't call dequeue if it's empty. So it's ok to raise exception in scenarios described above.
* 样例
* CircularQueue(5)
* isFull()   => false
* isEmpty() => true
* enqueue(1)
* dequeue()  => 1
*/
class CircularQueue {
public:
	/**
	* @return:  return true if the array is full
	*/
	CircularQueue(int n) {
		// do intialization if necessary
		v = vector<int>(N);
		size = n;
	}
	bool isFull() {
		// write your code here
		return (rear - front + N) % N == size;
	}

	/**
	* @return: return true if there is no element in the array
	*/
	bool isEmpty() {
		// write your code here
		return front == rear;
	}

	/**
	* @param element: the element given to be added
	* @return: nothing
	*/
	void enqueue(int element) {
		// write your code here
		v[rear++] = element;
		if (rear == N)
			rear = 0;
	}

	/**
	* @return: pop an element from the queue
	*/
	int dequeue() {
		// write your code here
		int val = v[front];
		front++;
		if (front == N)
			front = 0;
		return val;
	}
	vector<int> v;//表示循环数组
	int front = 0, rear = 0;//front,rear分别表示头部和尾部
	int N = 1000;//循环数组初始大小
	int size;//存放队列大小
};
#endif