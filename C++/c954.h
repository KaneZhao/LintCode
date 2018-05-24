#ifndef C954_H
#define C954_H
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stdlib.h>
#include<algorithm>
using namespace std;
/*
* Insert Delete GetRandom O(1) - Duplicates allowed
*
* Design a data structure that supports all following operations in average O(1) time.
* 注意事项
* Duplicate elements are allowed.
* 1. insert(val): Inserts an item val to the collection.
* 2. remove(val): Removes an item val from the collection if present.
* 3. getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
*/
class RandomizedCollection {
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		// write your code here
		//将元素添加到v的尾部
		//m[val]中添加其位置
		bool res = m.find(val) == m.end();
		v.push_back(val);
		m[val].push(v.size() - 1);
		return res;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		// write your code here
		if (m.find(val) == m.end())
			return false;
		//当要去除的值val不在v的尾部,将val所在的最大位置用来存放v的尾部
		//删除在m中v.back()的最大位置.将v.back()的新位置添加到m[v.back()]
		//删除在m中val的最大位置,删除v的最后一个元素
		if (val != v.back())
		{
			v[m[val].top()] = v.back();
			m[v.back()].pop();
			m[v.back()].push(m[val].top());
		}
		m[val].pop();
		v.pop_back();
		return true;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		// write your code here
		//利用rand()返回v中任意位置上的元素
		if (v.empty())
			return 0;
		return v[rand() % v.size()];
	}
	unordered_map<int, priority_queue<int>> m;//存放元素的值和在v中的位置(从大到小)
	vector<int> v;//为保证getRandom()得到的结果可能性相同,将元素存入vector中
};

/**
* Your RandomizedCollection object will be instantiated and called as such:
* RandomizedCollection obj = new RandomizedCollection();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/
#endif