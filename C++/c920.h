#ifndef C920_H
#define C920_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
* 会议室
*
* 给定一系列的会议时间间隔，包括起始和结束时间[[s1,e1]，[s2,e2]，…(si < ei)，确定一个人是否可以参加所有会议。
* 样例
* 给定区间=[[0,30]，[5,10]，[15,20]]，返回false。
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
			//对于i,当si<ei-1的时候时间会产生冲突
			if (intervals[i].start < intervals[i - 1].end)
				return false;
		}
		return true;
	}
};
#endif