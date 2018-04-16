#ifndef C657_H
#define C657_H
#include<iostream>
#include<map>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
/*
* Insert Delete GetRandom O(1)
*
* 设计一个数据结构实现在平均 O(1) 的复杂度下执行以下所有的操作。
* insert(val): 如果这个元素不在set中，则插入。
* remove(val): 如果这个元素在set中，则从set中移除。
* getRandom: 随机从set中返回一个元素。每一个元素返回的可能性必须相同。
* 样例
* // 初始化空集set
* RandomizedSet randomSet = new RandomizedSet();
* // 1插入set中。返回正确因为1被成功插入
* randomSet.insert(1);
* // 返回错误因为2不在set中
* randomSet.remove(2);
* // 2插入set中，返回正确，set现在有[1,2]。
* randomSet.insert(2);
* // getRandom 应该随机的返回1或2。
* randomSet.getRandom();
* // 从set中移除1，返回正确。set现在有[2]。
* randomSet.remove(1);
* // 2已经在set中，返回错误。
* randomSet.insert(2);
* // 因为2是set中唯一的数字，所以getRandom总是返回2。
* randomSet.getRandom();
*/
class RandomizedSet {
public:
	RandomizedSet() {
		// do intialization if necessary
	}

	/*
	* @param val: a value to the set
	* @return: true if the set did not already contain the specified element or false
	*/
	//m中没有val,v尾部插入val,并把val的位置存入m[val]
	bool insert(int val) {
		// write your code here
		if (m.find(val) == m.end())
		{
			v.push_back(val);
			m[val] = v.size() - 1;
			return true;
		}
		else
			return false;
	}

	/*
	* @param val: a value from the set
	* @return: true if the set contained the specified element or false
	*/
	//m中存在val,利用m[val]获取在v中的下标,并将v[m[val]]和v最后一个元素交换,并将最后的元素删除
	//最后删除m[val]
	bool remove(int val) {
		// write your code here
		if (m.find(val) != m.end())
		{
			swap(v[m[val]], v[v.size() - 1]);
			v.pop_back();
			m.erase(m.find(val));
			return true;
		}
		else
			return false;
	}

	/*
	* @return: Get a random element from the set
	*/
	int getRandom() {
		// write your code here
		if (v.empty())
			return 0;
		int num = rand() % v.size();
		return v[num];
	}
	map<int, int> m;
	vector<int> v;
};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet obj = new RandomizedSet();
* bool param = obj.insert(val);
* bool param = obj.remove(val);
* int param = obj.getRandom();
*/
#endif