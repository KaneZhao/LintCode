#ifndef C920_H
#define C920_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* ������
*
* ����һϵ�еĻ���ʱ������������ʼ�ͽ���ʱ��[[s1,e1]��[s2,e2]����(si < ei)��ȷ��һ�����Ƿ���Բμ����л��顣
* ����
* ��������=[[0,30]��[5,10]��[15,20]]������false��
*/
class Interval{
public:
	int start, end;
	Interval(int start, int end){
		this->start = start;
		this->end = end;
	}
};
bool comp(const Interval &a, const Interval &b)
{
	return a.start < b.start;
}
class Solution {
public:
	/**
	* @param intervals: an array of meeting time intervals
	* @return: if a person could attend all meetings
	*/
	bool canAttendMeetings(vector<Interval> &intervals) {
		// Write your code here
		if (intervals.empty()||intervals.size()==1)
			return true;
		sort(intervals.begin(), intervals.end(), comp);
		int len = intervals.size();
		for (int i = 1; i < len; ++i)
		{
			//����i,��si<ei-1��ʱ��ʱ��������ͻ
			if (intervals[i].start < intervals[i - 1].end)
				return false;
		}
		return true;
	}
};
#endif