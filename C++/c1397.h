#ifndef C1397_H
#define C1397_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
/*
* ��������
*
* ����
* ����һЩ���䣬�ʸ��Ǵ����������Ƕ��٣�����ж���������С���Ǹ�����
* ����ĸ���������10^5��
* ��������Ҷ˵����0С�ڵ���10^5��
* ����
* ���� intervals = [(1,7),(2,8)], ���� 2��
* ���ͣ�
* 2��������2�Σ����Ǹ���2������С������
* ���� intervals = [(1,3),(2,3),(3,4)], ���� 3��
* ���ͣ�
* 3��������3�Ρ�
*/
class Interval{
public:
	int start, end;
	Interval(int start, int end){
		this->start = start;
		this->end = end;
	}
};
class Solution {
public:
	/**
	* @param intervals: The intervals
	* @return: The answer
	*/
	int digitalCoverage(vector<Interval> &intervals) {
		// Write your code here
		if (intervals.empty())
			return 0;
		map<int, int> m;//���Ԫ�غ͵�ǰ���ϵĸ���
		set<int> nums;
		int num = 0;
		int temp = 0;
		int cnt = 0;
		for (auto c : intervals)
		{
			++m[c.start];
			--m[c.end + 1];//����end������,end+1û�б�����,Ҫ�����ֵ��end+1
			nums.insert(c.start);
			nums.insert(c.end + 1);
		}
		//�ҵ���󸲸Ǵ�����Ӧ��Ԫ��
		for (auto c : nums)
		{
			temp += m[c];
			if (temp < 0)
				temp = 0;
			if (temp>cnt)
			{
				cnt = temp;
				num = c;
			}
		}
		return num;
	}
	
};
#endif