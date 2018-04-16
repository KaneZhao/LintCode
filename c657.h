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
* ���һ�����ݽṹʵ����ƽ�� O(1) �ĸ��Ӷ���ִ���������еĲ�����
* insert(val): ������Ԫ�ز���set�У�����롣
* remove(val): ������Ԫ����set�У����set���Ƴ���
* getRandom: �����set�з���һ��Ԫ�ء�ÿһ��Ԫ�ط��صĿ����Ա�����ͬ��
* ����
* // ��ʼ���ռ�set
* RandomizedSet randomSet = new RandomizedSet();
* // 1����set�С�������ȷ��Ϊ1���ɹ�����
* randomSet.insert(1);
* // ���ش�����Ϊ2����set��
* randomSet.remove(2);
* // 2����set�У�������ȷ��set������[1,2]��
* randomSet.insert(2);
* // getRandom Ӧ������ķ���1��2��
* randomSet.getRandom();
* // ��set���Ƴ�1��������ȷ��set������[2]��
* randomSet.remove(1);
* // 2�Ѿ���set�У����ش���
* randomSet.insert(2);
* // ��Ϊ2��set��Ψһ�����֣�����getRandom���Ƿ���2��
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
	//m��û��val,vβ������val,����val��λ�ô���m[val]
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
	//m�д���val,����m[val]��ȡ��v�е��±�,����v[m[val]]��v���һ��Ԫ�ؽ���,��������Ԫ��ɾ��
	//���ɾ��m[val]
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