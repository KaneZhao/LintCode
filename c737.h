#ifndef C737_H
#define C737_H
#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
* Find Elements in Matrix
* Given a matrix, find a element that appear in all the rows in the matrix.You can assume that there is only one such element.
*
* ����
* For example:
* Given a matrix:
* [
*   [2,5,3],
*   [3,2,1],
*   [1,3,5]
* ]
* return 3
*/
class Solution {
public:
	/**
	* @param Matrix: the input
	* @return: the element which appears every row
	*/
	int FindElements(vector<vector<int>> &Matrix) {
		// write your code here
		vector<set<int>> v;
		set<int> set;
		for (int i = 0; i < Matrix.size(); ++i)
		{
			set.clear();
			for (auto c : Matrix[i])
			{
				set.insert(c);
			}
			v.push_back(set);
		}
		vector<int> tmp;
		vector<int> res;
		for (auto it = Matrix[0].begin(); it != Matrix[0].end(); ++it)
		{
			tmp.push_back(*it);//ȡ����һ������
		}
		for (int i = 1; i < v.size(); ++i)
		{
			for (auto c : tmp)
			{
				if (v[i].find(c) != v[i].end())
					res.push_back(c);//��������ʣ�������Ԫ�ش����µ�����
			}
			tmp = res;//����tmp��ֵ,׼�������µ��ж�
			res.clear();
		}
		return tmp[0];
	}
};
#endif