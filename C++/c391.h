#ifndef C391_H
#define C391_H
#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
/*
* ���ɻ�
*
* �����ɻ�����ɺͽ���ʱ����б��� interval ���б�ʾ. ����������ͬʱ����ж��ټܷɻ���
* ע������
* �����ܷɻ�����������ͬһʱ�̣�������Ϊ����������Ȩ��
* ����
* ����ÿ�ܷɻ�����ʱ���б�[[1,10],[2,3],[5,8],[4,7]], ����3��
*/
class Interval{
public:
	int start, end;
	Interval(int start, int end)
	{
		this->start = start;
		this->end = end;
	}
};
class Solution {
public:
	/**
	* @param airplanes: An interval array
	* @return: Count of airplanes are in the sky.
	*/
	int countOfAirplanes(vector<Interval> &airplanes) {
		// write your code here
		if (airplanes.empty())
			return 0;
		int temp = 0;
		int num = 0;
		map<int, int> m;//���ʱ���ͽ����ǵ�ǰʱ��������ϵķɻ���
		set<int> set;
		for (auto c : airplanes)
		{
			m[c.start]++;//start��ʾ�ɻ�����,��Ŀ��һ
			m[c.end]--;//end��ʾ����,��Ŀ��һ
			set.insert(c.start);//���𽵵�ʱ��㶼���뵽set��
			set.insert(c.end);
		}
		//����set,ȡ�����ɻ���
		for (auto c : set)
		{
			temp += m[c];
			if (temp < 0)
				temp = 0;
			if (num < temp)
				num = temp;
		}
		return num;
	}
};
#endif