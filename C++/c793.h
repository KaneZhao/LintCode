#ifndef C793_H
#define C793_H
#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
* Intersection of Arrays
*
* ����������飬�����ǵĽ�����������ǽ����Ĵ�С��
* ע������
* �������������Ԫ������������500000��
* ��Ŀ����ÿ���������Ԫ��û���ظ���
* ����
* ���� [[1,2,3],[3,4,5],[3,9,10]]������ 1��
* ���ͣ�
* ֻ��Ԫ��3�����е������г��ֹ�������Ϊ[3]����СΪ1��
* ���� [[1,2,3,4],[1,2,5,6,7],[9,10,1,5,2,3]]������2��
* ���ͣ�
* ֻ��Ԫ��1,2�������е�������ֹ�������Ϊ[1,2]����СΪ2��
*/
class Solution {
public:
	/**
	* @param arrs: the arrays
	* @return: the number of the intersection of the arrays
	*/
	int intersectionOfArrays(vector<vector<int>> &arrs) {
		// write your code here
		if (arrs.empty()||arrs[0].empty())
			return 0;
		int size = arrs.size();
		if (size == 1)
			return arrs[0].size();
		set<int> set1,set2;
		for (auto c : arrs[0])
			set1.insert(c);
		for (int i = 1; i < size; ++i)
		{
			set2.clear();
			for (auto t : arrs[i])
			{
				if (set1.find(t) != set1.end())
					set2.insert(t);
			}
			set1 = set2;
		}
		return set1.size();
	}
};
#endif